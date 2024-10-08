#include "sensor_card.hpp"
#include <stdio.h>
#include <stdarg.h>

SensorCard::SensorCard(int x_size, int y_size, int x_offset, int y_offset, lv_obj_t * parrent) {
    card = lv_obj_create(parrent);
    lv_obj_align(card, LV_ALIGN_TOP_LEFT, x_offset, y_offset);
    lv_obj_set_size(card, x_size, y_size);
    lv_obj_set_style_pad_all(card,0,0);
    header = lv_obj_create(card);
    lv_obj_set_size(header, x_size-4, 35);
    lv_obj_align(header, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_set_style_border_side(header, LV_BORDER_SIDE_NONE, 0);
    lv_obj_set_style_radius(header, 0, 0);
    lv_obj_set_style_pad_all(header,0,0);
    top_label_p = new Label(0,0, &lv_font_montserrat_14, header);
    sensor_label_p = new Label(0,17, &lv_font_montserrat_30, card);
    ThemeManager theme_manager = ThemeManager::get_manager();
    set_theme(theme_manager.get_theme(LIGHT_THEME));
}

void 
SensorCard::set_theme(ui_style_t theme) {
    lv_obj_set_style_bg_color(card, theme.card_background_color, 0);
    lv_obj_set_style_bg_color (header , theme.header_color, 0);
    top_label_p->set_color(theme.header_font_color);
    top_label_p->set_font(theme.main_font);
    sensor_label_p->set_color(theme.main_font_color);
    lv_obj_set_style_border_color(card, theme.border_color, 0);
}

void 
SensorCard::set_label(const char* label) {
    top_label_p->set_text(label);
}

void 
SensorCard::set_data(const char* text, uint32_t arg) {
    sensor_label_p->set_text(text, arg);
}

void 
SensorCard::set_data_font(const lv_font_t * font) {
    sensor_label_p->set_font(font);
}