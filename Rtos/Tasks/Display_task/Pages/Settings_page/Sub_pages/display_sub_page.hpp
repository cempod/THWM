#pragma once
#include "lvgl.h"
#include "theme_manager.hpp"
#include "label.hpp"

class DisplaySubPage {
    private:
        static void brightness_slider_event_cb(lv_event_t * e);
    public:
        lv_obj_t * page;
        Label * brightness_label_p;
        lv_obj_t * brightness_slider;
        lv_obj_t * brightness_card;
        lv_obj_t * brightness_card_header;

        DisplaySubPage(lv_obj_t * menu);
        void set_theme(ui_style_t theme);
};