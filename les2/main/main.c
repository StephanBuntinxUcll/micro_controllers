#include <stdio.h>
#include "driver/gpio.h"

#include "component_1.h"
#define LED_PIN 2
#define BUTTON_PIN 27
void app_main(void)
{
    while (1) {
        printf("Hello, World!\n");
        // vTaskDelay(1000 / portTICK_PERIOD_MS);
    gpio_reset_pin(BUTTON_PIN);
    }
}