#include <stdio.h>
#include "myGPIO.h"
#include "freertos/FreeRTOS.h"

#define LED1 2
#define KNOP1 0 


static void IRAM_ATTR ButtenISR(void* args){
        
        myGPIO_LED_Toggle(LED1);
    }

void app_main(void)
{

    myGPIO_LED_Setup(LED1);
    myGPIO_KNOP_Setup(KNOP1);

    while(1){
        
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        myGPIO_LED_On(LED1);
        

    }
}
