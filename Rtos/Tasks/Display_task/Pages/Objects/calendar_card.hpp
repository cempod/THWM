#pragma once
#include "display.h"

class CalendarCard
{
private:
    lv_obj_t  * calendar;
    ui_style_t calendar_theme;
public:
    CalendarCard(int x_size, int y_size, int x_offset, int y_offset, lv_obj_t * parrent);
    void set_colors(ui_style_t colors);
    void set_date(uint32_t day, uint32_t month, uint32_t year);
};