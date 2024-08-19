#include "board.h"
#include "rcc.h"
#include "stm32h7xx_ll_system.h"

void
board_init(void) {

    rcc_init();
    
    NVIC_SetPriorityGrouping(3U);
    NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 15, 0));

}