
#include "unity.h"

#include <util/delay.h>

#include <avr/io.h>
#include "adxl345.h"
#include <stdint.h>
#include <math.h>
#include "hc_sr04.h"
#include "dht11.h"
#include <stdio.h>
#include "light.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_adxl345_is_g()
{
    adxl345_init();
    _delay_ms(1000);
    int16_t x, y, z;
    adxl345_read_xyz(&x, &y, &z);

    float total_acceleration = sqrtf((float)x * (float)x + (float)y * (float)y + (float)z * (float)z) / 834;
    TEST_ASSERT_FLOAT_WITHIN(2, 9.82, total_acceleration);
    char message[1024];
    sprintf(message, "INFO! adxl345 measurement! x= %dm/s^2, y= %dm/s^2, z= %dm/s^2        :1:_:PASS\n", x / 834, y / 834, z / 834);
    TEST_MESSAGE(message); // TEST_MESSAGE("m e s s a g e :1:_:PASS\n");
}

void test_hc_sr04_is_measoring_between_5cm_and_3m()
{
    hc_sr04_init();
    _delay_ms(500);
    uint16_t distance = hc_sr04_takeMeasurement();

    char message[1024];
    sprintf(message, "INFO! hc_sr04 measurement! Distance %d cm        :1:_:PASS\n", distance / 10);
    TEST_MESSAGE(message); // TEST_MESSAGE("m e s s a g e :1:_:PASS\n");

    TEST_ASSERT_TRUE_MESSAGE(50 < distance && 3000 > distance, message);
}

void test_dht11_status()
{
    dht11_init();
    _delay_ms(2000);
    TEST_ASSERT_EQUAL(DHT11_OK, dht11_get(NULL, NULL, NULL, NULL));
}

void test_temperature_is_22celc()
{

    dht11_init();
    _delay_ms(2000);
    uint8_t celc, celc_dec, hum_int, hum_dec;
    dht11_get(&hum_int, &hum_dec, &celc, &celc_dec);
    TEST_ASSERT_INT_WITHIN(5, 22, celc);//between 17 and 

    char message[1024];
    sprintf(message, "INFO! dht11 measurement! Temperature %d.%d C! Humidity %d.%d%%       :1:_:PASS\n", celc, celc_dec, hum_int, hum_dec);
    TEST_MESSAGE(message); // TEST_MESSAGE("m e s s a g e :1:_:PASS\n"); // no : in the message
}

void test_light_returns_a_value()
{
        light_init();
        _delay_ms(300);
        uint16_t light = light_read();
    TEST_ASSERT_INT16_WITHIN(400,500,light);

    char message[1024];
    sprintf(message, "INFO! photo_resistor measurement= %d       :1:_:PASS\n", light);
    TEST_MESSAGE(message); // TEST_MESSAGE("m e s s a g e :1:_:PASS\n"); // no : in the message

}



int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_adxl345_is_g);
    RUN_TEST(test_hc_sr04_is_measoring_between_5cm_and_3m);
    RUN_TEST(test_dht11_status);
    RUN_TEST(test_temperature_is_22celc);
    RUN_TEST(test_light_returns_a_value);
    return UNITY_END();
}