#include "main_page.hpp"
#include "page_manager.hpp"
#include "stm32h7xx_ll_rtc.h"
#include "stm32h7xx_ll_rcc.h"

static void top_panel_event_cb(lv_event_t * event);

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
    calendar_p->set_date(__LL_RTC_CONVERT_BCD2BIN(LL_RTC_DATE_GetDay(RTC)), __LL_RTC_CONVERT_BCD2BIN(LL_RTC_DATE_GetMonth(RTC)), 2000 + __LL_RTC_CONVERT_BCD2BIN(LL_RTC_DATE_GetYear(RTC)));
    top_panel_p = new TopPanel(470, 40, 5, 5, screen);
    top_panel_p->set_time(12, 30);
    top_panel_p->set_text("");
    lv_obj_add_event_cb(top_panel_p->get_event_zone(), top_panel_event_cb, LV_EVENT_CLICKED, NULL);
    ThemeManager theme_manager = ThemeManager::get_manager();
    set_theme(theme_manager.get_theme(LIGHT_THEME));
}

void 
MainPage::load(void) {
    lv_screen_load(screen);
}

void
MainPage::set_theme(ui_style_t theme) {
    lv_obj_set_style_bg_color(screen, theme.background_color, 0);
    temperature_card_p->set_theme(theme);
    pressure_card_p->set_theme(theme);
    humidity_card_p->set_theme(theme);
    co2_card_p->set_theme(theme);
    calendar_p->set_theme(theme);
    top_panel_p->set_theme(theme);
}

void
MainPage::set_time(void) {
    top_panel_p->set_time(__LL_RTC_CONVERT_BCD2BIN(LL_RTC_TIME_GetHour(RTC)),__LL_RTC_CONVERT_BCD2BIN(LL_RTC_TIME_GetMinute(RTC)));
    calendar_p->set_date(__LL_RTC_CONVERT_BCD2BIN(LL_RTC_DATE_GetDay(RTC)), __LL_RTC_CONVERT_BCD2BIN(LL_RTC_DATE_GetMonth(RTC)), 2000 + __LL_RTC_CONVERT_BCD2BIN(LL_RTC_DATE_GetYear(RTC)));
}

static void 
top_panel_event_cb(lv_event_t * event)
{
    PageManager page_manager = PageManager::get_manager();
    page_manager.load_page(SETTINGS_PAGE);
}