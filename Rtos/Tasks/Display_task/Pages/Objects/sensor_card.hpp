#pragma once
#include "lvgl.h"
#include "label.hpp"

class SensorCard
{
private:
    lv_obj_t * card;
    Label * top_label_p;
public:
    SensorCard(lv_obj_t * parrent);
};

