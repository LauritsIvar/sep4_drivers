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
#include "servo.h"


int main(void)
{
    // servo(90);
    //();
    display_init();
    leds_init();
    light_init();


while (1)
{
    display_int(light_read());
_delay_ms(300);
}

   


    return 0;
}
