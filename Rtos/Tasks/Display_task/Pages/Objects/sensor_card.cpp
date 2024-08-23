#include "sensor_card.hpp"

SensorCard::SensorCard(int x_size, int y_size, int x_offset, int y_offset, lv_obj_t * parrent) {
    card = lv_obj_create(parrent);
    lv_obj_align(card, LV_ALIGN_TOP_LEFT, x_offset, y_offset);
    lv_obj_set_size(card, x_size, y_size);
    lv_obj_set_style_pad_all(card,0,0);
    header = lv_obj_create(card);
    lv_obj_set_size(header, 146, 35);
    lv_obj_align(header, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_set_style_border_side(header, LV_BORDER_SIDE_NONE, 0);
    lv_obj_set_style_radius(header, 0, 0);
    lv_obj_set_style_pad_all(header,0,0);
    Label top_label(0,0, &lv_font_montserrat_14, header);
    top_label_p = &top_label;
    set_colors(light_theme);
}

void 
SensorCard::set_colors(ui_style_t colors) {
    lv_obj_set_style_bg_color(card, colors.card_background_color, 0);
    lv_obj_set_style_bg_color (header , colors.header_color, 0);
}