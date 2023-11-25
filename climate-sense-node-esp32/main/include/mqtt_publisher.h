/**
 * @file mqtt_publisher.h
 * @brief Header file for the MQTT publisher functions.
 *
 * This file contains the function declarations for interacting with the MQTT publisher.
 * It includes functions for starting the MQTT application.
 *
 * Copyright (c) 2023 Charles Dias
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __MQTT_PUBLISHER_H__
#define __MQTT_PUBLISHER_H__

#ifdef __cplusplus 
extern "C" {
#endif

/**
 * @brief Starts the MQTT application.
 *
 * This function initializes and starts the MQTT application.
 * It sets up the MQTT client and connects to the MQTT broker.
 */
void mqtt_app_start(void);

#ifdef __cplusplus 
}
#endif

#endif /* __MQTT_PUBLISHER_H__ */