#pragma once
#include "lvgl.h"
#include "top_panel.hpp"

class SettingsPage
{
private:
    lv_obj_t * screen;
    lv_obj_t * page;
    TopPanel * top_panel_p;
    lv_obj_t * menu;

    void create_menu(void);
public:
    SettingsPage();
    void load(void);
    void set_colors(ui_style_t colors);
};
