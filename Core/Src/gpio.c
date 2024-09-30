#include "gpio.h"
#include "stm32h7xx_ll_bus.h"
#include "stm32h7xx_ll_utils.h"

void
gpio_init(void) {
    LL_GPIO_InitTypeDef gpio_init = {0};
    
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOE);
    gpio_init.Pin = LED_Pin;
    gpio_init.Mode = LL_GPIO_MODE_OUTPUT;
    gpio_init.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    gpio_init.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    gpio_init.Alternate =  LL_GPIO_AF_0;
    LL_GPIO_Init(LED_GPIO_Port, &gpio_init);

    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOA);
    gpio_init.Pin = RST_Pin | DC_Pin;
    LL_GPIO_Init(GPIOA, &gpio_init);

    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOB);
    gpio_init.Pin = TRST_Pin| CS_Pin;
    LL_GPIO_Init(GPIOB, &gpio_init);

    LL_GPIO_SetOutputPin(TRST_GPIO_Port, TRST_Pin);
}