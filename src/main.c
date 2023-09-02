#include "includes.h"
#include "pc_comm.h"
#include "dht11.h"
#include "display.h"
#include "leds.h"
#include "light.h"
#include "buzzer.h"


int main(void)
{
  pc_comm_init(115200, NULL);
    uint8_t h1, h2, t1, t2;
    char str[128];
    int16_t light;
    display_init();
    leds_init();
    light_init();
    

    while (1)
    {
     light=light_read();
      display_int(light);
      _delay_ms(200);
      sprintf(str,"Light = %d \n", light);
      pc_comm_send_string_blocking(str);


      
   
} 
return 0;}
