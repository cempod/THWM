#ifndef __SPI_H
#define __SPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void spi_init(void);
void spi_send_byte(uint8_t byte);

#ifdef __cplusplus
}
#endif

#endif