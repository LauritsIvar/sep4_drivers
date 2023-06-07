#include <stdint.h>

typedef enum{
    WIFI_OK,
    WIFI_FAIL,
    WIFI_ERROR_RECEIVED_ERROR,
    WIFI_ERROR_NOT_RECEIVING,
    WIFI_ERROR_RECEIVING_GARBAGE
} WIFI_ERROR_MESSAGE_t;

typedef void (*WIFI_TCP_Callback_t)();

void wifi_init();

WIFI_ERROR_MESSAGE_t wifi_init_and_varify();



void wifi_transmit(uint8_t * data, uint8_t length);

WIFI_ERROR_MESSAGE_t wifi_command_AT();

WIFI_ERROR_MESSAGE_t wifi_command_join_AP(char * ssid, char * password); // if wrong ssid or password, it will return WIFE_FAIL. 

WIFI_ERROR_MESSAGE_t wifi_command_disable_echo();

WIFI_ERROR_MESSAGE_t wifi_command_set_mode_to_1();

WIFI_ERROR_MESSAGE_t wifi_command_set_to_single_Connection();

WIFI_ERROR_MESSAGE_t wifi_command_create_TCP_connection(char * IP, uint16_t port, WIFI_TCP_Callback_t callback_when_message_received, char * received_message_buffer);

WIFI_ERROR_MESSAGE_t wifi_command_TCP_transmit(uint8_t * data, uint16_t length);

WIFI_ERROR_MESSAGE_t wifi_command_quit_AP();
