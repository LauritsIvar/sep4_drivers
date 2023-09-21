#include "includes.h"
#include "pc_comm.h"
#include "dht11.h"
#include "display.h"
#include "leds.h"
#include "light.h"
#include "buzzer.h"
#include "buttons.h"
#include "periodic_task.h"
#include "ADXL345.h"
#include "hc_sr04.h"
#include "wifi.h"
#include "avr/power.h"
#include "pir.h"
#include "tone.h"


void timer2_delay_us(uint32_t delay_us) {
    // Initialize Timer2 in normal mode
    TCCR2A = 0;
    TCCR2B = 0;

    uint8_t prescaler_bits = 0;
    uint16_t prescaler_value = 0;

    // Choose prescaler based on delay
    if (delay_us > 4000) {
        prescaler_bits = (1 << CS22) | (1 << CS21) | (1 << CS20); // 1024
        prescaler_value = 1024;
    } else if (delay_us > 2000) {
        prescaler_bits = (1 << CS22) | (1 << CS21); // 256
        prescaler_value = 256;
    } else if (delay_us > 1000) {
        prescaler_bits = (1 << CS22) | (1 << CS20); // 128
        prescaler_value = 128;
    } else if (delay_us >500) {
        prescaler_bits = (1 << CS22); // 64
        prescaler_value = 64;
    } else if (delay_us >125) {
        prescaler_bits = (1 << CS21)| (1 << CS20); //32
        prescaler_value = 32;
    }
    else
     {
       prescaler_bits = (1 << CS21) ; // 8
        prescaler_value = 8;
     }

    // Set the prescaler
    TCCR2B = prescaler_bits;

    // Calculate the number of timer ticks needed for the specified delay
    uint8_t num_ticks = (F_CPU / 1000000UL) * delay_us / prescaler_value;

    // Reset the timer counter
    TCNT2 = 0;

    // Wait until the timer counter reaches the required ticks
    while (TCNT2 < num_ticks) {
        // Busy-wait
    }

    // Disable Timer2
    TCCR2B = 0;
}



void pir_func(void){
    leds_toggle(1);
}

int main(void) {
leds_init();
//pir_init(pir_func);
display_init();
tone_init();

tone_play_starwars();
int i=0;
//pa1






    // Play the beginning of the Star Wars theme
/*for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    //tone(buzzer, melody[thisNote], noteDuration*0.9);
    tone_play(melody[thisNote], noteDuration*0.9); 

    // Wait for the specief duration before playing the next note.
    //delay(noteDuration);
    
    // stop the waveform generation before the next note.
    //noTone(buzzer);
  }*/
return 0;}
   

