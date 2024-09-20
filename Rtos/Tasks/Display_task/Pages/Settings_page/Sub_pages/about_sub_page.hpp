#pragma once
#include "lvgl.h"
#include "theme_manager.hpp"

class AboutSubPage {
    public:
        lv_obj_t * page;
        lv_obj_t *    about_label;

        AboutSubPage(lv_obj_t * menu);
        void set_theme(ui_style_t theme);
};