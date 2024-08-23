#include "calendar_card.hpp"

CalendarCard::CalendarCard(int x_size, int y_size, int x_offset, int y_offset, lv_obj_t * parrent) {
    calendar = lv_calendar_create(parrent);
    lv_obj_set_size(calendar, x_size, y_size);
    lv_obj_align(calendar, LV_ALIGN_CENTER, 0, 0);    
    lv_obj_align(calendar, LV_ALIGN_TOP_LEFT, x_offset, y_offset);

    lv_calendar_set_today_date(calendar, 2024, 8, 23);
    lv_calendar_set_showed_date(calendar, 2024, 8);
}