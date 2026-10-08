#include "input_service.h"

/* TODO：按计划实现 按键与编码器事件整合，在此之前不访问硬件、不改写结果。 */
SgStatus InputService_Init(void)
{
    return SG_NOT_IMPLEMENTED;
}

SgStatus InputService_Poll(uint32_t now_ms, InputEvent *event)
{
    (void)now_ms;
    (void)event;
    return SG_NOT_IMPLEMENTED;
}

