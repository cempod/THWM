#ifndef __I2C_H
#define __I2C_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void i2c_init(void);
void i2c_write(uint16_t addr,uint8_t *buf, uint16_t bytes_count);
void i2c_read(uint16_t addr, uint8_t *buf, uint16_t bytes_count);

#ifdef __cplusplus
}
#endif

#endif