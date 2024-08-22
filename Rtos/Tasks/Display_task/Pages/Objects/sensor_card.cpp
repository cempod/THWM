#include "sensor_card.hpp"

SensorCard::SensorCard(lv_obj_t * parrent) {
    card = lv_obj_create(parrent);
    lv_obj_set_size(card, 100, 100);
    Label top_label(0,0, &lv_font_montserrat_14, card);
    top_label_p = &top_label;
}