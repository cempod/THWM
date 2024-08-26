#include "calendar_card.hpp"

static void draw_task_event_cb(lv_event_t * e);
static void remove_events(lv_obj_t * obj);

CalendarCard::CalendarCard(int x_size, int y_size, int x_offset, int y_offset, lv_obj_t * parrent) {
    set_colors(light_theme); 
    calendar = lv_calendar_create(parrent);
    lv_obj_set_size(calendar, x_size, y_size);
    lv_obj_align(calendar, LV_ALIGN_CENTER, 0, 0);    
    lv_obj_align(calendar, LV_ALIGN_TOP_LEFT, x_offset, y_offset);

    lv_calendar_set_today_date(calendar, 2024, 8, 23);
    lv_calendar_set_showed_date(calendar, 2024, 8);
    remove_events(lv_calendar_get_btnmatrix(calendar));
    lv_obj_add_event_cb(lv_calendar_get_btnmatrix(calendar), draw_task_event_cb, LV_EVENT_DRAW_TASK_ADDED, &calendar_theme);
}

static void
remove_events(lv_obj_t * obj) {
    uint32_t i;
    uint32_t event_cnt = lv_obj_get_event_count(obj);
    for (i = 0; i < event_cnt; i++) {
        lv_event_dsc_t * event_dsc = lv_obj_get_event_dsc(obj, i);
        if(lv_event_dsc_get_cb(event_dsc)) {
            //lv_obj_remove_event(obj, i);
            lv_obj_remove_event_cb(obj, lv_event_dsc_get_cb(event_dsc));
            break;
        }
    }
}

static void 
draw_task_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = (lv_obj_t *)lv_event_get_current_target(e);
    lv_draw_task_t * draw_task = (lv_draw_task_t *)lv_event_get_param(e);
    ui_style_t * ui_color = (ui_style_t *)lv_event_get_user_data(e);
    lv_draw_dsc_base_t * base_dsc = (lv_draw_dsc_base_t *)lv_draw_task_get_draw_dsc(draw_task);
    if(base_dsc->part != LV_PART_ITEMS) return;

    lv_draw_fill_dsc_t * fill_draw_dsc = lv_draw_task_get_fill_dsc(draw_task);
    lv_draw_border_dsc_t * border_draw_dsc = lv_draw_task_get_border_dsc(draw_task);
    lv_draw_label_dsc_t * label_draw_dsc = lv_draw_task_get_label_dsc(draw_task);

    if(!fill_draw_dsc && !border_draw_dsc && !label_draw_dsc) {
        return;
    }

    int32_t id = base_dsc->id1;

    /*Day name styles*/
    if(id < 7) {
        if(fill_draw_dsc) fill_draw_dsc->opa = LV_OPA_TRANSP;
        if(border_draw_dsc) border_draw_dsc->opa = LV_OPA_TRANSP;
        if(label_draw_dsc)  label_draw_dsc->opa = LV_OPA_COVER;
        if(label_draw_dsc)  label_draw_dsc->color = ui_color->header_color;
    }
    else if(lv_buttonmatrix_has_button_ctrl(obj, id, LV_BUTTONMATRIX_CTRL_DISABLED)) {
        if(fill_draw_dsc) fill_draw_dsc->opa = LV_OPA_TRANSP;
        if(border_draw_dsc) border_draw_dsc->opa = LV_OPA_TRANSP;
    }

    if(lv_buttonmatrix_has_button_ctrl(obj, id, LV_BUTTONMATRIX_CTRL_CUSTOM_2)) { //highlight
        if(border_draw_dsc) border_draw_dsc->color = lv_theme_get_color_primary(obj);
        if(fill_draw_dsc) fill_draw_dsc->opa = LV_OPA_40;
        if(fill_draw_dsc) fill_draw_dsc->color = lv_theme_get_color_primary(obj);
        if(lv_buttonmatrix_get_selected_button(obj) == (uint32_t)id) {
            if(fill_draw_dsc) fill_draw_dsc->opa = LV_OPA_70;
        }
    }

    if(lv_buttonmatrix_has_button_ctrl(obj, id, LV_BUTTONMATRIX_CTRL_CUSTOM_1)) { //today
        if(border_draw_dsc) border_draw_dsc->opa = LV_OPA_COVER;
        if(border_draw_dsc) border_draw_dsc->color = ui_color->header_color;
        if(label_draw_dsc)  label_draw_dsc->opa = LV_OPA_COVER;
        if(label_draw_dsc)  label_draw_dsc->color = ui_color->header_color;
    }
}

void 
CalendarCard::set_colors(ui_style_t colors) {
    calendar_theme.background_color = colors.background_color;
    calendar_theme.border_color = colors.border_color;
    calendar_theme.card_background_color = colors.card_background_color;
    calendar_theme.header_color = colors.header_color;
    calendar_theme.header_font_color = colors.header_font_color;
    calendar_theme.main_font_color = colors.main_font_color;
}