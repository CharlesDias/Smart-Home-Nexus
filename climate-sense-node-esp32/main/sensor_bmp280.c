#include "sensor_bmp280.h"
#include "utils.h"

#include "esp_random.h"

void read_sensor_data(double *temperature, double *pressure, double *humidity)
{
    // Generate random sensor values
    *temperature = 20.0 + ((esp_random() % 210) / 10.0); // Random between 20.0 and 40.0
    *pressure = 900.0 + ((esp_random() % 1010) / 10.0); // Random between 900.0 and 1000.0
    *humidity = 70.0 + ((esp_random() % 310) / 10.0); // Random between 70.0 and 100.0
}