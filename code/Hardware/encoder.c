#include "encoder.h"

/* TODO：按计划实现 EC11旋转方向、步进与按压，在此之前不访问硬件、不改写结果。 */
SgStatus Encoder_Init(void)
{
    return SG_NOT_IMPLEMENTED;
}

SgStatus Encoder_ReadDelta(uint32_t now_ms, int16_t *delta)
{
    (void)now_ms;
    (void)delta;
    return SG_NOT_IMPLEMENTED;
}

