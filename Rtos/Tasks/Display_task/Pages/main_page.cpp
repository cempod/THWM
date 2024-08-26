#include "main_page.hpp"

MainPage::MainPage() {
    screen = lv_obj_create(NULL);
    temperature_card_p = new SensorCard(150, 150, 5, 55, screen);
    temperature_card_p->set_label("Temperature");
    pressure_card_p = new SensorCard(150, 100, 5, 215, screen);
    pressure_card_p->set_label("Pressure");
    humidity_card_p = new SensorCard(150, 100, 165, 215, screen);
    humidity_card_p->set_label("Humidity");
    co2_card_p = new SensorCard(150, 100, 325, 215, screen);
    co2_card_p->set_label("CO2");
    calendar_p = new CalendarCard(310, 150, 165, 55, screen);
}

void 
MainPage::load(void) {
    lv_screen_load(screen);
}