# component_licht

Dit ESP-IDF component biedt basisfunctionaliteit voor analoge ingang (ADC) en digitale-naar-analoge converter (DAC) op een ESP32.

## Inhoud

- `component_licht.c` : Implementatie van ADC/DAC functies.
- `include/component_licht.h` : API header.
- `CMakeLists.txt` : Component registratie.
- `idf_component.yml`: metadata.

## Functionaliteit

- `setup_adc(int kanaal)` : initialiseert ADC op het opgegeven ADC kanaal.
- `read_adc(int kanaal)` : leest een ADC-waarde van het opgegeven kanaal.
- `myDAC_Setup(int dac_pin)` : initialiseert een DAC-kanaal (DAC_CHANNEL_1 of DAC_CHANNEL_2).
- `myDAC_WriteVoltage(int value)` : stuurt spanningswaarde naar DAC (0..255).
- (Uit commentaar: `output_to_dac(int dac_pin, int value)` is in header aanwezig maar in C file uitgecommentarieerd.)

## Vereisten

```cmake
idf_component_register(
    SRCS "component_licht.c"
    INCLUDE_DIRS "include"
    REQUIRES esp_adc esp_driver_dac
)
```

## Voorbeeld gebruik

```c
#include "component_licht.h"

void app_main(void)
{
    int adc_kanal = ADC_CHANNEL_0; // pas aan naargelang jouw board
    setup_adc(adc_kanal);

    int dac_chan = DAC_CHANNEL_1; // of DAC_CHANNEL_2
    myDAC_Setup(dac_chan);

    while (1) {
        int waarde = read_adc(adc_kanal);
        // eventueel schalen naar DAC range 0-255
        int dac_waarde = (waarde * 255) / 4095;
        myDAC_WriteVoltage(dac_waarde);

        // logs
        printf("ADC=%d, DAC=%d\n", waarde, dac_waarde);
        vTaskDelay(pdMS_TO_TICKS(200));
    }
}
```

## Opmerkingen

- ADC en DAC setups worden momenteel elke keer aangeroepen vanuit de setup-functies; hergebruik van initialisaties kan nuttig zijn om power/time te besparen.
- Controleer pin-toewijzing op jouw ESP32-module (ADC_CHANNEL_0..7, DAC_CHANNEL_1/2).
