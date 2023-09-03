#include "includes.h"
#include "pc_comm.h"
#include "dht11.h"
#include "display.h"
#include "leds.h"
#include "light.h"
#include "buzzer.h"
#include "buttons.h"


int main(void)
{
  pc_comm_init(115200, NULL);
    uint8_t h1, h2, t1, t2;
    char str[128];
    int16_t light;
    display_init();
    leds_init();
    light_init();
    buttons_init();
    

    while (1)
    {
     if (buttons_1_pressed())
      leds_turnOn(1);
     else
      leds_turnOff(1);

           if (buttons_2_pressed())
      leds_turnOn(2);
     else
      leds_turnOff(2);

           if (buttons_3_pressed())
      leds_turnOn(3);
     else
      leds_turnOff(3);
     
     
     


      
   
} 
return 0;}
