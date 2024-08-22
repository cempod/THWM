#include "sensor_card.hpp"

SensorCard::SensorCard(int x_offset, int y_offset, lv_obj_t * parrent) {
    card = lv_obj_create(parrent);
    lv_obj_set_style_bg_color (card , lv_palette_darken(LV_PALETTE_GREY,3),0);
    lv_obj_set_style_border_color(card , lv_palette_darken(LV_PALETTE_GREY,2),0);    
    lv_obj_align(card, LV_ALIGN_TOP_LEFT, x_offset, y_offset);
    lv_obj_set_size(card, 145, 145);
    lv_obj_set_style_pad_all(card,0,0);
    header = lv_obj_create(card);
    lv_obj_set_style_bg_color (header , lv_palette_darken(LV_PALETTE_CYAN,4),0);
    lv_obj_set_size(header, 141, 35);
    lv_obj_align(header, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_set_style_border_side(header, LV_BORDER_SIDE_NONE, 0);
    lv_obj_set_style_radius(header, 0, 0);
    lv_obj_set_style_pad_all(header,0,0);
    Label top_label(0,0, &lv_font_montserrat_14, header);
    top_label_p = &top_label;
}