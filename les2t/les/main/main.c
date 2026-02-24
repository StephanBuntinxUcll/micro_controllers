#include <stdio.h>
#include "component1.h"
#include "driver/gpio.h"

#define BUTTON_PIN GPIO_NUM_32
#define LED_PIN GPIO_NUM_12


void app_main(void)
{
    setup_Button(BUTTON_PIN);

    setup_led(LED_PIN);

    while (1) {
        test_button(BUTTON_PIN);

    
    }
}
