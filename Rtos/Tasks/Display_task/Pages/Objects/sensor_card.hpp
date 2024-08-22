#pragma once
#include "lvgl.h"
#include "label.hpp"

class SensorCard
{
private:
    lv_obj_t * card;
    lv_obj_t * header;
    Label * top_label_p;
public:
    SensorCard(int x_offset, int y_offset, lv_obj_t * parrent);
};

