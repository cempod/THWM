#pragma once
#include "lvgl.h"

class Label {
    private:
    lv_obj_t * label;
    char str[50];

    public:
    Label(int x_offset, int y_offset, const lv_font_t * font, lv_obj_t * parrent);
    void set_text(const char* msg, ...);
    void set_color(lv_color_t color);
    void set_font(const lv_font_t * font);
};