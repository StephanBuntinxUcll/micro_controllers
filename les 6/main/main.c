#include <stdio.h>
#include "myUART.h"
#include "driver/uart.h"

char buf[256]; // Adjust size as needed 
void app_main(void)
{
    myUART_setup(115200, 1);

   sprintf(buf, "hello world\n");
   uart_write_bytes(2, buf, strlen(buf));
}
