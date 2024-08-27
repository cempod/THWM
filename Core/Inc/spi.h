#ifndef __SPI_H
#define __SPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void spi_init(void);
void spi_send_byte(uint8_t byte);
void spi_send_dma(uint8_t * bytes, uint32_t size);

#ifdef __cplusplus
}
#endif

#endif