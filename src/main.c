#include "led_hal.h"
#include "pc_comm.h"
#include <util/delay.h>
#include <stdio.h>
#include "wifi.h"


void receive(char byte){

  pc_comm_send_string_blocking("0");
  pc_comm_send_array_blocking((uint8_t*)&byte, 1);
}


int main(){
  pc_comm_init(9600, receive);
  while (1)
  {
    _delay_ms(1000);
    pc_comm_send_string_blocking("Lets Test This!\n");
    pc_comm_send_array_nonBlocking((uint8_t*)"123456789", 7);
  }
  

}