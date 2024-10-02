#include "board.h"
#include "rcc.h"
#include "gpio.h"
#include "spi.h"
#include "i2c.h"
#include "pwm.h"
#include "stm32h7xx_ll_system.h"
#include "rtc.h"
#include "stm32h7xx_ll_rtc.h"
#include "stm32h7xx_ll_rcc.h"

void
board_init(void) {

    rcc_init();

    gpio_init();

    spi_init();

    i2c_init();

    pwm_init();

    if (LL_RCC_LSE_IsReady() == 0) {
        rtc_init(00, 00, 00);
    }
    
    NVIC_SetPriorityGrouping(3U);
    NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 15, 0));

}