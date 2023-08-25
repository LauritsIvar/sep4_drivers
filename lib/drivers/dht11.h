#pragma once

#include <stdint.h>

typedef enum{
    DHT11_OK,                         /**< Command successful. */
    DHT11_FAIL,                       /**< General failure or operation not successful. */
} DHT11_ERROR_MESSAGE_t;


/**
 * @brief Get humidity reading from DHT11 sensor
 * 
 * @param humidity A pointer to store the humidity value
 * @return int 0 if successful, -1 otherwise
 */
DHT11_ERROR_MESSAGE_t dht11_get(uint8_t* humidity_integer, uint8_t*  humidity_decimal, uint8_t* temperature_integer, uint8_t* temperature_decimal);

