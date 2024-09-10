#pragma once

#include "main_page.hpp"
#include "settings_page.hpp"

enum Pages {
    MAIN_PAGE = 0,
    SETTINGS_PAGE
};

class PageManager {
public:
  static PageManager& get_manager();
  void load_page(int page);
  void set_colors(ui_style_t colors);
private:
  PageManager();
  MainPage * main_page;
  SettingsPage * settings_page;
};