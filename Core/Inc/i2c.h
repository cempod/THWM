#ifndef __I2C_H
#define __I2C_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void i2c_init(void);
uint8_t i2c_read_byte(uint16_t addr);
#ifdef __cplusplus
}
#endif

#endif