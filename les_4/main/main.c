#include <stdio.h>
#include "component_licht.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/dac_oneshot.h"

#define ADC_CHANNEL ADC2_CHANNEL_0 // GPIO36
#define DAC_PIN DAC_CHANNEL_1 // GPIO25


void app_main(void)
{
    setup_adc(ADC_CHANNEL);
    myDAC_Setup(DAC_PIN);


    while (1) {
        
        int adc_value = read_adc(ADC_CHANNEL);
        printf("ADC Value: %d\n", adc_value);
        vTaskDelay(pdMS_TO_TICKS(100)); // Delay for 1 second

        int dac_value = (adc_value * 255) / 4095; // Scale 12-bit ADC to 8-bit DAC
        myDAC_WriteVoltage(dac_value); // Output to DAC channel
      
    }
}
