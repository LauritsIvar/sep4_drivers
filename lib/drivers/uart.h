#pragma once
#include <stdint.h>


typedef enum {
    USART_0,
    USART_1,
    USART_2,
    USART_3
} USART_t;




typedef void (*UART_Callback_t)(uint8_t);



void uart_init(USART_t usart, uint32_t baudrate, UART_Callback_t callback);

void uart_send_blocking(USART_t usart,uint8_t data);

void uart_send_array_nonBlocking(USART_t usart,  uint8_t *str, uint16_t len);

void uart_send_array_blocking(USART_t usart, uint8_t *data, uint16_t length);

void uart_send_string_blocking(USART_t usart, char *data);

UART_Callback_t uart_get_rx_callback(USART_t usart);