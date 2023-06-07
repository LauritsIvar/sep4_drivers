#include "unity.h"
#include "led_hal.h"

#ifdef WINDOWS_TEST
    #include "mock_avr_io.h"
#else
    #include <avr/io.h>
#endif

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void test_led_init_set_bit7(void) {
  DDRB=0;
  led_hal_init();
  TEST_ASSERT_EQUAL(0b10000000, DDRB);
}

void test_led_init_only_the_7th_bit_is_set(void) {
  DDRB=0xAA;
  led_hal_init();
  TEST_ASSERT_EQUAL(0xAA| (1<<7), DDRB);
}


void test_led_turnOn(){
    PORTB = 0;
    led_hal_turnOn();

    TEST_ASSERT_EQUAL(0b10000000, PORTB);
}




//test that it can turn on
//it can turn off
//it can turn on




int main(void) {
  UNITY_BEGIN();
  //RUN_TEST(test_led_init_set_bit7);
  //RUN_TEST(test_led_init_only_the_7th_bit_is_set);
  RUN_TEST(test_led_turnOn);
  return UNITY_END();
}