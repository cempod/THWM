#include "display.h"
#include "rtos.h"
#include "stm32h7xx_ll_gpio.h"
#include "st7796.h"

void 
vApplicationTickHook(void) {

}

void
display_task(void* arg) {
    st7796_init();
    while (1) {
        LL_GPIO_TogglePin(GPIOE, LL_GPIO_PIN_3);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}