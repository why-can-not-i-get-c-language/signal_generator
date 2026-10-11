#include "spi_bus.h"
#include "stm32f1xx_hal.h"
#include "board_config.h"

static uint8_t initialized;
static void HalfClockDelay(void)
{
    /* 保守低速，不宣称精确频率；当前 HSI 8 MHz。 */
    for (volatile uint32_t i = 0; i < 32U; ++i) { __NOP(); }
}
SgStatus SpiBus_Init(void)
{
    GPIO_InitTypeDef gpio = {0};
    __HAL_RCC_GPIOA_CLK_ENABLE();
    HAL_GPIO_WritePin(BOARD_SPI_GPIO, BOARD_SPI_CLK_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(BOARD_SPI_GPIO, BOARD_SPI_DATA_PIN, GPIO_PIN_RESET);
    gpio.Pin = BOARD_SPI_CLK_PIN | BOARD_SPI_DATA_PIN;
    gpio.Mode = GPIO_MODE_OUTPUT_PP;
    gpio.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(BOARD_SPI_GPIO, &gpio);
    initialized = 1U;
    return SG_OK;
}
SgStatus SpiBus_Write(const uint8_t *data, size_t length)
{
    if (data == NULL || length == 0U) { return SG_INVALID_ARGUMENT; }
    if (initialized == 0U) { return SG_NOT_READY; }
    for (size_t i = 0; i < length; ++i)
    {
        for (uint8_t mask = 0x80U; mask != 0U; mask >>= 1)
        {
            HAL_GPIO_WritePin(BOARD_SPI_GPIO, BOARD_SPI_DATA_PIN,
                (data[i] & mask) != 0U ? GPIO_PIN_SET : GPIO_PIN_RESET);
            HalfClockDelay();
            /* 模式 2：时钟闲置高，下降沿采样，高位先发。 */
            HAL_GPIO_WritePin(BOARD_SPI_GPIO, BOARD_SPI_CLK_PIN, GPIO_PIN_RESET);
            HalfClockDelay();
            HAL_GPIO_WritePin(BOARD_SPI_GPIO, BOARD_SPI_CLK_PIN, GPIO_PIN_SET);
        }
    }
    HalfClockDelay();
    return SG_OK;
}
