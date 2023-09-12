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



int main(void) {
    pc_comm_init(115200, NULL);
    leds_init();
    //ADXL345_init();
    display_init();
    hc_sr04_init();
    light_init();
    wifi_init();

    while (1) {
_delay_ms(1000);
display_int(hc_sr04_takeMeasurement());


    
}return 0;}
   

