#include "includes.h"
#include "pc_comm.h"
#include "dht11.h"


int main(void)
{
  pc_comm_init(9600, NULL);
    uint8_t h1, h2, t1, t2;
    char str[128];
    while (1)
    {

        dht11_get(&h1, &h2, &t1, &t2);
        _delay_ms(3000);
        sprintf(str, "humidity = %d.%d%%\ntemperature = %d.%d C\n\n", h1,h2,t1,t2);
        pc_comm_send_string_blocking(str);
    }
    return 0;
}
