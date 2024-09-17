#pragma once
#include "lvgl.h"
#include "top_panel.hpp"
#include "display_sub_page.hpp"

class SettingsPage {
    private:
        lv_obj_t * screen;
        lv_obj_t * page;
        TopPanel * top_panel_p;
        lv_obj_t * menu;
        lv_obj_t * menu_main_section;
        lv_obj_t * menu_root_page;
        DisplaySubPage * display_sub_page_p;

        void create_menu(void);
        void add_page_to_menu(lv_obj_t * parent, const char * icon, const char * page_name, lv_obj_t * page_content);
    public:
        SettingsPage();
        void load(void);
        void set_theme(ui_style_t theme);
};