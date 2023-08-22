#include "led_hal.h"
#include "uart.h"
#include <util/delay.h>
#include <stdio.h>
#include "wifi.h"


char received_buffer[128];
void receive(){
    uart_send_string_blocking(USART_0, received_buffer);
}

int main(){

  led_hal_init();
  uart_init(USART_0, 115200, NULL);
  wifi_init();
  wifi_command_disable_echo();
  wifi_command_set_mode_to_1();
  wifi_command_set_to_single_Connection();
  wifi_command_join_AP("Den gamle daarlige router","vildfred");
  wifi_command_create_TCP_connection("10.0.0.42", 23, receive, received_buffer);
  
uint16_t i;
  while (1)
  {
     
i++;
wifi_command_TCP_transmit(&i,2);
_delay_ms(1000);

    
  }
  


}