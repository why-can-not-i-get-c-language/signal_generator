#include "app.h"
#include "ad9833.h"
#include "board_config.h"
#include "board_led.h"
#include "led_test.h"
#include "stm32f1xx_hal.h"

static SgStatus status = SG_NOT_READY;
static uint32_t start_ms;
static uint8_t output_started;
static uint8_t waveform_index;
static uint32_t waveform_start_ms;
#if BOARD_DDS_BENCH_TEST && BOARD_DDS_CYCLE_WAVEFORMS
static const SgWaveform test_waveforms[] = {SG_SINE, SG_TRIANGLE, SG_SQUARE};
#endif

static void ShowWaveform(uint32_t now_ms)
{
    /* 每两秒一组：正弦闪一次、三角闪两次、方波闪三次。
     * 只表示软件已发送的模式，不代表实物输出已经测量通过。 */
    const uint32_t elapsed = (uint32_t)(now_ms - waveform_start_ms) % 2000U;
    const uint32_t pulses = (uint32_t)waveform_index + 1U;
    BoardLed_Set((uint8_t)(elapsed < pulses * 300U && elapsed % 300U < 120U));
}
SgStatus App_Init(void)
{
    BoardLed_Init();
    start_ms = HAL_GetTick();
    LedTest_Init(start_ms);
    output_started = 0U;
    waveform_index = 0U;
    waveform_start_ms = start_ms;
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
        if (status == SG_OK)
        {
            output_started = 1U;
            waveform_start_ms = now_ms;
        }
    }
#if BOARD_DDS_CYCLE_WAVEFORMS
    if (status == SG_OK && output_started != 0U &&
        (uint32_t)(now_ms - waveform_start_ms) >= BOARD_DDS_WAVE_HOLD_MS)
    {
        const uint8_t next = (uint8_t)((waveform_index + 1U) % 3U);
        status = Ad9833_SetWaveform(test_waveforms[next]);
        if (status == SG_OK)
        {
            waveform_index = next;
            waveform_start_ms = now_ms;
        }
    }
#endif
#endif
    if (status != SG_OK)
    {
        /* 软件故障时尝试复位 DDS，并快闪；复位不是物理断开。 */
        (void)Ad9833_EnableOutput(0U);
        BoardLed_Set((uint8_t)((now_ms / 100U) & 1U));
    }
    else if (output_started != 0U)
    {
        ShowWaveform(now_ms);
    }
    else
    {
        LedTest_Update(now_ms);
    }
    return status;
}
