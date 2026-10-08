#include "sweep.h"

/* TODO：按计划实现 线性及对数扫频状态机，在此之前不访问硬件、不改写结果。 */
SgStatus Sweep_Init(void)
{
    return SG_NOT_IMPLEMENTED;
}

SgStatus Sweep_Start(const SweepConfig *config, uint32_t now_ms)
{
    (void)config;
    (void)now_ms;
    return SG_NOT_IMPLEMENTED;
}

SgStatus Sweep_Update(uint32_t now_ms)
{
    (void)now_ms;
    return SG_NOT_IMPLEMENTED;
}

SgStatus Sweep_Stop(void)
{
    return SG_NOT_IMPLEMENTED;
}

