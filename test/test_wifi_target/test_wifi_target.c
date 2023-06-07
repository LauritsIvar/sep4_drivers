
#include "unity.h"
#include "wifi.h"
#include <util/delay.h>
#include <avr/io.h>

void setUp(void)
{
    wifi_init();
}

void tearDown(void)
{
}

void test_wifi_AT()
{

    TEST_ASSERT_EQUAL(WIFI_OK, wifi_command_AT());
}

void test_wifi_Connect_to_accessPoint_wrong_password()
{

    TEST_ASSERT_EQUAL(WIFI_FAIL, wifi_command_join_AP("Den gamle daarlige router", "vildfredd"));
}
void test_wifi_disable_echo()
{

    TEST_ASSERT_EQUAL(WIFI_OK, wifi_command_disable_echo());
}

void test_wifi_connect_to_AP_wrong_ssid()
{
    TEST_ASSERT_EQUAL(WIFI_FAIL, wifi_command_join_AP("Den gamle daarlige routerr", "vildfred"));
}

void test_wifi_connect_to_AP_with_correct_ssid_and_password()
{
    TEST_ASSERT_EQUAL(WIFI_OK, wifi_command_join_AP("Den gamle daarlige router", "vildfred"));
}

void test_wifi_set_to_mode_1()
{
    TEST_ASSERT_EQUAL(WIFI_OK, wifi_command_set_mode_to_1());
}
void test_wifi_set_to_single_connection()
{
    TEST_ASSERT_EQUAL(WIFI_OK, wifi_command_set_to_single_Connection());
}

char received_buffer[128];
void receive()
{
    // uart_send_string_blocking(USART_0, received_buffer);
}
void test_wifi_create_TCP_connection()
{

    TEST_ASSERT_EQUAL(WIFI_OK, wifi_command_create_TCP_connection("10.0.0.42", 23, receive, received_buffer));
    TEST_ASSERT_EQUAL(WIFI_OK, wifi_command_TCP_transmit("1234567890", 4));
}

void test_wifi_send_stuff()
{

    TEST_ASSERT_EQUAL(WIFI_OK, wifi_command_TCP_transmit("1234567890", 4));
}

void test_wifi_receive_stuff()
{
    received_buffer[4] = '\0';
    _delay_ms(500);

    TEST_ASSERT_EQUAL_STRING("1234", received_buffer);
}

int main(void)
{
    UNITY_BEGIN();
    _delay_ms(4000);
    RUN_TEST(test_wifi_AT);
    RUN_TEST(test_wifi_set_to_mode_1);
    RUN_TEST(test_wifi_set_to_single_connection);
    RUN_TEST(test_wifi_connect_to_AP_with_correct_ssid_and_password);

    RUN_TEST(test_wifi_create_TCP_connection);

    RUN_TEST(test_wifi_send_stuff);
    RUN_TEST(test_wifi_receive_stuff);

    return UNITY_END();
}