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
    lv_obj_update_layout(page);
    lv_obj_set_size(menu, lv_obj_get_content_width(page), lv_obj_get_content_height(page));
    lv_obj_center(menu);

    lv_obj_t * root_page;
    lv_obj_t * cont;
    lv_obj_t * section;
    lv_obj_t * label;
    

    lv_obj_t * todo_page = lv_menu_page_create(menu, NULL);
    lv_obj_set_style_pad_hor(todo_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
    lv_menu_separator_create(todo_page);
    label = lv_label_create(todo_page);
    lv_label_set_text(label, "TODO");
    
    root_page = lv_menu_page_create(menu, "Main");
    lv_obj_set_style_pad_hor(root_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
    section = lv_menu_section_create(root_page);
    lv_obj_set_style_border_color(section, LV_COLOR_MAKE(0xF4, 0x43, 0x36), 0);
    lv_obj_set_style_border_width(section,1,0);
    add_page_to_menu(section, NULL, "Display", todo_page);
    add_page_to_menu(section, NULL, "Date & Time", todo_page);
    add_page_to_menu(section, NULL, "TODO", todo_page);

    lv_menu_set_sidebar_page(menu, root_page);
    lv_obj_send_event(lv_obj_get_child(lv_obj_get_child(lv_menu_get_cur_sidebar_page(menu), 0), 0), LV_EVENT_CLICKED, NULL);
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

void
SettingsPage::add_page_to_menu(lv_obj_t * parent, const char * icon, const char * page_name, lv_obj_t * page_content) {
    lv_obj_t * obj = lv_menu_cont_create(parent);

    lv_obj_t * img = NULL;
    lv_obj_t * label = NULL;

    if(icon) {
        img = lv_image_create(obj);
        lv_image_set_src(img, icon);
    }

    if(page_name) {
        label = lv_label_create(obj);
        lv_label_set_text(label, page_name);
        lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_flex_grow(label, 1);
    }

    lv_menu_set_load_page_event(menu, obj, page_content);
}