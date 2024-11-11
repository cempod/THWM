#pragma once
#include "lvgl.h"
#include "top_panel.hpp"
#include "display_sub_page.hpp"
#include "about_sub_page.hpp"
#include "date_sub_page.hpp"

class SettingsPage {
    private:
        lv_obj_t * screen;
        lv_obj_t * page;
        TopPanel * top_panel_p;
        lv_obj_t * menu;
        lv_obj_t * menu_main_section;
        lv_obj_t * menu_root_page;
        lv_obj_t * other_section_label;
        lv_obj_t * menu_other_section;
        DisplaySubPage * display_sub_page_p;
        AboutSubPage * about_sub_page_p;
        DateSubPage * date_sub_page_p;

        void create_menu(void);
        void add_page_to_menu(lv_obj_t * parent, const char * icon, const char * page_name, lv_obj_t * page_content);
    public:
        SettingsPage();
        void load(void);
        void set_theme(ui_style_t theme);
        void set_time(void);
};