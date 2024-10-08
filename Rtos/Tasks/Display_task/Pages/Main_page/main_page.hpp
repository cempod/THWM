#pragma once
#include "lvgl.h"
#include "sensor_card.hpp"
#include "calendar_card.hpp"
#include "top_panel.hpp"

class MainPage
{
private:
    lv_obj_t * screen;
    SensorCard * temperature_card_p;
    SensorCard * pressure_card_p;
    SensorCard * humidity_card_p;
    SensorCard * co2_card_p;
    CalendarCard * calendar_p;
    TopPanel * top_panel_p;
public:
    MainPage();
    void load(void);
    void set_theme(ui_style_t theme);
    void set_time(void);
};
