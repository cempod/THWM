#pragma once

#include "main_page.hpp"

enum Pages {
    MAIN_PAGE = 0,
    SETTINGS_PAGE
};

class PageManager {
public:
  static PageManager& get_manager();
  void load_page(int page);
private:
  PageManager();
  MainPage * main_page;
};