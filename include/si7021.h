/*
 * HTU21D Component
 *
 * esp-idf component to interface with HTU21D humidity and temperature sensor
 * by TE Connectivity (http://www.te.com/usa-en/product-CAT-HSC0004.html)
 *
 * Luca Dentella, www.lucadentella.it
 */

#ifndef __ESP_SI7021_H__
#define __ESP_SI7021_H__

#ifdef __cplusplus
extern "C" {
#endif

 // Error library
#include "esp_err.h"

// I2C driver
#include "driver/i2c.h"

// FreeRTOS (for delay)
#include "freertos/task.h"

// sensor address
#define SI7021_ADDR		0x40

#define SI7021_MEASRH_HOLD_CMD           0xE5
#define SI7021_MEASRH_NOHOLD_CMD         0xF5
#define SI7021_MEASTEMP_HOLD_CMD         0xE3   // TRIGGER_TEMP_MEASURE_HOLD
#define SI7021_MEASTEMP_NOHOLD_CMD       0xF3
#define SI7021_READPREVTEMP_CMD          0xE0
#define SI7021_RESET_CMD                 0xFE
#define SI7021_WRITERHT_REG_CMD          0xE6
#define SI7021_READRHT_REG_CMD           0xE7
#define SI7021_WRITEHEATER_REG_CMD       0x51
#define SI7021_READHEATER_REG_CMD        0x11
#define SI7021_ID1_CMD                   0xFA0F
#define SI7021_ID2_CMD                   0xFCC9
#define SI7021_FIRMVERS_CMD              0x84B8

// HTU21D commands
#define TRIGGER_TEMP_MEASURE_HOLD  		0xE3
#define TRIGGER_HUMD_MEASURE_HOLD  		0xE5
#define TRIGGER_TEMP_MEASURE_NOHOLD  	0xF3
#define TRIGGER_HUMD_MEASURE_NOHOLD  	0xF5
#define WRITE_USER_REG  				0xE6
#define READ_USER_REG  					0xE7
#define SOFT_RESET  					0xFE

// return values
#define SI7021_ERR_OK				0x00
#define SI7021_ERR_CONFIG			0x01
#define SI7021_ERR_INSTALL			0x02
#define SI7021_ERR_NOTFOUND			0x03
#define SI7021_ERR_INVALID_ARG		0x04
#define SI7021_ERR_FAIL		 		0x05
#define SI7021_ERR_INVALID_STATE	0x06
#define SI7021_ERR_TIMEOUT	 		0x07

// variables
i2c_port_t _port;

// functions
int si7021_init(i2c_port_t port, int sda_pin, int scl_pin, gpio_pullup_t sda_internal_pullup, gpio_pullup_t scl_internal_pullup);
float si7021_read_temperature();
float si7021_read_humidity();
uint8_t si7021_get_resolution();
int si7021_set_resolution(uint8_t resolution);
int si7021_soft_reset();

// helper functions
uint8_t si7021_read_user_register();
int si7021_write_user_register(uint8_t value);
uint16_t read_value(uint8_t command);
bool is_crc_valid(uint16_t value, uint8_t crc);

#ifdef __cplusplus
}
#endif

#endif  // __ESP_SI7021_H__
