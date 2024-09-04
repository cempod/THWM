#include "page_manager.hpp"

PageManager::PageManager(){
    main_page = new(MainPage);
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
    
    default:
        break;
    }
}