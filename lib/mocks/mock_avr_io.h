#include <inttypes.h>

void cli(void);
void sei(void );
#define PB7 7
#define F_CPU 16000000L
#define TXEN0 3
#define RXEN0 4
#define RXCIE0 7

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
uint8_t UCSR0C;

#define UCSZ10 1
#define UCSZ11 2
uint8_t UCSR1C;

#define UCSZ20 1
#define UCSZ21 2
uint8_t UCSR2C;

#define UCSZ30 1
#define UCSZ31 2

uint8_t UCSR3C;

uint8_t UCSR1B; 
#define UDRIE1 5
uint8_t UCSR2B; 
#define UDRIE2 5
uint8_t UCSR3B; 
#define UDRIE3 5
uint8_t UCSR0B; 
#define UDRIE0 5
uint8_t UCSR0A;
uint8_t UCSR1A;
uint8_t UCSR2A;
uint8_t UCSR3A;

#define UDRE0 5
#define UDRE1 5
#define UDRE2 5
#define UDRE3 5
void _delay_ms(int a);
uint8_t DDRB;
uint8_t PORTB;

uint8_t UDR0;
uint8_t UCSR0B;
uint8_t UBRR0H;
uint8_t UBRR0L;

uint8_t UDR1;
uint8_t UCSR1B;
uint8_t UBRR1H;
uint8_t UBRR1L;

uint8_t UDR2;
uint8_t UCSR2B;
uint8_t UBRR2H;
uint8_t UBRR2L;

uint8_t UDR3;
uint8_t UCSR3B;
uint8_t UBRR3H;
uint8_t UBRR3L;
