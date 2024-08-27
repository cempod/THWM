#ifndef __ST7735_H
#define __ST7735_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void st7796_init();
void st7796_draw(uint8_t* pixels, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void st7796_draw_dma(uint8_t* pixels, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

#ifdef __cplusplus
}
#endif

#endif 
