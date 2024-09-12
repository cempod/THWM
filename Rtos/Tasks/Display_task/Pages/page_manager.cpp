#include "page_manager.hpp"

PageManager::PageManager(){
    main_page = new(MainPage);
    settings_page = new(SettingsPage);
}

PageManager& 
PageManager::get_manager() {
  static PageManager manager;
  return manager;
}

void
PageManager::load_page(int page) {
    switch (page)
    {
    case MAIN_PAGE: {
            main_page->load();
            break;
        }

    case SETTINGS_PAGE: {
            settings_page->load();
            break;
        }
    
    default:
        break;
    }
}

void
PageManager::set_theme(ui_style_t theme) {
    main_page->set_theme(theme);
    settings_page->set_theme(theme);
}