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


void my_function_a(void) {
    leds_toggle(1);
    int x, y, z;
    //adxl345_read_xyz(&x, &y, &z);
  
    display_int(light_read());
    
}

void my_function_b(void) {}

void my_function_c(void) {
     char str[50];
     sprintf(str, "float value = %f \n",get_exact_interval_b());
    pc_comm_send_string_blocking(str);
}

int main(void) {


    pc_comm_init(115200, NULL);
    leds_init();
    ADXL345_init();
    timer_init_a(my_function_a, 1000);
    display_init();
    hc_sr04_init();
    light_init();


    timer_init_b(my_function_b, 1000);
    timer_init_c(my_function_c, 1000);

    while (1) {
        // Your main loop code here
    }

    return 0;
}
   

