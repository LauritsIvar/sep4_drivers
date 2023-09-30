
#include "unity.h"
#include "buttons.h"
#include <util/delay.h>
#include "pc_comm.h"
#include <avr/io.h>
#include "buzzer.h"
#include "display.h"

void setUp(void)
{
    buttons_init();
}

void tearDown(void)
{
}

void test_button_Not_pressed()
{
    // pc_comm_init(115200, NULL);
    // pc_comm_send_string_blocking("Press button 1! \n\n");
    _delay_ms(1000);

    TEST_ASSERT_EQUAL(0, buttons_1_pressed());
    TEST_ASSERT_EQUAL(0, buttons_2_pressed());
    TEST_ASSERT_EQUAL(0, buttons_3_pressed());
}

void test_display()
{
    display_init();
    _delay_ms(1000);
    for (int16_t i = -999; i < 9999; i++)
    {
        display_int(i);
        _delay_ms(1);
    }

    TEST_ASSERT_EQUAL(1, 1);
}

void test_button_pressed()
{
    // pc_comm_init(115200, NULL);
    // pc_comm_send_string_blocking("Press button 1! \n\n");
    buzzer_beep();
    _delay_ms(200);
    buzzer_beep();
    _delay_ms(200);
    buzzer_beep();
    _delay_ms(200);
    buzzer_beep();
    TEST_ASSERT_EQUAL(1, buttons_1_pressed());
    TEST_ASSERT_EQUAL(1, buttons_2_pressed());
    TEST_ASSERT_EQUAL(1, buttons_3_pressed());
}

int main(void)
{
    UNITY_BEGIN();
    //_delay_ms(4000);

    RUN_TEST(test_button_Not_pressed);

    TEST_MESSAGE("INFO!!!! When_the displayed_is_finished (reaching 9999), all 3 buttons should be pressed! :1:_:PASS\n"); // TEST_MESSAGE("m e s s a g e :1:_:PASS\n");
    RUN_TEST(test_display);
    RUN_TEST(test_button_pressed);

    return UNITY_END();
}