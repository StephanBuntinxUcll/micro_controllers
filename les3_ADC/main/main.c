#include <stdio.h>
#include "Component_ADC.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define CHANNEL ADC1_CHANNEL_3 //channel 1 is voor sar1 gpio37




void app_main(void)
{
    setup_adc(CHANNEL);

    while (1)
    {
        /* code */
        int adc_value = adc_read(CHANNEL);
        printf("ADC Value: %d\n", adc_value) ;
        vTaskDelay( pdMS_TO_TICKS(100)); // Delay van 1 seconde
    }
    

}
