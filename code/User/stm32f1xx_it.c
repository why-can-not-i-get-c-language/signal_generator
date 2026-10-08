#include "stm32f1xx_hal.h"

void SysTick_Handler(void)
{
    HAL_IncTick();
}

void HardFault_Handler(void)
{
    /* 故障时停住，供调试器检查；不能视为 LED 测试通过。 */
    while (1) { }
}
