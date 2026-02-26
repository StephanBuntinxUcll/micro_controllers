

#pragma once

#include "driver/gpio.h"

void setup_Button(gpio_num_t pin);

void setup_led(gpio_num_t pin);

int test_pin(gpio_num_t pin);

int flank(gpio_num_t pin);

int led_on(gpio_num_t pin);

int led_off(gpio_num_t pin);

void toggle(gpio_num_t pin);