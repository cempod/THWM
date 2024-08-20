#ifndef __PWM_H
#define __PWM_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>

void pwm_init(void);
void set_pwm(uint8_t pwm);

#ifdef __cplusplus
}
#endif

#endif