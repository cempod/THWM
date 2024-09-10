#pragma once
#include "lvgl.h"
#include "top_panel.hpp"

class SettingsPage {
    private:
        lv_obj_t * screen;
        lv_obj_t * page;
        TopPanel * top_panel_p;
        lv_obj_t * menu;
        lv_obj_t * menu_main_section;
        lv_obj_t * menu_root_page;

        void create_menu(void);
        void add_page_to_menu(lv_obj_t * parent, const char * icon, const char * page_name, lv_obj_t * page_content);
    public:
        SettingsPage();
        void load(void);
        void set_colors(ui_style_t colors);
};

class MenuDisplayPage {
    public:
        lv_obj_t * page;
        lv_obj_t * label;

        MenuDisplayPage(lv_obj_t * menu);
        void set_colors(ui_style_t colors);
};
