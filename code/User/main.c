#include "stm32f1xx_hal.h"
#include "board_led.h"
#include "led_test.h"

int main(void)
{
    /* 保留复位后的内部 HSI 8 MHz 时钟；HAL 建立 1 ms 时间基准。 */
    HAL_Init();
    BoardLed_Init();
    LedTest_Init(HAL_GetTick());

    while (1)
    {
        LedTest_Update(HAL_GetTick());
    }
}
