#include <avr/io.h>
#include <avr/delay.h>
#include <stdint.h>

void buttons_init(){
    DDRF&=~((1<<PF1) | (1<<PF2) | (1<<PF3)) ; // Make them 3 buttons to be input. 
    PORTF|=((1<<PF1) | (1<<PF2) | (1<<PF3)) ; // enable the pullup resistor. 
}

uint8_t buttons_1_pressed(){
    if (!(PINF & (1 << PF1))) return 1;
    else return 0;
}

uint8_t buttons_2_pressed(){
    
    if (!(PINF & (1 << PF2))) return 1;
    else return 0;
}

uint8_t buttons_3_pressed(){
    if (!(PINF & (1 << PF2))) return 1;
    else return 0;
}

