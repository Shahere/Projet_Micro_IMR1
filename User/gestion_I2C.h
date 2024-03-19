#ifndef __gestion_I2C_H__
#define __gestion_I2C_H__

#include "lpc17xx_timer.h"

void init_i2c_eeprom();
void i2c_eeprom_write(uint16_t addr, void* data, int length);
void i2c_eeprom_read(uint16_t addr, void* data, int length);

#endif

