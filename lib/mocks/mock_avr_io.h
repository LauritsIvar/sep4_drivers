#pragma once
#include <inttypes.h>

void cli(void);
void sei(void );
#define PB7 7
#define F_CPU 16000000L
#define TXEN0 3
#define RXEN0 4
#define RXCIE0 7

#define DDA6 6
#define DDA4 4
#define DDC7 7
#define DDC1 1
#define PG1 1

#define PD7 7

#define TXEN1 3
#define RXEN1 4
#define RXCIE1 7

#define TXEN2 3
#define RXEN2 4

#define RXCIE2 7

#define TXEN3 3
#define RXEN3 4
#define RXCIE3 7

#define UCSZ00 1
#define UCSZ01 2
extern uint8_t UCSR0C;

#define UCSZ10 1
#define UCSZ11 2
extern uint8_t UCSR1C;

#define UCSZ20 1
#define UCSZ21 2
extern uint8_t UCSR2C;

#define UCSZ30 1
#define UCSZ31 2
#define PD1 1

extern uint8_t UCSR3C;

extern uint8_t UCSR1B; 
#define UDRIE1 5
extern uint8_t UCSR2B; 
#define UDRIE2 5
extern uint8_t UCSR3B; 
#define UDRIE3 5
extern uint8_t UCSR0B; 
#define UDRIE0 5
extern uint8_t UCSR0A;
extern uint8_t UCSR1A;
extern uint8_t UCSR2A;
extern uint8_t UCSR3A;

#define UDRE0 5
#define UDRE1 5
#define UDRE2 5
#define UDRE3 5
void _delay_ms(int a);
void _delay_us(int a);
extern uint8_t DDRB;
extern uint8_t PORTB;

extern uint8_t UDR0;
extern uint8_t UCSR0B;
extern uint8_t UBRR0H;
extern uint8_t UBRR0L;

extern uint8_t UDR1;
extern uint8_t UCSR1B;
extern uint8_t UBRR1H;
extern uint8_t UBRR1L;

extern uint8_t UDR2;
extern uint8_t UCSR2B;
extern uint8_t UBRR2H;
extern uint8_t UBRR2L;

extern uint8_t UDR3;
extern uint8_t UCSR3B;
extern uint8_t UBRR3H;
extern uint8_t UBRR3L;

extern uint8_t DDRA;
extern uint8_t DDRC;

extern uint8_t PORTC;
extern uint8_t PORTA;

extern uint8_t DDRG;
extern uint8_t PORTG;


extern uint8_t DDRD;
extern uint8_t PORTD;
extern uint8_t PIND;
extern uint8_t PINC;

extern uint8_t DDRF;
extern uint8_t PORTF;
extern uint8_t PINF;

#define PF1 1
#define PF2 2
#define PF3 3
#define PD0 0
#define PD1 1
#define PD2 2

extern uint8_t DDRE;
extern uint8_t PORTE;

#define PE5 5
#define PG5 5
#define PH5 5
#define PH4 4

extern uint8_t DDRH;
extern uint8_t TCCR1B;
extern uint8_t OCR1A;
extern uint8_t TIMSK1;
extern uint8_t PORTH;

#define WGM12 3
#define CS11 1
#define OCIE1A 1

extern uint8_t DDRK;
extern uint8_t PORTK;
extern uint8_t TCNT1;
extern uint8_t PINK;

#define PK6 6
#define PK5 5
#define PK7 7
#define PK4 4

#define CS12 2

#define PB6 6
#define PB5 5
#define PB4 4

 extern uint8_t ADMUX;
 extern  uint8_t ADCSRA;
 extern  uint8_t ADCSRB;
extern  uint8_t ADCL;
 extern  uint8_t ADCH;
extern uint8_t DIDR2;
#define REFS0 6
#define ADEN 7
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0
#define MUX5 3
#define ADC9D 1
#define ADC8D 0
#define PK1 1
#define PK2 2
#define ADSC 6
