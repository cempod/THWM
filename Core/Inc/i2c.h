#ifndef __I2C_H
#define __I2C_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define I2C_OK 1
#define I2C_ERROR 0

void i2c_init(void);
uint8_t i2c_read_byte(uint16_t addr, uint8_t * byte);
#ifdef __cplusplus
}
#endif

#endif