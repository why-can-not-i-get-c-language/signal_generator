#ifndef SIGNAL_GENERATOR_H
#define SIGNAL_GENERATOR_H
#include "sg_types.h"

/* 波形参数到DDS及模拟链路的协调：接口已建立，功能尚未实现。 */
SgStatus SignalGenerator_Init(void);
SgStatus SignalGenerator_ApplyParameters(const SgParameters *parameters);
SgStatus SignalGenerator_EnableOutput(uint8_t enabled);
#endif

