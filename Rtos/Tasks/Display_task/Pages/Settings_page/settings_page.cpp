#include "settings_page.hpp"

SettingsPage::SettingsPage() {
    screen = lv_obj_create(NULL);
    ThemeManager theme_manager = ThemeManager::get_manager();
    top_panel_p = new TopPanel(470, 45, 5, 5, screen);
    top_panel_p->set_time(12, 30);
    top_panel_p->set_text("Settings");
    page = lv_obj_create(screen);
    lv_obj_set_size(page, 470, 260);
    lv_obj_align(page, LV_ALIGN_CENTER, 0, 25);
    create_menu();
    set_colors(theme_manager.get_theme(LIGHT_THEME));
}

void
SettingsPage::create_menu() {
    menu = lv_menu_create(page);
    lv_menu_set_mode_root_back_button(menu, LV_MENU_ROOT_BACK_BUTTON_DISABLED);
    lv_obj_set_size(menu, lv_obj_get_content_width(page), lv_obj_get_content_height(page));
    lv_obj_center(menu);
}

void 
SettingsPage::load(void) {
    lv_screen_load(screen);
}

void
SettingsPage::set_colors(ui_style_t colors) {
    lv_obj_set_style_bg_color(screen, colors.background_color, 0);
    lv_obj_set_style_bg_color(page, colors.card_background_color, 0);
    lv_obj_set_style_border_color(page, colors.border_color, 0);
    top_panel_p->set_colors(colors);
}