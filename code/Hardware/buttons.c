#include "buttons.h"

/* TODO：按计划实现 按键读取与消抖，在此之前不访问硬件、不改写结果。 */
SgStatus Buttons_Init(void)
{
    return SG_NOT_IMPLEMENTED;
}

SgStatus Buttons_ReadEvents(uint32_t now_ms, uint32_t *event_mask)
{
    (void)now_ms;
    (void)event_mask;
    return SG_NOT_IMPLEMENTED;
}

