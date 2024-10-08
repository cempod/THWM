#include "top_panel.hpp"

TopPanel::TopPanel(int x_size, int y_size, int x_offset, int y_offset, lv_obj_t * parrent) {
    panel = lv_obj_create(parrent);
    lv_obj_align(panel, LV_ALIGN_TOP_LEFT, x_offset, y_offset);
    lv_obj_set_size(panel, x_size, y_size);
    lv_obj_set_style_pad_all(panel,0,0);
    time_label_p = new Label(200,0, &lv_font_montserrat_14, panel);
    header_label_p = new Label(0,0, &lv_font_montserrat_14, panel);
    ThemeManager theme_manager = ThemeManager::get_manager();
    set_theme(theme_manager.get_theme(LIGHT_THEME));
}

void 
TopPanel::set_theme(ui_style_t theme) {
    lv_obj_set_style_bg_color(panel, theme.header_color, 0);
    time_label_p->set_color(theme.header_font_color);
    header_label_p->set_color(theme.header_font_color);
    header_label_p->set_font(theme.main_font);
    lv_obj_set_style_border_color(panel, theme.border_color, 0);
}

void 
TopPanel::set_time(uint8_t hour, uint8_t minute) {
    time_label_p->set_text("%02d:%02d",hour, minute);
}

void 
TopPanel::set_text(const char* text) {
    header_label_p->set_text(text);
}

lv_obj_t * 
TopPanel::get_event_zone(void) {
    return panel;
}