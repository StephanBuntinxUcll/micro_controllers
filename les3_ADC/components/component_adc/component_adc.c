#include <stdio.h>
#include "Component_ADC.h"
#include "driver/adc.h"
#include "esp_adc/adc_oneshot.h"




 adc_oneshot_unit_handle_t adc1_handle;
adc_oneshot_unit_init_cfg_t init_config1 = {
    .unit_id = ADC_UNIT_1,
    .ulp_mode = ADC_ULP_MODE_DISABLE,
};

    adc_oneshot_chan_cfg_t config = {
    .bitwidth = ADC_BITWIDTH_DEFAULT,
    .atten = ADC_ATTEN_DB_12,
};

   


void setup_adc(int kanaal) {
     adc_oneshot_new_unit(&init_config1, &adc1_handle);
     adc_oneshot_config_channel(adc1_handle, kanaal, &config);
}

int adc_read(int kanaal) {
    int adc_raw;
    adc_oneshot_read(adc1_handle, kanaal, &adc_raw);
    return adc_raw;
}
