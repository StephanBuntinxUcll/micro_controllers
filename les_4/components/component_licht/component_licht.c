#include <stdio.h>
#include "component_licht.h"
#include "esp_adc/adc_oneshot.h"
#include "driver/dac_oneshot.h"

adc_oneshot_unit_handle_t adc1_handle;
adc_oneshot_unit_init_cfg_t init_config1 = {
    .unit_id = ADC_UNIT_2,
    .ulp_mode = ADC_ULP_MODE_DISABLE,
};

adc_oneshot_chan_cfg_t config = {
    .bitwidth = ADC_BITWIDTH_DEFAULT,
    .atten = ADC_ATTEN_DB_12,
};

dac_oneshot_handle_t dac_handle;


void setup_adc(int kanaal) {
    adc_oneshot_new_unit(&init_config1, &adc1_handle);
    adc_oneshot_config_channel(adc1_handle, kanaal, &config);
}

int read_adc(int kanaal){
    int result;
    adc_oneshot_read(adc1_handle, kanaal, &result);
    // printf("ADC Reading: %d\n", result);
    return result;
}



void myDAC_Setup(int dac_pin)
{
    //dac_output_enable(DAC_CHANNEL_1); // or DAC_CHANNEL_2
    dac_oneshot_config_t chan_cfg = 
    {
        .chan_id = dac_pin, // or DAC_CHANNEL_2
    };
dac_oneshot_new_channel(&chan_cfg, &dac_handle);
}

void myDAC_WriteVoltage(int value)
{
    dac_oneshot_output_voltage(dac_handle,value);
    
}

// void output_to_dac(int dac_pin, int value)
// {
//     /* make sure the DAC channel is initialised (idempotent) */
//     myDAC_Setup(dac_pin);

//     /* pass the channel handle and the desired voltage level (0-255) */
//     dac_oneshot_output_voltage(dac_handle, value);
// }