#include "includes.h"
void led_hal_init(void){
    DDRB |= (1<<PB7);
}

void led_hal_turnOn(){
    PORTB |= (1<<PB7);
}

void led_hal_turnOff(){
    PORTB &= ~(1<<PB7);
}

void led_hal_toggle(){
    PORTB ^= (1<<PB7);
}