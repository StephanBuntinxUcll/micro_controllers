#include <stdio.h>
#include "component_licht.h"
#include "esp_adc/adc_oneshot.h"
#include "driver/dac_oneshot.h"


dac_oneshot_handle_t dac_handle;



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