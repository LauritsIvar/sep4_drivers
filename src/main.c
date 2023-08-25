#include "led_hal.h"
#include "pc_comm.h"
#include <util/delay.h>
#include <stdio.h>

#include "wifi.h"
#include "humidity.h"

int main()
{
  pc_comm_init(9600, NULL);

  uint8_t humidity_int, humidity_dec, temperature_int, temperature_dec;
  char str[64];
  _delay_ms(2000);

  while (1)
  {
    _delay_ms(2000);
    
    if (HUMIDITY_OK==  humidity_get(&humidity_int, &humidity_dec, &temperature_int, &temperature_dec)){
      pc_comm_send_string_blocking("Error in reading \n");
    }
    else{
    sprintf(str, "humidity = %d.%d  \n temperature = %d.%d\n\n", humidity_int, humidity_dec, temperature_int, temperature_dec);
    pc_comm_send_string_blocking(str);

    }


  }
}