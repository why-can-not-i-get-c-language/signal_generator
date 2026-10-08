#include "am_control.h"

/* TODO：按计划实现 AD633模拟调幅辅助控制，在此之前不访问硬件、不改写结果。 */
SgStatus AmControl_Init(void)
{
    return SG_NOT_IMPLEMENTED;
}

SgStatus AmControl_Configure(uint32_t modulation_hz, uint8_t depth_percent)
{
    (void)modulation_hz;
    (void)depth_percent;
    return SG_NOT_IMPLEMENTED;
}

SgStatus AmControl_Enable(uint8_t enabled)
{
    (void)enabled;
    return SG_NOT_IMPLEMENTED;
}

