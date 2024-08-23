#pragma once
#include "lvgl.h"
#include "sensor_card.hpp"
#include "calendar_card.hpp"

class MainPage
{
private:
    lv_obj_t * screen;
    SensorCard * temperature_card_p;
    SensorCard * pressure_card_p;
    SensorCard * humidity_card_p;
    SensorCard * co2_card_p;
    CalendarCard * calendar_p;
public:
    MainPage();
    void load(void);
};
