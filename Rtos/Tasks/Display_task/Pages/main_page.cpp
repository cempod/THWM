#include "main_page.hpp"

MainPage::MainPage() {
    screen = lv_obj_create(NULL);
    temperature_card_p = new SensorCard(150, 150, 5, 55, screen);
    temperature_card_p->set_label("Temperature");
    temperature_card_p->set_data_font(&lv_font_montserrat_44);
    temperature_card_p->set_data("%d°C",20);
    pressure_card_p = new SensorCard(150, 100, 5, 215, screen);
    pressure_card_p->set_label("Pressure");
    pressure_card_p->set_data("%dmm",760);
    humidity_card_p = new SensorCard(150, 100, 165, 215, screen);
    humidity_card_p->set_label("Humidity");
    humidity_card_p->set_data("%d%%",40);
    co2_card_p = new SensorCard(150, 100, 325, 215, screen);
    co2_card_p->set_label("CO2");
    co2_card_p->set_data("%dppm",1920);
    calendar_p = new CalendarCard(310, 150, 165, 55, screen);
    calendar_p->set_date(26, 8, 2024);
    top_panel_p = new TopPanel(470, 45, 5, 5, screen);
    top_panel_p->set_time(12, 30);
}

void 
MainPage::load(void) {
    lv_screen_load(screen);
}