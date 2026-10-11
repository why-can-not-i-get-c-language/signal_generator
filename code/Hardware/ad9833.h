#ifndef AD9833_H
#define AD9833_H
#include "sg_types.h"

/* SG_OK 仅表示发送完成，无芯片应答或测量证据。
 * 默认使用频率/相位寄存器 0，写寄存器 1 不会切换输出。
 * 禁用使用 RESET，DAC 保持中间电平，不是零伏或物理断开。 */
SgStatus Ad9833_Init(void);
SgStatus Ad9833_SetFrequency(uint8_t register_index, uint32_t frequency_hz);
SgStatus Ad9833_SetPhase(uint8_t register_index, uint16_t phase_code);
SgStatus Ad9833_SetWaveform(SgWaveform waveform);
SgStatus Ad9833_EnableOutput(uint8_t enabled);
#endif
