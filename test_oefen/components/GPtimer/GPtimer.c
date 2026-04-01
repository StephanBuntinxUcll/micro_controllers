#include <stdio.h>
#include "GPtimer.h"
#include "driver/gptimer.h"

gptimer_handle_t gptimer = NULL;
gptimer_config_t timer_config = {
    .clk_src = GPTIMER_CLK_SRC_DEFAULT, // Select the default clock source
    .direction = GPTIMER_COUNT_UP,      // Counting direction is up
    .resolution_hz = 1 * 1000 * 1000,   // Resolution is 1 MHz, i.e., 1 tick equals 1 microsecond
};
// // Create a timer instance
// ESP_ERROR_CHECK(gptimer_new_timer(&timer_config, &gptimer));
// // Enable the timer
// ESP_ERROR_CHECK(gptimer_enable(gptimer));
// // Start the timer
// ESP_ERROR_CHECK(gptimer_start(gptimer));


void setup_timer(){
    gptimer_new_timer(&timer_config, &gptimer);
    gptimer_enable(gptimer);
    gptimer_start(gptimer);
}
