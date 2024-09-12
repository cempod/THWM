#include "theme_manager.hpp"

ThemeManager::ThemeManager(){
    LV_FONT_DECLARE(open_sans_18);
    LV_FONT_DECLARE(comfortaa_12);
    LV_FONT_DECLARE(comfortaa_16);

    light_theme = {
        .background_color = LV_COLOR_MAKE(0xFF, 0xFF, 0xFF),
        .card_background_color = LV_COLOR_MAKE(0xFF, 0xFF, 0xFF),
        .header_color = LV_COLOR_MAKE(0xF4, 0x43, 0x36),
        .main_font_color = LV_COLOR_MAKE(0xF4, 0x43, 0x36),
        .header_font_color = LV_COLOR_MAKE(0xFF, 0xFF, 0xFF),
        .border_color = LV_COLOR_MAKE(0xF4, 0x43, 0x36),
        .main_font = &comfortaa_16,
        .small_font = &comfortaa_12
    };

    dark_theme = {
        .background_color = LV_COLOR_MAKE(0x28, 0x2C, 0x34),
        .card_background_color = LV_COLOR_MAKE(0x28, 0x2C, 0x34),
        .header_color = LV_COLOR_MAKE(0xF4, 0x43, 0x36),
        .main_font_color = LV_COLOR_MAKE(0xF4, 0x43, 0x36),
        .header_font_color = LV_COLOR_MAKE(0xFF, 0xFF, 0xFF),
        .border_color = LV_COLOR_MAKE(0xF4, 0x43, 0x36),
        .main_font = &comfortaa_16,
        .small_font = &comfortaa_12
    };
}

ThemeManager& 
ThemeManager::get_manager() {
  static ThemeManager manager;
  return manager;
}

ui_style_t 
ThemeManager::get_theme(int theme) {
    switch (theme)
    {
    case LIGHT_THEME:
        return light_theme;

    case DARK_THEME:
        return dark_theme;
    
    default:
        return light_theme;
    }
}