#pragma once
#include "display.h"
#include "label.hpp"

class SensorCard
{
private:
    lv_obj_t * card;
    lv_obj_t * header;
    Label * top_label_p;
    Label * sensor_label_p;
public:
    SensorCard(int x_size, int y_size, int x_offset, int y_offset, lv_obj_t * parrent);
    void set_colors(ui_style_t colors);
    void set_label(const char* label);
    void set_data(const char* text, uint32_t arg);
    void set_data_font(const lv_font_t * font);
};

