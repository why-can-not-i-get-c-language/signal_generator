#include "board_led.h"
#include "stm32f1xx_hal.h"

void BoardLed_Init(void)
{
    GPIO_InitTypeDef gpio = {0};

    /* 已存实物照片标注 PC13；低电平点亮方式等待实物测试验证。 */
    __HAL_RCC_GPIOC_CLK_ENABLE();
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
    gpio.Pin = GPIO_PIN_13;
    gpio.Mode = GPIO_MODE_OUTPUT_PP;
    gpio.Pull = GPIO_NOPULL;
    gpio.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOC, &gpio);
}

void BoardLed_Set(uint8_t on)
{
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13,
                      on ? GPIO_PIN_RESET : GPIO_PIN_SET);
}
