#include "pwm.h"
#include "gpio.h"
#include "stm32h7xx_ll_bus.h"
#include "stm32h7xx_ll_tim.h"

void
pwm_init(void) {
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOA);

    LL_GPIO_InitTypeDef gpio_init = {0};

    gpio_init.Pin = BLK_Pin;
    gpio_init.Mode = LL_GPIO_MODE_ALTERNATE;
    gpio_init.Speed = LL_GPIO_SPEED_FREQ_HIGH;
    gpio_init.OutputType = LL_GPIO_PULL_NO;
    gpio_init.Alternate =  LL_GPIO_AF_2;
    LL_GPIO_Init(BLK_GPIO_Port, &gpio_init);

    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM5); 

    LL_TIM_SetPrescaler(TIM5, 27500-1);
                                            
    LL_TIM_EnableARRPreload(TIM5);

    LL_TIM_SetAutoReload(TIM5, 100-1);

    LL_TIM_OC_SetMode(TIM5, LL_TIM_CHANNEL_CH2, LL_TIM_OCMODE_PWM1);
  
    LL_TIM_OC_SetCompareCH2(TIM5, 0);
  
    LL_TIM_OC_EnablePreload(TIM5, LL_TIM_CHANNEL_CH2);
  
    LL_TIM_CC_EnableChannel(TIM5, LL_TIM_CHANNEL_CH2);
    
    LL_TIM_EnableCounter(TIM5);

    LL_TIM_GenerateEvent_UPDATE(TIM5);
}

void
set_pwm(uint8_t pwm) {
    LL_TIM_OC_SetCompareCH2(TIM5, pwm < 100 ? pwm : 100);
}