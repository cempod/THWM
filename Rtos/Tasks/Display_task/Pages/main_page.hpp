#pragma once
#include "lvgl.h"

class MainPage
{
private:
    lv_obj_t * screen;
public:
    MainPage(/* args */);
    void load(void);
};
