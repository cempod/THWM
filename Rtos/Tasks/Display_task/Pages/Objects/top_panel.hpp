#pragma once
#include "theme_manager.hpp"
#include "label.hpp"

class TopPanel
{
private:
    lv_obj_t * panel;
    Label * time_label_p;
    Label * header_label_p;
public:
    TopPanel(int x_size, int y_size, int x_offset, int y_offset, lv_obj_t * parrent);
    void set_colors(ui_style_t colors);
    void set_time(uint8_t hour, uint8_t minute);
    void set_text(const char* text);
};
