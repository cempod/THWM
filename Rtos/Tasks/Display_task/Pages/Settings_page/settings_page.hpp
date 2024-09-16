#pragma once
#include "lvgl.h"
#include "top_panel.hpp"

class MenuDisplayPage {
    private:
        static void brightness_slider_event_cb(lv_event_t * e);
    public:
        lv_obj_t * page;
        Label * brightness_label_p;
        lv_obj_t * brightness_slider;
        lv_obj_t * brightness_card;
        lv_obj_t * brightness_card_header;

        MenuDisplayPage(lv_obj_t * menu);
        void set_theme(ui_style_t theme);
};

class SettingsPage {
    private:
        lv_obj_t * screen;
        lv_obj_t * page;
        TopPanel * top_panel_p;
        lv_obj_t * menu;
        lv_obj_t * menu_main_section;
        lv_obj_t * menu_root_page;
        MenuDisplayPage * menu_display_page_p;

        void create_menu(void);
        void add_page_to_menu(lv_obj_t * parent, const char * icon, const char * page_name, lv_obj_t * page_content);
    public:
        SettingsPage();
        void load(void);
        void set_theme(ui_style_t theme);
};