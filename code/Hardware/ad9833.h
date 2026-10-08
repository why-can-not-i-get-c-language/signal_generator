#ifndef AD9833_H
#define AD9833_H
#include "sg_types.h"

/* DDS频率、相位、波形及输出控制：接口已建立，功能尚未实现。 */
SgStatus Ad9833_Init(void);
SgStatus Ad9833_SetFrequency(uint8_t register_index, uint32_t frequency_hz);
SgStatus Ad9833_SetPhase(uint8_t register_index, uint16_t phase_code);
SgStatus Ad9833_SetWaveform(SgWaveform waveform);
SgStatus Ad9833_EnableOutput(uint8_t enabled);
#endif

