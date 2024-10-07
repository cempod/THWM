#include "date_time_sub_page.hpp"
#include "rtos.h"
#include "stm32h7xx_ll_rtc.h"
#include "stm32h7xx_ll_rcc.h"

DateTimeSubPage::DateTimeSubPage(lv_obj_t * menu) {
    page = lv_menu_page_create(menu, NULL);
    lv_obj_set_style_pad_hor(page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
    lv_menu_separator_create(page);
    lv_obj_set_style_pad_all(page,0,0);
    calendar_card = lv_obj_create(page);
    lv_obj_set_style_clip_corner(calendar_card, true, 0);
    lv_obj_align(calendar_card, LV_ALIGN_TOP_MID, 0, 5);
    lv_obj_set_size(calendar_card, 310, 300);
    lv_obj_set_style_pad_all(calendar_card,0,0);
    lv_obj_set_style_border_width(calendar_card, 1, 0);
    calendar_card_header = lv_obj_create(calendar_card);
    lv_obj_set_size(calendar_card_header, 310-2, 35);
    lv_obj_align(calendar_card_header, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_set_style_border_side(calendar_card_header, LV_BORDER_SIDE_NONE, 0);
    lv_obj_set_style_radius(calendar_card_header, 0, 0);
    lv_obj_set_style_pad_all(calendar_card_header,0,0);
    calendar_card_label_p = new Label(0,0, &lv_font_montserrat_14, calendar_card_header);
    calendar_card_label_p->set_text("Настройка даты");
    calendar_p = new CalendarCard(300, 255, 5, 40, calendar_card);
    calendar_p->set_date(__LL_RTC_CONVERT_BCD2BIN(LL_RTC_DATE_GetDay(RTC)), __LL_RTC_CONVERT_BCD2BIN(LL_RTC_DATE_GetMonth(RTC)), 2000 + __LL_RTC_CONVERT_BCD2BIN(LL_RTC_DATE_GetYear(RTC)));
    lv_calendar_header_arrow_create(calendar_p->get_calendar_obj());
}

void
DateTimeSubPage::set_theme(ui_style_t theme) {
    lv_obj_set_style_bg_color(page, theme.background_color, 0);
    lv_obj_set_style_bg_color(calendar_card, theme.card_background_color, 0);
    lv_obj_set_style_border_color(calendar_card, theme.border_color, 0);
    lv_obj_set_style_bg_color(calendar_card_header, theme.header_color, 0);
    calendar_card_label_p->set_font(theme.main_font);
    calendar_card_label_p->set_color(theme.header_font_color);
}