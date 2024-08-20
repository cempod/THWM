#include "spi.h"
#include "stm32h7xx_ll_rcc.h"
#include "stm32h7xx_ll_gpio.h"
#include "stm32h7xx_ll_bus.h"
#include "stm32h7xx_ll_spi.h"

void
spi_init() {
    LL_SPI_InitTypeDef spi_init = {0};

    LL_GPIO_InitTypeDef gpio_init = {0};

    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI1);

    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOA);
    
    gpio_init.Pin = LL_GPIO_PIN_5 | LL_GPIO_PIN_6 | LL_GPIO_PIN_7;
    gpio_init.Mode = LL_GPIO_MODE_ALTERNATE;
    gpio_init.Speed = LL_GPIO_SPEED_HIGH;
    gpio_init.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    gpio_init.Alternate =  LL_GPIO_AF_5;
    LL_GPIO_Init(GPIOA, &gpio_init);

    spi_init.TransferDirection = LL_SPI_FULL_DUPLEX;
    spi_init.Mode = LL_SPI_MODE_MASTER;
    spi_init.DataWidth = LL_SPI_DATAWIDTH_8BIT;
    spi_init.ClockPolarity = LL_SPI_POLARITY_LOW;
    spi_init.ClockPhase = LL_SPI_PHASE_1EDGE;
    spi_init.NSS = LL_SPI_NSS_SOFT;
    spi_init.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV4;
    spi_init.BitOrder = LL_SPI_MSB_FIRST;
    spi_init.CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE;
    spi_init.CRCPoly = 10;

    LL_SPI_Init(SPI1, &spi_init);

    LL_SPI_Enable(SPI1);
    
}

void
spi_send_byte(uint8_t byte) {
    LL_SPI_Enable(SPI1);
    while (!LL_SPI_IsActiveFlag_TXP(SPI1)) {}
    LL_SPI_SetTransferSize(SPI1,sizeof(uint8_t));
    LL_SPI_TransmitData8(SPI1, byte);
    LL_SPI_StartMasterTransfer(SPI1);
    while (!LL_SPI_IsActiveFlag_EOT(SPI1)) {}
    LL_SPI_ClearFlag_EOT(SPI1);
    LL_SPI_ClearFlag_TXTF(SPI1);
    LL_SPI_Disable(SPI1);
}