#include "ad9833.h"
#include "spi_bus.h"
#include "stm32f1xx_hal.h"
#include "board_config.h"

#define DDS_B28 0x2000U
#define DDS_RESET 0x0100U
#define DDS_WAVE_MASK 0x002AU
static uint16_t control;
static uint8_t initialized;
static uint32_t frequency[2];

static SgStatus WriteWord(uint16_t word)
{
    const uint8_t bytes[2] = {(uint8_t)(word >> 8), (uint8_t)word};
    HAL_GPIO_WritePin(BOARD_SPI_GPIO, BOARD_DDS_FSYNC_PIN, GPIO_PIN_RESET);
    SgStatus result = SpiBus_Write(bytes, sizeof(bytes));
    HAL_GPIO_WritePin(BOARD_SPI_GPIO, BOARD_DDS_FSYNC_PIN, GPIO_PIN_SET);
    return result;
}
SgStatus Ad9833_Init(void)
{
    GPIO_InitTypeDef gpio = {0};
    initialized = 0U;
    frequency[0] = frequency[1] = 0U;
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /* FSY 属于 DDS；CS 属于电位器，本阶段 CS 始终保持高。 */
    HAL_GPIO_WritePin(BOARD_SPI_GPIO, BOARD_DDS_FSYNC_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(BOARD_POT_GPIO, BOARD_POT_CS_PIN, GPIO_PIN_SET);
    gpio.Mode = GPIO_MODE_OUTPUT_PP;
    gpio.Speed = GPIO_SPEED_FREQ_LOW;
    gpio.Pin = BOARD_DDS_FSYNC_PIN;
    HAL_GPIO_Init(BOARD_SPI_GPIO, &gpio);
    gpio.Pin = BOARD_POT_CS_PIN;
    HAL_GPIO_Init(BOARD_POT_GPIO, &gpio);
    SgStatus result = SpiBus_Init();
    if (result != SG_OK) { return result; }
    control = DDS_B28 | DDS_RESET;
    /* RESET 不清空频率/相位寄存器，须全部写入已知值。 */
    const uint16_t words[] = {control, 0x4000U, 0x4000U,
        0x8000U, 0x8000U, 0xC000U, 0xE000U};
    for (size_t i = 0; i < sizeof(words) / sizeof(words[0]); ++i)
    {
        result = WriteWord(words[i]);
        if (result != SG_OK) { return result; }
    }
    initialized = 1U;
    return SG_OK;
}
SgStatus Ad9833_SetFrequency(uint8_t register_index, uint32_t frequency_hz)
{
    if (register_index > 1U) { return SG_INVALID_ARGUMENT; }
    if (frequency_hz < 10U || frequency_hz > 1000000U) { return SG_OUT_OF_RANGE; }
    if (initialized == 0U) { return SG_NOT_READY; }
    if ((control & 0x0002U) != 0U && frequency_hz > 100000U) { return SG_OUT_OF_RANGE; }
    /* 四舍五入；64 位运算避免频率乘 2^28 时溢出。 */
    const uint32_t tuning = (uint32_t)((((uint64_t)frequency_hz << 28)
        + BOARD_DDS_CLOCK_HZ / 2U) / BOARD_DDS_CLOCK_HZ);
    const uint16_t address = register_index == 0U ? 0x4000U : 0x8000U;
    SgStatus result = WriteWord(control);
    if (result == SG_OK) { result = WriteWord(address | (tuning & 0x3FFFU)); }
    if (result == SG_OK) { result = WriteWord(address | ((tuning >> 14) & 0x3FFFU)); }
    if (result == SG_OK) { frequency[register_index] = frequency_hz; }
    return result;
}
SgStatus Ad9833_SetPhase(uint8_t register_index, uint16_t phase_code)
{
    if (register_index > 1U) { return SG_INVALID_ARGUMENT; }
    if (phase_code > 0x0FFFU) { return SG_OUT_OF_RANGE; }
    if (initialized == 0U) { return SG_NOT_READY; }
    return WriteWord((register_index == 0U ? 0xC000U : 0xE000U) | phase_code);
}
SgStatus Ad9833_SetWaveform(SgWaveform waveform)
{
    uint16_t bits;
    if (initialized == 0U) { return SG_NOT_READY; }
    switch (waveform)
    {
        case SG_SINE: bits = 0U; break;
        case SG_TRIANGLE:
            if (frequency[0] > 100000U || frequency[1] > 100000U) { return SG_OUT_OF_RANGE; }
            bits = 0x0002U; break;
        case SG_SQUARE: bits = 0x0028U; break;
        default: return SG_INVALID_ARGUMENT;
    }
    const uint16_t next = (control & (uint16_t)~DDS_WAVE_MASK) | bits;
    SgStatus result = WriteWord(next);
    if (result == SG_OK) { control = next; }
    return result;
}
SgStatus Ad9833_EnableOutput(uint8_t enabled)
{
    if (enabled > 1U) { return SG_INVALID_ARGUMENT; }
    if (initialized == 0U || (enabled != 0U && frequency[0] == 0U)) { return SG_NOT_READY; }
    const uint16_t next = enabled != 0U
        ? control & (uint16_t)~DDS_RESET : control | DDS_RESET;
    SgStatus result = WriteWord(next);
    if (result == SG_OK) { control = next; }
    return result;
}
