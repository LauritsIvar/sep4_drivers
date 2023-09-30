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
    DDRE |= (1 << PE3);



int i=0;
uint8_t angle_array[]={0,125,127,128,129,130,180};
while (1)
{

    display_int(angle_array[i]);
    //(angle_array[i]);

   if (i==6)
   {
    i=0;
   }
   i++;
   
}


    return 0;
}
