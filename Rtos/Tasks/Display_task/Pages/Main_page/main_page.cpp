#include "main_page.hpp"

MainPage::MainPage() {
    screen = lv_obj_create(NULL);
    temperature_card_p = new SensorCard(150, 150, 5, 55, screen);
    temperature_card_p->set_label("Температура");
    temperature_card_p->set_data_font(&lv_font_montserrat_44);
    temperature_card_p->set_data("%d°C",20);
    pressure_card_p = new SensorCard(150, 100, 5, 215, screen);
    pressure_card_p->set_label("Давление");
    pressure_card_p->set_data("%dmm",760);
    humidity_card_p = new SensorCard(150, 100, 165, 215, screen);
    humidity_card_p->set_label("Влажность");
    humidity_card_p->set_data("%d%%",40);
    co2_card_p = new SensorCard(150, 100, 325, 215, screen);
    co2_card_p->set_label("CO2");
    co2_card_p->set_data("%dppm",1920);
    calendar_p = new CalendarCard(310, 150, 165, 55, screen);
    calendar_p->set_date(29, 8, 2024);
    top_panel_p = new TopPanel(470, 40, 5, 5, screen);
    top_panel_p->set_time(12, 30);
    top_panel_p->set_text("");
    ThemeManager theme_manager = ThemeManager::get_manager();
    set_colors(theme_manager.get_theme(LIGHT_THEME));
}

void 
MainPage::load(void) {
    lv_screen_load(screen);
}

void
MainPage::set_colors(ui_style_t colors) {
    lv_obj_set_style_bg_color(screen, colors.background_color, 0);
    temperature_card_p->set_colors(colors);
    pressure_card_p->set_colors(colors);
    humidity_card_p->set_colors(colors);
    co2_card_p->set_colors(colors);
    calendar_p->set_colors(colors);
    top_panel_p->set_colors(colors);
}