/**
 * @file utils.h
 * @brief This file contains utility functions for the application.
 *
 * This file includes function declarations that provide utility services
 * to the rest of the application. These might include string manipulation,
 * error handling, etc.
 * 
 * Copyright (c) 2023 Charles Dias
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __UTILS_H__
#define __UTILS_H__

#ifdef __cplusplus 
extern "C" {
#endif

#include "esp_log.h"

/**
 * @var const char *TAG
 * @brief A tag used for logging.
 */
extern const char *TAG;

/**
 * @brief Logs an error message if the error code is non-zero.
 *
 * @param message The error message to log.
 * @param error_code The error code. If non-zero, the error message is logged.
 */
void log_error_if_nonzero(const char *message, int error_code);

#ifdef __cplusplus 
}
#endif

#endif /* __UTILS_H__ */