#pragma once
#include "theme_manager.hpp"

class CalendarCard
{
private:
    lv_obj_t  * calendar;
    ui_style_t calendar_theme;
public:
    CalendarCard(int x_size, int y_size, int x_offset, int y_offset, lv_obj_t * parrent);
    void set_theme(ui_style_t theme);
    void set_date(uint32_t day, uint32_t month, uint32_t year);
    lv_obj_t  * get_calendar_obj(void);
};