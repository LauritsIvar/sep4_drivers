#include "includes.h"
#include "pc_comm.h"
#include "dht11.h"
#include "display.h"
#include "leds.h"
#include "light.h"
#include "buzzer.h"
#include "buttons.h"
#include "periodic_task.h"
#include "adxl345.h"
#include "hc_sr04.h"
#include "wifi.h"
#include "avr/power.h"
#include "pir.h"
#include "tone.h"
#include <stdio.h>


void timer2_delay_us(uint32_t delay_us) {
    // Initialize Timer2 in normal mode
    TCCR2A = 0;
    TCCR2B = 0;

    uint8_t prescaler_bits = 0;
    uint16_t prescaler_value = 0;

    // Choose prescaler based on delay
    if (delay_us > 4000) {
        prescaler_bits = (1 << CS22) | (1 << CS21) | (1 << CS20); // 1024
        prescaler_value = 1024;
    } else if (delay_us > 2000) {
        prescaler_bits = (1 << CS22) | (1 << CS21); // 256
        prescaler_value = 256;
    } else if (delay_us > 1000) {
        prescaler_bits = (1 << CS22) | (1 << CS20); // 128
        prescaler_value = 128;
    } else if (delay_us >500) {
        prescaler_bits = (1 << CS22); // 64
        prescaler_value = 64;
    } else if (delay_us >125) {
        prescaler_bits = (1 << CS21)| (1 << CS20); //32
        prescaler_value = 32;
    }
    else
     {
       prescaler_bits = (1 << CS21) ; // 8
        prescaler_value = 8;
     }

    // Set the prescaler
    TCCR2B = prescaler_bits;

    // Calculate the number of timer ticks needed for the specified delay
    uint8_t num_ticks = (F_CPU / 1000000UL) * delay_us / prescaler_value;

    // Reset the timer counter
    TCNT2 = 0;

    // Wait until the timer counter reaches the required ticks
    while (TCNT2 < num_ticks) {
        // Busy-wait
    }

    // Disable Timer2
    TCCR2B = 0;
}



void pir_func(void){
    leds_toggle(1);
}

int main(void) {
leds_init();
//pir_init(pir_func);
display_init();
tone_init();

//tone_play_starwars();
pc_comm_init(9600, NULL);

adxl345_init();
int i=0;
uint8_t temp;
int16_t x,y,z;
char string[128];
while (1)
{
    /*adxl345_read_xyz(&x, &y, &z);
    sprintf(string, "x=%d\ny=%d\nz=%d\n\n",x/834,y/834,z/834);
    pc_comm_send_string_blocking(string);
    display_int(z/834);*/
display_int(i++);
if (i>9998)
{
    i=-990;
}

_delay_ms(10);

    
}


return 0;}
   

