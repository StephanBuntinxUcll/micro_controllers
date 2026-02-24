#include <stdio.h>
#include "component1.h"
#include "driver/gpio.h"

void setup_Button( gpio_num_t pin)
{
    gpio_reset_pin(pin);
    gpio_set_direction(pin, GPIO_MODE_INPUT);
    gpio_pullup_en(pin);
}

void setup_led( gpio_num_t pin)
{
    gpio_reset_pin(pin);
    gpio_set_direction(pin, GPIO_MODE_OUTPUT);
}

void test_button(gpio_num_t pin)
{
    if (gpio_get_level(pin) ==0){
        printf("Button on pin %d is pressed\n", pin);
    }
    
}