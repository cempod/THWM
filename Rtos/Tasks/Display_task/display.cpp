#include "display.h"
#include "rtos.h"
#include "stm32h7xx_ll_gpio.h"
#include "st7796.h"
#include "lvgl/lvgl.h"
#include "main_page.hpp"

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
    __attribute__((section(".DTCMRAM_section"))) static lv_color_t buf1[480 * 320 / 4];               
    lv_display_set_buffers(display, buf1, NULL, sizeof(buf1),LV_DISP_RENDER_MODE_PARTIAL);
    lv_display_set_flush_cb(display, my_disp_flush);

    MainPage main_page;
    main_page.load();

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