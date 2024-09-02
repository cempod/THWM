#ifndef __GPIO_H
#define __GPIO_H

#ifdef __cplusplus
extern "C" {
#endif
#include "stm32h7xx_ll_gpio.h"

#define LED_Pin                 LL_GPIO_PIN_3
#define LED_GPIO_Port           GPIOE
#define RST_Pin                 LL_GPIO_PIN_3
#define RST_GPIO_Port           GPIOA
#define DC_Pin                  LL_GPIO_PIN_2
#define DC_GPIO_Port            GPIOA
#define CS_Pin                  LL_GPIO_PIN_4
#define CS_GPIO_Port            GPIOA
#define BLK_Pin                 LL_GPIO_PIN_1
#define BLK_GPIO_Port           GPIOA
#define TRST_Pin                LL_GPIO_PIN_5
#define TRST_GPIO_Port           GPIOB

void gpio_init(void);

#ifdef __cplusplus
}
#endif

#endif
