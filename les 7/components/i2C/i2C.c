#include <stdio.h>
#include "driver/i2c.h"
#define I2C_MASTER_SCL_IO 22 // GPIO voor SCL
#define I2C_MASTER_SDA_IO 21 // GPIO voor SDA
#define I2C_MASTER_NUM I2C_NUM_0
#define I2C_MASTER_FREQ_HZ 100000 // 100 kHz (standaard)





static esp_err_t i2c_master_init(void)
{
i2c_config_t conf = {
.mode = I2C_MODE_MASTER,
.sda_io_num = I2C_MASTER_SDA_IO,
.scl_io_num = I2C_MASTER_SCL_IO,
.sda_pullup_en = GPIO_PULLUP_ENABLE,
.scl_pullup_en = GPIO_PULLUP_ENABLE,
.master.clk_speed = I2C_MASTER_FREQ_HZ,
};
esp_err_t err = i2c_param_config(I2C_MASTER_NUM, &conf);
if (err != ESP_OK) return err;
return i2c_driver_install(I2C_MASTER_NUM, conf.mode, 0, 0, 0);
}




void i2c_scan(void)
{
printf("Scannen...\n");
for (uint8_t addr = 0x03; addr < 0x78; addr++) {
i2c_cmd_handle_t cmd = i2c_cmd_link_create();
i2c_master_start(cmd);
i2c_master_write_byte(cmd, (addr << 1) | I2C_MASTER_WRITE, true);
i2c_master_stop(cmd);
esp_err_t ret = i2c_master_cmd_begin(
I2C_MASTER_NUM, cmd, pdMS_TO_TICKS(10));
i2c_cmd_link_delete(cmd);
if (ret == ESP_OK) {
printf(" Gevonden op adres: 0x%02X\n", addr);
}
}
printf("Klaar.\n");
}


