#pragma once

#include <stdint.h>

typedef enum{
    HUMIDITY_OK,                         /**< Command successful. */
    HUMIDITY_FAIL,                       /**< General failure or operation not successful. */
} HUMIDITY_ERROR_MESSAGE_t;


/**
 * @brief Get humidity reading from DHT11 sensor
 * 
 * @param humidity A pointer to store the humidity value
 * @return int 0 if successful, -1 otherwise
 */
HUMIDITY_ERROR_MESSAGE_t humidity_get(uint8_t* humidity_integer, uint8_t*  humidity_decimal, uint8_t* temperature_integer, uint8_t* temperature_decimal);

