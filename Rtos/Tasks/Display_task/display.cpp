#include "display.h"
#include "rtos.h"
#include "stm32h7xx_ll_gpio.h"
#include "st7796.h"
#include "main_page.hpp"
#include "stm32h7xx_ll_spi.h"
#include "stm32h7xx_ll_dma.h"
#include "i2c.h"

void my_disp_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * color_p);
lv_display_t *display;

void 
vApplicationTickHook(void) {
    lv_tick_inc(1);
}

static void
touch_read(lv_indev_t * indev, lv_indev_data_t * data) {
    if(i2c_read_byte(0x02) != 0) {
        uint8_t xh = i2c_read_byte(0x03);
        uint8_t xl = i2c_read_byte(0x04);
        uint8_t yh = i2c_read_byte(0x05);
        uint8_t yl = i2c_read_byte(0x06);

        data->point.x = (yh & 0x0F) << 8 | yl;
        data->point.y = 320 - ((xh & 0x0F) << 8 | xl);
        data->state = LV_INDEV_STATE_PRESSED;
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

void
display_task(void* arg) {
    st7796_init();
    lv_init();

    display = lv_display_create(480, 320);
    static lv_color_t buf1[480 * 320 / 7], buf2[480 * 320 / 7];   
    lv_display_set_buffers(display, buf1, buf2, sizeof(buf1),LV_DISP_RENDER_MODE_PARTIAL);
    lv_display_set_flush_cb(display, my_disp_flush);
    lv_indev_t * indev = lv_indev_create();
    lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
    lv_indev_set_read_cb(indev, touch_read);
    MainPage main_page;
    //main_page.set_colors(dark_theme);
    main_page.load();
    xTaskNotify(backlight_task_handle, 100, eSetValueWithOverwrite);
    while (1) {
        lv_timer_handler();
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}

void 
my_disp_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * color_p) {
    st7796_draw_dma(color_p,area->x1,area->y1,area->x2,area->y2);
}


    
#ifdef __cplusplus
extern "C" {
#endif
void DMA1_Stream7_IRQHandler(void)
{
    if(LL_DMA_IsActiveFlag_TC7(DMA1))
    {
        while (!LL_SPI_IsActiveFlag_TXC(SPI1)) {}
        LL_DMA_ClearFlag_TC7(DMA1);
        LL_DMA_DisableStream(DMA1, LL_DMA_STREAM_7);
        LL_SPI_DisableDMAReq_TX(SPI1);
        LL_SPI_ClearFlag_EOT(SPI1);
        LL_SPI_Disable(SPI1);
        lv_display_flush_ready(display);
    }
        else if(LL_DMA_IsActiveFlag_TE7(DMA1))
    {
        while (1) {}
    }
}
#ifdef __cplusplus
}
#endif

