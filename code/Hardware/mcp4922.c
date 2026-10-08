#include "mcp4922.h"

/* TODO：按计划实现 双通道DAC控制，在此之前不访问硬件、不改写结果。 */
SgStatus Mcp4922_Init(void)
{
    return SG_NOT_IMPLEMENTED;
}

SgStatus Mcp4922_SetCode(uint8_t channel, uint16_t code)
{
    (void)channel;
    (void)code;
    return SG_NOT_IMPLEMENTED;
}

