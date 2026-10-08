#include "timebase.h"

/* TODO：按计划实现 微秒计时与精确调度的时间源，在此之前不访问硬件、不改写结果。 */
SgStatus Timebase_Init(void)
{
    return SG_NOT_IMPLEMENTED;
}

SgStatus Timebase_ReadMicroseconds(uint32_t *now_us)
{
    (void)now_us;
    return SG_NOT_IMPLEMENTED;
}

