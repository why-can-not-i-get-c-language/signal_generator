#include "app.h"
#include "ad9833.h"
#include "board_config.h"
#include "board_led.h"
#include "led_test.h"
#include "stm32f1xx_hal.h"

static SgStatus status = SG_NOT_READY;
static uint32_t start_ms;
static uint8_t output_started;
SgStatus App_Init(void)
{
    BoardLed_Init();
    start_ms = HAL_GetTick();
    LedTest_Init(start_ms);
    output_started = 0U;
    /* 仅初始化短暂等待模块电源稳定。 */
    HAL_Delay(100U);
    status = Ad9833_Init();
    if (status == SG_OK) { status = Ad9833_SetFrequency(0U, BOARD_DDS_TEST_HZ); }
    if (status == SG_OK) { status = Ad9833_SetPhase(0U, 0U); }
    if (status == SG_OK) { status = Ad9833_SetWaveform(SG_SINE); }
    return status;
}
SgStatus App_Update(uint32_t now_ms)
{
    if (status != SG_OK)
    {
        /* 快闪仅报告软件失败，不能判断未连接的器件。 */
        BoardLed_Set((uint8_t)((now_ms / 100U) & 1U));
        return status;
    }
#if BOARD_DDS_BENCH_TEST
    if (output_started == 0U && (uint32_t)(now_ms - start_ms) >= 2000U)
    {
        status = Ad9833_EnableOutput(1U);
        if (status == SG_OK) { output_started = 1U; }
    }
#endif
    LedTest_Update(now_ms);
    return status;
}
