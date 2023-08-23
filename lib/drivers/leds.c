#include <avr/io.h>

void leds_init(void){

      // LEDS, create driver later
  DDRB |= (1<<PB7)|(1<<PB6)|(1<<PB5)|(1<<PB4); //Output
  PORTB |= (1<<PB7)|(1<<PB6)|(1<<PB5)|(1<<PB4); //turnOff (Active Low)


}

void leds_turnOn(uint8_t led_no){
 switch (led_no)
 {
 case 1:
    PORTB&=~((1<<PB7));
    break;
case 2:
    PORTB&=~((1<<PB6));
    break;
case 3:
    PORTB&=~((1<<PB5));
    break;
case 4:
    PORTB&=~((1<<PB4));
    break;
 }

}

void leds_turnOff(uint8_t led_no){
 switch (led_no)
 {
 case 1:
    PORTB|=((1<<PB7));
    break;
case 2:
    PORTB|=((1<<PB6));
    break;
case 3:
    PORTB|=((1<<PB5));
    break;
case 4:
    PORTB|=((1<<PB4));
    break;
 }

}

void leds_toggle(uint8_t led_no){
 switch (led_no)
 {
 case 1:
    PORTB^=((1<<PB7));
    break;
case 2:
    PORTB^=((1<<PB6));
    break;
case 3:
    PORTB^=((1<<PB5));
    break;
case 4:
    PORTB^=((1<<PB4));
    break;
 }

}