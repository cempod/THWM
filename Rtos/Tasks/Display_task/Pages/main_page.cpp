#include "main_page.hpp"

MainPage::MainPage() {
    screen = lv_obj_create(NULL);
    SensorCard temperature_card(150, 150, 5, 55, screen);
    temperature_card_p = &temperature_card;
    SensorCard pressure_card(150, 100, 5, 215, screen);
    pressure_card_p = &pressure_card;
    SensorCard humidity_card(150, 100, 165, 215, screen);
    humidity_card_p = &humidity_card;
    SensorCard co2_card(150, 100, 325, 215, screen);
    co2_card_p = &co2_card;
    CalendarCard calendar(310, 150, 165, 55, screen);
    calendar_p = &calendar;
}

void 
MainPage::load(void) {
    lv_screen_load(screen);
}