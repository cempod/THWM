#include "settings_page.hpp"
#include "rtos.h"

SettingsPage::SettingsPage() {
    screen = lv_obj_create(NULL);
    ThemeManager theme_manager = ThemeManager::get_manager();
    top_panel_p = new TopPanel(470, 40, 5, 5, screen);
    top_panel_p->set_time(12, 30);
    top_panel_p->set_text("Настройки");
    page = lv_obj_create(screen);
    lv_obj_set_style_pad_all(page,0,0);
    lv_obj_set_size(page, 470, 260);
    lv_obj_align(page, LV_ALIGN_CENTER, 0, 25);
    create_menu();
    set_theme(theme_manager.get_theme(LIGHT_THEME));
}

void
SettingsPage::create_menu() {
    menu = lv_menu_create(page);
    lv_menu_set_mode_root_back_button(menu, LV_MENU_ROOT_BACK_BUTTON_DISABLED);
    lv_obj_update_layout(page);
    lv_obj_set_size(menu, lv_obj_get_content_width(page), lv_obj_get_content_height(page));
    lv_obj_center(menu);    

    
    
    menu_root_page = lv_menu_page_create(menu, "Главное");
    lv_obj_set_style_pad_hor(menu_root_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
    menu_main_section = lv_menu_section_create(menu_root_page);
    lv_obj_set_style_border_width(menu_main_section, 1, 0);
    display_sub_page_p = new DisplaySubPage(menu);
    about_sub_page_p = new AboutSubPage(menu);
    add_page_to_menu(menu_main_section, NULL, "Экран", display_sub_page_p->page);
    add_page_to_menu(menu_main_section, NULL, "Дата и время", display_sub_page_p->page);
    add_page_to_menu(menu_main_section, NULL, "TODO", display_sub_page_p->page);

    lv_obj_t * obj = lv_menu_cont_create(menu_root_page);
    lv_obj_set_style_pad_hor(obj, 0, 0);
    other_section_label = lv_label_create(obj);
    lv_label_set_text(other_section_label, "Прочее");
    lv_label_set_long_mode(other_section_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_flex_grow(other_section_label, 1);

    menu_other_section = lv_menu_section_create(menu_root_page);
    lv_obj_set_style_border_width(menu_other_section, 1, 0);
    add_page_to_menu(menu_other_section, NULL, "Об устройстве", about_sub_page_p->page);

    lv_menu_set_sidebar_page(menu, menu_root_page);
    lv_obj_send_event(lv_obj_get_child(lv_obj_get_child(lv_menu_get_cur_sidebar_page(menu), 0), 0), LV_EVENT_CLICKED, NULL);
}

void 
SettingsPage::load(void) {
    lv_screen_load(screen);
}

void
SettingsPage::set_theme(ui_style_t theme) {
    lv_obj_set_style_border_color(menu_main_section, theme.border_color, 0);
    lv_obj_set_style_border_color(menu_other_section, theme.border_color, 0);
    lv_obj_set_style_bg_color(screen, theme.background_color, 0);
    lv_obj_set_style_bg_color(page, theme.card_background_color, 0);
    lv_obj_set_style_bg_color(menu, theme.card_background_color, 0);
    lv_obj_set_style_bg_color(menu_main_section, theme.card_background_color, 0);
    lv_obj_set_style_bg_color(menu_other_section, theme.card_background_color, 0);
    lv_obj_set_style_border_color(page, theme.border_color, 0);
    lv_obj_set_style_text_color(menu, theme.main_font_color, LV_PART_MAIN);
    lv_obj_set_style_text_font(menu, theme.main_font, 0);
    for (int i = 0; i < lv_obj_get_child_count(menu_main_section); i++)
    {
        lv_obj_set_style_text_color(lv_obj_get_child(menu_main_section, i), theme.main_font_color, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(lv_obj_get_child(menu_main_section, i), theme.header_font_color, LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_text_color(lv_obj_get_child(menu_main_section, i), theme.header_font_color, LV_STATE_PRESSED | LV_STATE_FOCUSED);
        lv_obj_set_style_bg_color(lv_obj_get_child(menu_main_section, i), theme.header_color, LV_PART_MAIN | LV_STATE_FOCUSED);
        lv_obj_set_style_bg_color(lv_obj_get_child(menu_main_section, i), theme.header_color, LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_bg_color(lv_obj_get_child(menu_main_section, i), theme.header_color, LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_bg_color(lv_obj_get_child(menu_main_section, i), theme.header_color, LV_PART_MAIN | LV_STATE_PRESSED | LV_STATE_FOCUSED);
        lv_obj_set_style_bg_opa(lv_obj_get_child(menu_main_section, i), LV_OPA_20, LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_bg_opa(lv_obj_get_child(menu_main_section, i), LV_OPA_80, LV_PART_MAIN | LV_STATE_PRESSED | LV_STATE_FOCUSED);
        lv_obj_set_style_bg_opa(lv_obj_get_child(menu_main_section, i), LV_OPA_100, LV_PART_MAIN | LV_STATE_CHECKED);
    }
    for (int i = 0; i < lv_obj_get_child_count(menu_other_section); i++)
    {
        lv_obj_set_style_text_color(lv_obj_get_child(menu_other_section, i), theme.main_font_color, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(lv_obj_get_child(menu_other_section, i), theme.header_font_color, LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_text_color(lv_obj_get_child(menu_other_section, i), theme.header_font_color, LV_STATE_PRESSED | LV_STATE_FOCUSED);
        lv_obj_set_style_bg_color(lv_obj_get_child(menu_other_section, i), theme.header_color, LV_PART_MAIN | LV_STATE_FOCUSED);
        lv_obj_set_style_bg_color(lv_obj_get_child(menu_other_section, i), theme.header_color, LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_bg_color(lv_obj_get_child(menu_other_section, i), theme.header_color, LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_bg_color(lv_obj_get_child(menu_other_section, i), theme.header_color, LV_PART_MAIN | LV_STATE_PRESSED | LV_STATE_FOCUSED);
        lv_obj_set_style_bg_opa(lv_obj_get_child(menu_other_section, i), LV_OPA_20, LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_bg_opa(lv_obj_get_child(menu_other_section, i), LV_OPA_80, LV_PART_MAIN | LV_STATE_PRESSED | LV_STATE_FOCUSED);
        lv_obj_set_style_bg_opa(lv_obj_get_child(menu_other_section, i), LV_OPA_100, LV_PART_MAIN | LV_STATE_CHECKED);
    }
    
    top_panel_p->set_theme(theme);
    display_sub_page_p->set_theme(theme);
    about_sub_page_p->set_theme(theme);
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