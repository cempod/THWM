#include "about_sub_page.hpp"

AboutSubPage::AboutSubPage(lv_obj_t * menu) {
    page = lv_menu_page_create(menu, NULL);
    lv_obj_set_style_pad_hor(page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
    lv_menu_separator_create(page);
    lv_obj_set_style_pad_all(page,0,0);

    about_label = lv_label_create(page);
    lv_obj_set_size(about_label, 310, 245);
     lv_obj_set_style_text_align(about_label, LV_TEXT_ALIGN_AUTO, 0);
    lv_label_set_text(about_label, "THWM - Touch Home Weather Station. \nМетеостанция домашняя. \nИзмеряет температуру и влажность воздуха, атмосферное давление и концентрацию углекислого газа в помещении. \n\nСсылка на проект:\ngithub.com/cempod/THWM");
}

void
AboutSubPage::set_theme(ui_style_t theme) {
    lv_obj_set_style_bg_color(page, theme.background_color, 0);
    lv_obj_set_style_text_font(about_label, theme.main_font, 0);
    lv_obj_set_style_text_color(about_label, theme.main_font_color, 0);
}