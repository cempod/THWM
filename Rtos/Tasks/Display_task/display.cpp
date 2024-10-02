#include "display.h"
#include "rtos.h"
#include "stm32h7xx_ll_gpio.h"
#include "st7796.h"
#include "page_manager.hpp"
#include "stm32h7xx_ll_spi.h"
#include "stm32h7xx_ll_dma.h"
#include "i2c.h"
#include "gpio.h"

void display_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * color_p);

void 
vApplicationTickHook(void) {
    lv_tick_inc(1);
}

static void
touch_read(lv_indev_t * indev, lv_indev_data_t * data) {
    uint8_t touch, xh, xl, yh, yl;
    data->state = LV_INDEV_STATE_RELEASED;

    if(i2c_read_byte(0x02, &touch) == I2C_OK) {
        if(touch != 0) {
            if((i2c_read_byte(0x03, &xh) == I2C_OK) && (i2c_read_byte(0x04, &xl) == I2C_OK) && (i2c_read_byte(0x05, &yh) == I2C_OK) && (i2c_read_byte(0x06, &yl) == I2C_OK)) {
                data->point.x = (yh & 0x0F) << 8 | yl;
                data->point.y = 320 - ((xh & 0x0F) << 8 | xl);
                data->state = LV_INDEV_STATE_PRESSED;
            }
        }
    }
}

void
display_task(void* arg) {
    st7796_init();
    lv_init();

    lv_display_t *display = lv_display_create(480, 320);
    static lv_color_t buf1[480 * 320 / 7], buf2[480 * 320 / 7];   
    lv_display_set_buffers(display, buf1, buf2, sizeof(buf1),LV_DISP_RENDER_MODE_PARTIAL);
    lv_display_set_flush_cb(display, display_flush);
    lv_indev_t * indev = lv_indev_create();
    lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
    lv_indev_set_read_cb(indev, touch_read);
    
    PageManager page_manager = PageManager::get_manager();
    ThemeManager theme_manager = ThemeManager::get_manager();
    page_manager.load_page(MAIN_PAGE);
    //page_manager.set_theme(theme_manager.get_theme(DARK_THEME));    //example

    xTaskNotify(backlight_task_handle, 100, eSetValueWithOverwrite);
    while (1) {
        lv_timer_handler();
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}

void 
display_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * color_p) {
    st7796_draw_dma(color_p,area->x1,area->y1,area->x2,area->y2);
}


    
#ifdef __cplusplus
extern "C" {
#endif

void 
DMA1_Stream7_IRQHandler(void) {
    if(LL_DMA_IsActiveFlag_TC7(DMA1)) {
        while (!LL_SPI_IsActiveFlag_TXC(SPI2)) {}
        LL_DMA_ClearFlag_TC7(DMA1);
        LL_DMA_DisableStream(DMA1, LL_DMA_STREAM_7);
        LL_SPI_DisableDMAReq_TX(SPI2);
        LL_SPI_ClearFlag_EOT(SPI2);
        LL_SPI_Disable(SPI2);
        LL_GPIO_SetOutputPin(CS_GPIO_Port, CS_Pin);
        lv_display_flush_ready(lv_display_get_default());
    } else if(LL_DMA_IsActiveFlag_TE7(DMA1)) {
        while (1) {}
    }
}

#ifdef __cplusplus
}
#endif