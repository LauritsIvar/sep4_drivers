#include "includes.h"
#include "pc_comm.h"
#include "dht11.h"


int main(void)
{
  pc_comm_init(115200, NULL);
    uint8_t h1, h2, t1, t2;
    char str[128];
    while (1)
    {

      h1 =h2 =t1= t2=0;

        dht11_get(&h1, &h2, &t1, &t2);
        _delay_ms(1400);
        
        uint8_t humidity_integer, humidity_decimal, temperature_integer, temperature_decimal;
        dht11_get(&humidity_integer, &humidity_decimal, &temperature_integer, &temperature_decimal);
        sprintf(str, "Humidity = %d.%d%% and the temperature = %d.%d C\n\n", humidity_integer, humidity_decimal, temperature_integer, temperature_decimal);
        pc_comm_send_string_blocking(str);
    }
    return 0;
}
