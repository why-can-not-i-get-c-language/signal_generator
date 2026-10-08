#include "modulation.h"

/* TODO：按计划实现 2ASK、2FSK及2PSK测试序列，在此之前不访问硬件、不改写结果。 */
SgStatus Modulation_Init(void)
{
    return SG_NOT_IMPLEMENTED;
}

SgStatus Modulation_Start(const ModulationConfig *config)
{
    (void)config;
    return SG_NOT_IMPLEMENTED;
}

SgStatus Modulation_Update(uint32_t now_us)
{
    (void)now_us;
    return SG_NOT_IMPLEMENTED;
}

SgStatus Modulation_Stop(void)
{
    return SG_NOT_IMPLEMENTED;
}

