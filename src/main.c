#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include "pc_comm.h"

#define MAX_TIME 85
#define DHT11PIN PE4
#define DHT11PORT PORTE
#define DHT11PINREG PINE
#define DHT11DDR DDRE

int dht11_val[5] = {0, 0, 0, 0, 0};

void dht11_read_val()
{
  char str[128];
    uint8_t lststate = 1;   // Last state of the DHT11 pin, initialized to 1 (high)
    uint8_t counter = 0;    // Counter variable to count pulse width
    uint8_t j = 0, i;       // Loop variables
    // float farenheit;      // Uncomment if you wish to use Fahrenheit

    // Initialize the array to zeros before reading new values
    for (i = 0; i < 5; i++)
        dht11_val[i] = 0;

    // Initialize DHT11 communication
    DHT11DDR |= (1 << DHT11PIN);    // Set DHT11PIN as output
    DHT11PORT &= ~(1 << DHT11PIN);  // Pull DHT11PIN low
    _delay_ms(18);                  // Wait 18 ms
    DHT11PORT |= (1 << DHT11PIN);   // Pull DHT11PIN high
    _delay_us(40);                  // Wait 40 us

    // Switch to input to read from the DHT11 sensor
    DHT11DDR &= ~(1 << DHT11PIN);

    // Loop to read DHT11 data
    for (i = 0; i < MAX_TIME; i++)
    {
        counter = 0;
        // Measure the length of each pulse
        while ((DHT11PINREG & (1 << DHT11PIN)) == lststate)
        {
            counter++;
            _delay_us(1);
            // Break if counter reaches 255 (overflow)
            if (counter == 255)
                break;
        }

        lststate = DHT11PINREG & (1 << DHT11PIN); // Update last state

        // If the counter reached 255, break from the loop
        if (counter == 255)
            break;

        // Parse actual data from the sensor, skip initial 3 transitions
        if ((i >= 4) && (i % 2 == 0))
        {
            // Shift data and insert a bit into the least significant bit
            dht11_val[j / 8] <<= 1;
            // If the pulse is longer than 16us, it is a '1'
            if (counter > 26)
                dht11_val[j / 8] |= 1;
            j++;
        }
    }

    //if ((j >= 40) && (dht11_val[4] == ((dht11_val[0] + dht11_val[1] + dht11_val[2] + dht11_val[3]) & 0xFF)))
    //{
        // Uncomment if you wish to use Fahrenheit
        // farenheit = dht11_val[2] * 9.0 / 5.0 + 32;
        sprintf(str,"Humidity = %d.%d %% Temperature = %d.%d C\n", dht11_val[0], dht11_val[1], dht11_val[2], dht11_val[3]); //, farenheit);
    //}
    //else
        //sprintf(str,"Invalid Data!!\n");

        pc_comm_send_string_blocking(str);
}

int main(void)
{
  pc_comm_init(9600, NULL);
    while (1)
    {
        dht11_read_val();
        _delay_ms(3000);
    }
    return 0;
}
