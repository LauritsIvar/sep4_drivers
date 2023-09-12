
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
    //pc_comm_init(115200, NULL);
    //pc_comm_send_string_blocking("Press button 1! \n\n");
    _delay_ms(1000);

    TEST_ASSERT_EQUAL(0, buttons_1_pressed());
    TEST_ASSERT_EQUAL(0, buttons_2_pressed());
    TEST_ASSERT_EQUAL(0, buttons_3_pressed());
}

void prompt_user_to_click_on_buttons(){
        TEST_ASSERT_MESSAGE(1, "Click on all 3 buttons! \n");
    

}

void test_button_pressed()
{
    //pc_comm_init(115200, NULL);
    //pc_comm_send_string_blocking("Press button 1! \n\n");
    buzzer_beep();
    _delay_ms(200);
        buzzer_beep();
    _delay_ms(200);
        buzzer_beep();
    _delay_ms(200);
    buzzer_beep();
    _delay_ms(2000);

    TEST_ASSERT_EQUAL(1, buttons_1_pressed());
    TEST_ASSERT_EQUAL(1, buttons_2_pressed());
    TEST_ASSERT_EQUAL(1, buttons_3_pressed());
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




int main(void)
{
    UNITY_BEGIN();
    //_delay_ms(4000);

    RUN_TEST(test_button_Not_pressed);
RUN_TEST(prompt_user_to_click_on_buttons);
    RUN_TEST(test_button_pressed);

        RUN_TEST(test_display);


    return UNITY_END();
}