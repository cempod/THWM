#include "sensor_card.hpp"

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
    set_colors(light_theme);
}

void 
SensorCard::set_colors(ui_style_t colors) {
    lv_obj_set_style_bg_color(card, colors.card_background_color, 0);
    lv_obj_set_style_bg_color (header , colors.header_color, 0);
    top_label_p->set_color(colors.header_font_color);
}

void 
SensorCard::set_label(const char* label) {
    top_label_p->set_text(label);
}