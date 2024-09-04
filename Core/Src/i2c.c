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

static void
i2c_write_byte(uint8_t byte) {
    while(LL_I2C_IsActiveFlag_BUSY(I2C1)) {}
    LL_I2C_HandleTransfer(I2C1,TOUCH_ADDRESS|I2C_REQUEST_WRITE,LL_I2C_ADDRSLAVE_7BIT,1,LL_I2C_MODE_AUTOEND,LL_I2C_GENERATE_START_WRITE);
    while(!LL_I2C_IsActiveFlag_TXIS) {}
    LL_I2C_TransmitData8(I2C1, byte);
    while(!LL_I2C_IsActiveFlag_TXE(I2C1)){}
    while(!LL_I2C_IsActiveFlag_STOP) {}
    LL_I2C_ClearFlag_STOP(I2C1);
}

uint8_t 
i2c_read_byte(uint16_t addr) {
    i2c_write_byte(addr);
    while(LL_I2C_IsActiveFlag_BUSY(I2C1)) {}
    LL_I2C_HandleTransfer(I2C1,TOUCH_ADDRESS|I2C_REQUEST_READ,LL_I2C_ADDRSLAVE_7BIT,1,LL_I2C_MODE_AUTOEND,LL_I2C_GENERATE_START_READ);
    while(!LL_I2C_IsActiveFlag_RXNE(I2C1)){};
    uint8_t byte = LL_I2C_ReceiveData8(I2C1);
    while(!LL_I2C_IsActiveFlag_STOP) {}
    LL_I2C_ClearFlag_STOP(I2C1);
    return byte;
}