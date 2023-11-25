#include "mqtt_publisher.h"
#include "sensor_bmp280.h"
#include "utils.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "mqtt_client.h"
#include "cJSON.h"

bool connected = false;

static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data);
static void publish_sensor_data(void *pvParameters);

void mqtt_app_start(void)
{
    esp_mqtt_client_config_t mqtt_cfg = {
        .broker.address.uri = CONFIG_BROKER_URL,
    };

    esp_mqtt_client_handle_t client = esp_mqtt_client_init(&mqtt_cfg);

    esp_mqtt_client_register_event(client, ESP_EVENT_ANY_ID, mqtt_event_handler, NULL);
    esp_mqtt_client_start(client);

    // Create a task for publishing data
    xTaskCreate(publish_sensor_data, "publish_sensor_data", 4096, client, 5, NULL);
}

/**
 * @brief Handles MQTT events.
 *
 * This function is a callback for the MQTT event loop. It handles various MQTT events such as
 * connection, disconnection, subscription, etc.
 *
 * @param handler_args Arguments for the handler.
 * @param base Event base.
 * @param event_id The ID of the event.
 * @param event_data Data associated with the event.
 */
static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data)
{
    ESP_LOGD(TAG, "Event dispatched from event loop base=%s, event_id=%" PRIi32 "", base, event_id);
    esp_mqtt_event_handle_t event = event_data;

    switch ((esp_mqtt_event_id_t)event_id)
    {
    case MQTT_EVENT_CONNECTED:
        ESP_LOGI(TAG, "MQTT_EVENT_CONNECTED");
        connected = true;
        break;
    case MQTT_EVENT_DISCONNECTED:
        ESP_LOGI(TAG, "MQTT_EVENT_DISCONNECTED");
        connected = false;
        break;
    case MQTT_EVENT_PUBLISHED:
        ESP_LOGI(TAG, "MQTT_EVENT_PUBLISHED, msg_id=%d", event->msg_id);
        break;
    case MQTT_EVENT_ERROR:
        ESP_LOGI(TAG, "MQTT_EVENT_ERROR");
        if (event->error_handle->error_type == MQTT_ERROR_TYPE_TCP_TRANSPORT)
        {
            log_error_if_nonzero("reported from esp-tls", event->error_handle->esp_tls_last_esp_err);
            log_error_if_nonzero("reported from tls stack", event->error_handle->esp_tls_stack_err);
            log_error_if_nonzero("captured as transport's socket errno", event->error_handle->esp_transport_sock_errno);
            ESP_LOGI(TAG, "Last errno string (%s)", strerror(event->error_handle->esp_transport_sock_errno));
        }
        break;
    default:
        ESP_LOGI(TAG, "Other event id:%d", event->event_id);
        break;
    }
}

/**
 * @brief Publishes sensor data.
 *
 * This function retrieves sensor data and publishes it to a specified topic.
 * It is intended to be run as a separate task, hence the void pointer parameter.
 *
 * @param pvParameters Parameters for the task (unused).
 */
static void publish_sensor_data(void *pvParameters)
{
    // Cast the void pointer back to the appropriate type
    esp_mqtt_client_handle_t client = (esp_mqtt_client_handle_t)pvParameters;
    double temperature, pressure, humidity;

    while (1)
    {
        if (connected)
        {
            read_sensor_data(&temperature, &pressure, &humidity);

            // Create a cJSON object
            cJSON *sensor_data = cJSON_CreateObject();
            cJSON_AddNumberToObject(sensor_data, "t", temperature);
            cJSON_AddNumberToObject(sensor_data, "p", pressure);
            cJSON_AddNumberToObject(sensor_data, "h", humidity);

            // Convert cJSON object to string
            char *sensor_data_string = cJSON_Print(sensor_data);

            // Publish the sensor data
            int msg_id = esp_mqtt_client_publish(client, "/home/sensors", sensor_data_string, 0, 2, 0);
            ESP_LOGI("MQTT", "sent publish successful, msg_id=%d", msg_id);

            // Free the cJSON object
            cJSON_Delete(sensor_data);
            free(sensor_data_string);
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}