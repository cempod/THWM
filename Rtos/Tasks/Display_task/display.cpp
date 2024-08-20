#include "display.h"
#include "rtos.h"
#include "stm32h7xx_ll_gpio.h"
#include "st7796.h"
#include "lvgl/lvgl.h"

void my_disp_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * color_p);

void 
vApplicationTickHook(void) {
    lv_tick_inc(1);
}

void
display_task(void* arg) {
    st7796_init();
    lv_init();

    lv_display_t *display = lv_display_create(480, 320);
    static lv_color_t buf1[480 * 320 / 10];                      /*Declare a buffer for 1/10 screen size*/
    lv_display_set_buffers(display, buf1, NULL, sizeof(buf1),LV_DISP_RENDER_MODE_PARTIAL);  /*Initialize the display buffer.*/
    lv_display_set_flush_cb(display, my_disp_flush);

    lv_obj_set_style_bg_color ( lv_screen_active() , lv_palette_darken(LV_PALETTE_GREY,4),0) ;
    lv_obj_set_scrollbar_mode(lv_screen_active(), LV_SCROLLBAR_MODE_OFF);

    xTaskNotify(backlight_task_handle, 100, eSetValueWithOverwrite);
    while (1) {
        taskENTER_CRITICAL();
        lv_timer_handler();
        taskEXIT_CRITICAL();
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}

void 
my_disp_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * color_p) {
    st7796_draw(color_p,area->x1,area->y1,area->x2,area->y2);
    lv_display_flush_ready(disp); 
}