
#include "unity.h"

#include <util/delay.h>

#include <avr/io.h>
#include "light.h"


void setUp(void)
{
    light_init();
}

void tearDown(void)
{
}

void test_light_returns_a_value()
{
    TEST_ASSERT_INT16_WITHIN(400,500,light_read());

}


int main(void)
{
    UNITY_BEGIN();
    //_delay_ms(4000);
    RUN_TEST(test_light_returns_a_value);
    return UNITY_END();
}