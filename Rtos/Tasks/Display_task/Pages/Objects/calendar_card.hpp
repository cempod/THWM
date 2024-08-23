#pragma once
#include "lvgl.h"

class CalendarCard
{
private:
    lv_obj_t  * calendar;
public:
    CalendarCard(int x_size, int y_size, int x_offset, int y_offset, lv_obj_t * parrent);
};