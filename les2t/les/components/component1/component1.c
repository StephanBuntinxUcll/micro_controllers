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
    gpio_set_direction(pin, GPIO_MODE_INPUT_OUTPUT);
}

int test_pin(gpio_num_t pin)
{
    
    return gpio_get_level(pin);  
}

int flank(gpio_num_t pin)
{
    static int oud = 1;
    static int current= 1;
    oud = current;
    current = gpio_get_level(pin);
    
    if(oud > current){
       return 1;
    }
    return 0;
}
int led_on(gpio_num_t pin)
{
    gpio_set_level(pin, 1);
    return 1;
}

int led_off(gpio_num_t pin)
{
    gpio_set_level(pin, 0);
    return 0;
}

void toggle(gpio_num_t pin)
{
    int current = gpio_get_level(pin);
    if(current){
        gpio_set_level(pin, 0);
    } else {
        gpio_set_level(pin, 1);
    }
}
