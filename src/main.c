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



int numbers[]={-999,-888,-1234,0,66,1111,2222,5555,8888,9999};
while (1)
{

while (1)
{
    display_setValues(15,10,16,17);
    _delay_ms(1500);
     display_setValues(0,2,3,4);
         _delay_ms(1500);
     display_setValues(5,6,7,8);
              _delay_ms(1500);
     display_setValues(9,10,11,12);
                   _delay_ms(1500);
     display_setValues(13,14,15,16);
                      _delay_ms(1500);
     display_setValues(17,18,19,20);  

      _delay_ms(1500);
     
}

   
}


    return 0;
}
