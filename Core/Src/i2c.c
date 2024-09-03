#include "i2c.h"
#include "stm32h7xx_ll_rcc.h"
#include "stm32h7xx_ll_gpio.h"
#include "stm32h7xx_ll_bus.h"
#include "stm32h7xx_ll_i2c.h"

#define I2C_REQUEST_WRITE                       0x00
#define I2C_REQUEST_READ                        0x01
#define TOUCH_ADDRESS                           0x70

void
i2c_init() {
    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOB);

    LL_GPIO_InitTypeDef gpio_init = {0};

    gpio_init.Pin = LL_GPIO_PIN_6 | LL_GPIO_PIN_7;
    gpio_init.Mode = LL_GPIO_MODE_ALTERNATE;
    gpio_init.Speed = LL_GPIO_SPEED_FREQ_HIGH;
    gpio_init.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    gpio_init.Pull = LL_GPIO_PULL_NO;
    gpio_init.Alternate =  LL_GPIO_AF_4;
    LL_GPIO_Init(GPIOB, &gpio_init);

    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_I2C1);

    LL_RCC_SetI2CClockSource(LL_RCC_I2C1235_CLKSOURCE_PCLK1);

    LL_I2C_InitTypeDef i2c_init = {0};

    i2c_init.PeripheralMode  = LL_I2C_MODE_I2C;
    i2c_init.Timing          = 0x60404E72; //Steal from cube
    i2c_init.AnalogFilter    = LL_I2C_ANALOGFILTER_ENABLE;
    i2c_init.DigitalFilter   = 0x00;
    i2c_init.OwnAddress1     = 0x00;
    i2c_init.TypeAcknowledge = LL_I2C_ACK;
    i2c_init.OwnAddrSize     = LL_I2C_OWNADDRESS1_7BIT;

    LL_I2C_Init(I2C1, &i2c_init);
}

void
i2c_write(uint16_t addr,uint8_t *buf, uint16_t bytes_count) {
    //TODO   
}

void
i2c_read(uint16_t addr, uint8_t *buf, uint16_t bytes_count) {
    //TODO    
}