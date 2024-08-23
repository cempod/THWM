#ifndef __DISPLAY_H
#define __DISPLAY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

typedef struct {
    lv_color_t background_color;
    lv_color_t card_background_color;
    lv_color_t header_color;
    lv_color_t main_font_color;
    lv_color_t header_color_t;
    lv_color_t border_color;
} ui_style_t;

const ui_style_t light_theme = {
    .background_color = LV_COLOR_MAKE(0xFF, 0xFF, 0xFF),
    .card_background_color = LV_COLOR_MAKE(0xFF, 0xFF, 0xFF),
    .header_color = LV_COLOR_MAKE(0xF4, 0x43, 0x36),
    .main_font_color = LV_COLOR_MAKE(0xF4, 0x43, 0x36),
    .header_color_t = LV_COLOR_MAKE(0xF4, 0x43, 0x36),
    .border_color = LV_COLOR_MAKE(0xF4, 0x43, 0x36)
};

void display_task(void* arg);

#ifdef __cplusplus
}
#endif

#endif