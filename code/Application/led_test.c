#include "led_test.h"
#include "board_led.h"

/* 三次短闪（亮 120 ms、灭 180 ms），一次长亮 800 ms，再灭 1500 ms。 */
static const uint16_t durations_ms[] = {120, 180, 120, 180, 120, 180, 800, 1500};
static uint8_t phase;
static uint32_t phase_start_ms;

void LedTest_Init(uint32_t now_ms)
{
    phase = 0;
    phase_start_ms = now_ms;
    BoardLed_Set(1);
}

void LedTest_Update(uint32_t now_ms)
{
    /* 无符号差值允许毫秒计数回绕；主循环不会被长延时阻塞。 */
    if ((uint32_t)(now_ms - phase_start_ms) >= durations_ms[phase])
    {
        phase = (uint8_t)((phase + 1U) % 8U);
        phase_start_ms = now_ms;
        BoardLed_Set((uint8_t)((phase & 1U) == 0U));
    }
}
