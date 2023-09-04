#include "includes.h"
#include "pc_comm.h"
#include "dht11.h"
#include "display.h"
#include "leds.h"
#include "light.h"
#include "buzzer.h"
#include "buttons.h"
#include "periodic_task.h"


void my_function_a(void) {
    leds_toggle(1);
    static uint16_t i=0;
    i++;
    display_int(i);
}

void my_function_b(void) {
    static int16_t i=0;
    i++;
    char str[20];
    sprintf(str,"number %d", i);
    pc_comm_send_string_blocking(str);
}
void my_function_c(void) {
     char str[50];
     sprintf(str, "float value = %f \n",get_exact_interval_b());
    pc_comm_send_string_blocking(str);
}

int main(void) {


    pc_comm_init(115200, NULL);
    leds_init();
    timer_init_a(my_function_a, 60000);
    display_init();


    timer_init_b(my_function_b, 1000);
    timer_init_c(my_function_c, 1000);

    while (1) {
        // Your main loop code here
    }

    return 0;
}
   

