#include "spi.h"
#include "stm32h7xx_ll_rcc.h"
#include "stm32h7xx_ll_gpio.h"
#include "stm32h7xx_ll_bus.h"
#include "stm32h7xx_ll_spi.h"
#include "stm32h7xx_ll_dma.h"

void
spi_init() {
    LL_SPI_InitTypeDef spi_init = {0};

    LL_GPIO_InitTypeDef gpio_init = {0};

    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_SPI2);

    LL_AHB4_GRP1_EnableClock(LL_AHB4_GRP1_PERIPH_GPIOB);

    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1);
    
    gpio_init.Pin = LL_GPIO_PIN_13 | LL_GPIO_PIN_14 | LL_GPIO_PIN_15;
    gpio_init.Mode = LL_GPIO_MODE_ALTERNATE;
    gpio_init.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
    gpio_init.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    gpio_init.Alternate =  LL_GPIO_AF_5;
    LL_GPIO_Init(GPIOB, &gpio_init);

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

    LL_SPI_Init(SPI2, &spi_init);

    LL_SPI_EnableDMAReq_TX(SPI2);
    NVIC_SetPriority(DMA1_Stream7_IRQn, 5);
    NVIC_EnableIRQ(DMA1_Stream7_IRQn);
}

void
spi_send_byte(uint8_t byte) {
    LL_SPI_SetDataWidth(SPI2,LL_SPI_DATAWIDTH_8BIT);
    LL_SPI_Enable(SPI2);
    while (!LL_SPI_IsActiveFlag_TXP(SPI2)) {}
    LL_SPI_SetTransferSize(SPI2,sizeof(uint8_t));
    LL_SPI_TransmitData8(SPI2, byte);
    LL_SPI_StartMasterTransfer(SPI2);
    while (!LL_SPI_IsActiveFlag_EOT(SPI2)) {}
    LL_SPI_ClearFlag_EOT(SPI2);
    LL_SPI_ClearFlag_TXTF(SPI2);
    LL_SPI_Disable(SPI2);
}

void
spi_send_dma(uint8_t * bytes, uint32_t size) {
    LL_SPI_SetDataWidth(SPI2,LL_SPI_DATAWIDTH_16BIT);
    LL_SPI_SetTransferSize(SPI2,0);
    LL_SPI_EnableDMAReq_TX(SPI2);
    LL_DMA_ConfigTransfer(DMA1,
                        LL_DMA_STREAM_7,
                        LL_DMA_DIRECTION_MEMORY_TO_PERIPH | LL_DMA_PRIORITY_HIGH | LL_DMA_MODE_NORMAL |
                        LL_DMA_PERIPH_NOINCREMENT | LL_DMA_MEMORY_INCREMENT |
                        LL_DMA_PDATAALIGN_HALFWORD | LL_DMA_MDATAALIGN_HALFWORD);
    LL_DMA_ConfigAddresses(DMA1, 
                            LL_DMA_STREAM_7,
                            (uint32_t)bytes, (uint32_t) &(SPI2->TXDR),
                            LL_DMA_GetDataTransferDirection(DMA1, LL_DMA_STREAM_7));

    LL_DMA_SetDataLength(DMA1, LL_DMA_STREAM_7, size/2);
    LL_DMA_SetPeriphRequest(DMA1, LL_DMA_STREAM_7, LL_DMAMUX1_REQ_SPI2_TX);
    LL_SPI_Enable(SPI2);
    while (!LL_SPI_IsActiveFlag_TXP(SPI2)) {}
    LL_DMA_EnableIT_TC(DMA1, LL_DMA_STREAM_7);
    LL_DMA_EnableIT_TE(DMA1, LL_DMA_STREAM_7);
    LL_DMA_EnableStream(DMA1, LL_DMA_STREAM_7);
    LL_SPI_StartMasterTransfer(SPI2);
}

