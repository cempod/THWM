#pragma once

#include "lvgl/lvgl.h"

enum Themes {
    LIGHT_THEME = 0,
    DARK_THEME,
    CUSTOM_THEME //TODO
};

typedef struct {
    lv_color_t background_color;
    lv_color_t card_background_color;
    lv_color_t header_color;
    lv_color_t main_font_color;
    lv_color_t header_font_color;
    lv_color_t border_color;
    const lv_font_t * main_font;
    const lv_font_t * small_font;
} ui_style_t;

class ThemeManager {
public:
    static ThemeManager& get_manager();
    ui_style_t get_theme(int theme);
private:
    ui_style_t light_theme;
    ui_style_t dark_theme;
    ThemeManager();
};