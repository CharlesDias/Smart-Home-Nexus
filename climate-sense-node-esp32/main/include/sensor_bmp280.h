/**
 * @file sensor_bmp280.h
 * @brief Header file for the BMP280 sensor functions.
 *
 * This file contains the function declarations for interacting with the BMP280 sensor.
 * It includes functions for initializing the sensor, reading data, and error handling.
 * 
 * Copyright (c) 2023 Charles Dias
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __SENSOR_BMP280_H__
#define __SENSOR_BMP280_H__

#ifdef __cplusplus 
extern "C" {
#endif

/**
 * @brief Reads sensor data from the BMP280 sensor.
 *
 * This function reads temperature, pressure, and humidity data from the BMP280 sensor.
 * The read values are returned via pointer parameters.
 *
 * @param temperature Pointer to a double where the read temperature value will be stored.
 * @param pressure Pointer to a double where the read pressure value will be stored.
 * @param humidity Pointer to a double where the read humidity value will be stored.
 */
void read_sensor_data(double *temperature, double *pressure, double *humidity);

#ifdef __cplusplus 
}
#endif

#endif /* __SENSOR_BMP280_H__ */