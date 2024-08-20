#ifndef __ST7735_H
#define __ST7735_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void st7796_init();
void st7796_draw(uint8_t* pixels, uint16_t x, uint16_t y, uint16_t w, uint16_t h);

#ifdef __cplusplus
}
#endif

#endif 
