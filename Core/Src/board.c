#include "board.h"
#include "rcc.h"
#include "gpio.h"
#include "spi.h"
#include "pwm.h"
#include "stm32h7xx_ll_system.h"

void
board_init(void) {

    rcc_init();

    gpio_init();

    spi_init();

    pwm_init();
    
    NVIC_SetPriorityGrouping(3U);
    NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 15, 0));

}