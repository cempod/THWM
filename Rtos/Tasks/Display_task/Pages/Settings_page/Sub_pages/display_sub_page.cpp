#include "display_sub_page.hpp"
#include "rtos.h"

DisplaySubPage::DisplaySubPage(lv_obj_t * menu) {
    page = lv_menu_page_create(menu, NULL);
    lv_obj_set_style_pad_hor(page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
    lv_menu_separator_create(page);
    lv_obj_set_style_pad_all(page,0,0);
    brightness_card = lv_obj_create(page);
    lv_obj_set_style_clip_corner(brightness_card, true, 0);
    lv_obj_align(brightness_card, LV_ALIGN_TOP_MID, 0, 5);
    lv_obj_set_size(brightness_card, 310, 100);
    lv_obj_set_style_pad_all(brightness_card,0,0);
    lv_obj_set_style_border_width(brightness_card, 1, 0);
    brightness_card_header = lv_obj_create(brightness_card);
    lv_obj_set_size(brightness_card_header, 310-2, 35);
    lv_obj_align(brightness_card_header, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_set_style_border_side(brightness_card_header, LV_BORDER_SIDE_NONE, 0);
    lv_obj_set_style_radius(brightness_card_header, 0, 0);
    lv_obj_set_style_pad_all(brightness_card_header,0,0);
    brightness_label_p = new Label(0,0, &lv_font_montserrat_14, brightness_card_header);
    brightness_label_p->set_text("Яркость");
    brightness_slider = lv_slider_create(brightness_card);
    lv_slider_set_range(brightness_slider, 30, 100);
    lv_slider_set_value(brightness_slider, 100, LV_ANIM_OFF);//todo: get current from memory
    lv_obj_align(brightness_slider, LV_ALIGN_CENTER, 0, 17);
    lv_obj_add_event_cb(brightness_slider, brightness_slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
}

void
DisplaySubPage::set_theme(ui_style_t theme) {
    lv_obj_set_style_bg_color(page, theme.background_color, 0);
    lv_obj_set_style_bg_color(brightness_card, theme.card_background_color, 0);
    lv_obj_set_style_border_color(brightness_card, theme.border_color, 0);
    lv_obj_set_style_bg_color(brightness_card_header, theme.header_color, 0);
    brightness_label_p->set_font(theme.main_font);
    brightness_label_p->set_color(theme.header_font_color);
    lv_obj_set_style_bg_color(brightness_slider, theme.header_color, LV_PART_MAIN);
    lv_obj_set_style_bg_color(brightness_slider, theme.header_color, LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(brightness_slider, theme.header_color, LV_PART_KNOB);
}

void 
DisplaySubPage::brightness_slider_event_cb(lv_event_t * e)
{
    lv_obj_t * brightness_slider = (lv_obj_t *)lv_event_get_target(e);
    xTaskNotify(backlight_task_handle, lv_slider_get_value(brightness_slider), eSetValueWithOverwrite);
}