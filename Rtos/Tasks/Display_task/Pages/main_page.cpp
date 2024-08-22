#include "main_page.hpp"

MainPage::MainPage() {
    screen = lv_obj_create(NULL);
    lv_obj_set_style_bg_color (screen , lv_palette_darken(LV_PALETTE_GREY,4),0) ;
    SensorCard temperature_card(screen);
    temperature_card_p = &temperature_card;
}

void 
MainPage::load(void) {
    lv_screen_load(screen);
}