#include "ad9833.h"

/* TODO：按计划实现 DDS频率、相位、波形及输出控制，在此之前不访问硬件、不改写结果。 */
SgStatus Ad9833_Init(void)
{
    return SG_NOT_IMPLEMENTED;
}

SgStatus Ad9833_SetFrequency(uint8_t register_index, uint32_t frequency_hz)
{
    (void)register_index;
    (void)frequency_hz;
    return SG_NOT_IMPLEMENTED;
}

SgStatus Ad9833_SetPhase(uint8_t register_index, uint16_t phase_code)
{
    (void)register_index;
    (void)phase_code;
    return SG_NOT_IMPLEMENTED;
}

SgStatus Ad9833_SetWaveform(SgWaveform waveform)
{
    (void)waveform;
    return SG_NOT_IMPLEMENTED;
}

SgStatus Ad9833_EnableOutput(uint8_t enabled)
{
    (void)enabled;
    return SG_NOT_IMPLEMENTED;
}

