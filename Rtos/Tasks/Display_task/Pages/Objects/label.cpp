#include "label.hpp"
#include <stdio.h>
#include <stdarg.h>

Label::Label(int x_offset, int y_offset, const lv_font_t * font, lv_obj_t * parrent) {
    label = lv_label_create(parrent);
    lv_label_set_long_mode(label, LV_LABEL_LONG_WRAP);
    set_text("Label");
    lv_obj_set_width(label, LV_SIZE_CONTENT); 
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align(label, LV_ALIGN_CENTER, x_offset, y_offset);
    lv_obj_set_style_text_font(label,font,0);
}

void
Label::set_text(const char* msg, ...) {
    va_list ap;
    va_start(ap, msg);
    vsprintf(str, msg, ap);
    va_end(ap);
    lv_label_set_text(label, str);
}

void 
Label::set_color(lv_color_t color){
    lv_obj_set_style_text_color(label, color, 0);
}

void 
Label::set_font(const lv_font_t * font){
    lv_obj_set_style_text_font(label, font, 0);
}