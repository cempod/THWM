#pragma once
#include "lvgl.h"
#include "top_panel.hpp"

class SettingsPage
{
private:
    lv_obj_t * screen;
    TopPanel * top_panel_p;
public:
    SettingsPage();
    void load(void);
    void set_colors(ui_style_t colors);
};
