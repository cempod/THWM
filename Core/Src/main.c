#include "board.h"
#include "stm32h7xx_ll_gpio.h"
#include "stm32h7xx_ll_bus.h"
#include "stm32h7xx_ll_utils.h"

int 
main(void) {
  board_init();
  
  /*for test*/
  LL_GPIO_InitTypeDef gpio_init = {0};
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOE);
    gpio_init.Pin = LL_GPIO_PIN_3;
    gpio_init.Mode = LL_GPIO_MODE_OUTPUT;
    gpio_init.Speed = LL_GPIO_SPEED_FREQ_HIGH;
    gpio_init.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    gpio_init.Alternate =  LL_GPIO_AF_0;
    LL_GPIO_Init(GPIOE, &gpio_init);
  while (1) {
    LL_GPIO_TogglePin(GPIOE, LL_GPIO_PIN_3);
    LL_mDelay(500);
  }
  
}

void SVC_Handler(){}
void PendSV_Handler(){}
void SysTick_Handler(){}