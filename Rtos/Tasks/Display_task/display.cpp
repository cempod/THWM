#include "display.h"
#include "rtos.h"
#include "stm32h7xx_ll_gpio.h"
#include "st7796.h"
#include "main_page.hpp"
#include "stm32h7xx_ll_spi.h"
#include "stm32h7xx_ll_dma.h"

void my_disp_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * color_p);
lv_display_t *display;
void 
vApplicationTickHook(void) {
    lv_tick_inc(1);
}

void
display_task(void* arg) {
    st7796_init();
    lv_init();

    display = lv_display_create(480, 320);
    /*__attribute__((section(".DTCMRAM_section"))) */static lv_color_t buf1[480 * 320 / 30];   
    lv_display_set_buffers(display, buf1, NULL, sizeof(buf1),LV_DISP_RENDER_MODE_PARTIAL);
    lv_display_set_flush_cb(display, my_disp_flush);
    MainPage main_page;
    //main_page.set_colors(dark_theme);
    main_page.load();
    xTaskNotify(backlight_task_handle, 100, eSetValueWithOverwrite);
    while (1) {
        //taskENTER_CRITICAL();
        lv_timer_handler();
        //taskEXIT_CRITICAL();
        vTaskDelay(pdMS_TO_TICKS(5));
    }
}

void 
my_disp_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * color_p) {
    st7796_draw_dma(color_p,area->x1,area->y1,area->x2,area->y2);
    //st7796_draw(color_p,area->x1,area->y1,area->x2,area->y2);
    //lv_display_flush_ready(disp); 
}


    
#ifdef __cplusplus
extern "C" {
#endif
void DMA1_Stream7_IRQHandler(void)
{

    if(LL_DMA_IsActiveFlag_TC7(DMA1))
    {
        LL_DMA_ClearFlag_TC7(DMA1);
        LL_DMA_DisableStream(DMA1, LL_DMA_STREAM_7);
        LL_SPI_DisableDMAReq_TX(SPI1);
        LL_SPI_ClearFlag_EOT(SPI1);
        LL_SPI_SuspendMasterTransfer(SPI1);
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

