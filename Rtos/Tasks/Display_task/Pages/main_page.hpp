#pragma once
#include "lvgl.h"
#include "sensor_card.hpp"

class MainPage
{
private:
    lv_obj_t * screen;
    SensorCard * temperature_card_p;
public:
    MainPage(/* args */);
    void load(void);
};
