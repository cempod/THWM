#include "settings_page.hpp"

SettingsPage::SettingsPage() {
    screen = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen, light_theme.background_color, 0);
    top_panel_p = new TopPanel(470, 45, 5, 5, screen);
    top_panel_p->set_time(12, 30);
    top_panel_p->set_text("Settings");
}

void 
SettingsPage::load(void) {
    lv_screen_load(screen);
}

void
SettingsPage::set_colors(ui_style_t colors) {
    lv_obj_set_style_bg_color(screen, colors.background_color, 0);
    top_panel_p->set_colors(colors);
}