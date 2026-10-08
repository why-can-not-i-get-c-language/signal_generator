#include "burst.h"

/* TODO：按计划实现 触发与定周期数输出，在此之前不访问硬件、不改写结果。 */
SgStatus Burst_Init(void)
{
    return SG_NOT_IMPLEMENTED;
}

SgStatus Burst_Trigger(const BurstConfig *config)
{
    (void)config;
    return SG_NOT_IMPLEMENTED;
}

SgStatus Burst_Update(uint32_t now_us)
{
    (void)now_us;
    return SG_NOT_IMPLEMENTED;
}

SgStatus Burst_Stop(void)
{
    return SG_NOT_IMPLEMENTED;
}

