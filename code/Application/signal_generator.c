#include "signal_generator.h"

/* TODO：按计划实现 波形参数到DDS及模拟链路的协调，在此之前不访问硬件、不改写结果。 */
SgStatus SignalGenerator_Init(void)
{
    return SG_NOT_IMPLEMENTED;
}

SgStatus SignalGenerator_ApplyParameters(const SgParameters *parameters)
{
    (void)parameters;
    return SG_NOT_IMPLEMENTED;
}

SgStatus SignalGenerator_EnableOutput(uint8_t enabled)
{
    (void)enabled;
    return SG_NOT_IMPLEMENTED;
}

