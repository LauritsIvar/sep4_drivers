#ifdef WINDOWS_TEST
#include "mock_avr_io.h"
#else
#include <avr/io.h>
#include <util/delay.h>
#endif


#include <stdint.h>
void buzzer_beep(){

    //Save the state of the 2 registers
    uint8_t DDRE_state = DDRE;
    uint8_t PORTE_state = PORTE;


    DDRE |= (1<<PE5); //init to be an output
    PORTE&=~(1<<PE5); //Turn On (Active low)
    _delay_ms(5);
    PORTE|=(1<<PE5); //Turn Off (Active low)

    // Restore the previous state. 
    DDRE = DDRE_state;
    PORTE = PORTE_state;

}