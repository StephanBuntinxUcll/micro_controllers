#include <stdio.h>
#include "component_licht.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/dac_oneshot.h"
#include "esp_adc/adc_oneshot.h"
#include "Component_ADC.h"

#define DAC_PIN DAC_CHANNEL_1 // GPIO25
#define ADC_CHANNEL ADC_CHANNEL_0// GPIO34

void app_main(void)
{
    
    myDAC_Setup(DAC_PIN);
    setup_adc(ADC_CHANNEL);


    while (1) {
        
        int adc_value = adc_read(ADC_CHANNEL);
        printf("ADC Value: %d\n", adc_value);
        int dac_value = (adc_value * 255) / 4095; // Scale 12-bit ADC to 8-bit DAC
        
        myDAC_WriteVoltage(dac_value); // Output to DAC channel
        vTaskDelay(pdMS_TO_TICKS(100)); // Delay for 1 second
      
    }
}
