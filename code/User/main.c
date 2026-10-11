#include "stm32f1xx_hal.h"
#include "app.h"
int main(void)
{
    /* 保留 HSI 8 MHz；HAL 提供 1 ms 时间基准。 */
    HAL_Init();
    (void)App_Init();
    while (1) { (void)App_Update(HAL_GetTick()); }
}
