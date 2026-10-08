#ifndef BURST_H
#define BURST_H
#include "sg_types.h"
typedef struct { SgWaveform waveform; uint32_t frequency_hz; uint16_t cycles; } BurstConfig;
/* 精确周期计数与硬件门控待实现，不用软件延时冒充已验证周期数。 */
/* 触发与定周期数输出：接口已建立，功能尚未实现。 */
SgStatus Burst_Init(void);
SgStatus Burst_Trigger(const BurstConfig *config);
SgStatus Burst_Update(uint32_t now_us);
SgStatus Burst_Stop(void);
#endif

