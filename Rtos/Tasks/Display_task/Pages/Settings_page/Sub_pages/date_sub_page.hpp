#pragma once
#include "lvgl.h"
#include "theme_manager.hpp"
#include "label.hpp"
#include "calendar_card.hpp"

class DateSubPage {
    private:
    public:
        lv_obj_t * page;
        Label    * calendar_card_label_p;
        lv_obj_t * calendar_card;
        lv_obj_t * calendar_card_header;
        CalendarCard * calendar_p;

        DateSubPage(lv_obj_t * menu);
        void set_theme(ui_style_t theme);
};