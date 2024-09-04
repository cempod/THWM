#include "top_panel.hpp"

TopPanel::TopPanel(int x_size, int y_size, int x_offset, int y_offset, lv_obj_t * parrent) {
    panel = lv_obj_create(parrent);
    lv_obj_align(panel, LV_ALIGN_TOP_LEFT, x_offset, y_offset);
    lv_obj_set_size(panel, x_size, y_size);
    lv_obj_set_style_pad_all(panel,0,0);
    time_label_p = new Label(200,0, &lv_font_montserrat_14, panel);
    header_label_p = new Label(0,0, &lv_font_montserrat_14, panel);
    set_colors(light_theme);
}

void 
TopPanel::set_colors(ui_style_t colors) {
    lv_obj_set_style_bg_color(panel, colors.header_color, 0);
    time_label_p->set_color(colors.header_font_color);
    header_label_p->set_color(colors.header_font_color);
    lv_obj_set_style_border_color(panel, colors.border_color, 0);
}

void 
TopPanel::set_time(uint8_t hour, uint8_t minute) {
    time_label_p->set_text("%02d:%02d",2, 2);
}

void 
TopPanel::set_text(const char* text) {
    header_label_p->set_text(text);
}