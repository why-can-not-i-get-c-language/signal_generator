#include "ui_menu.h"

/* TODO：按计划实现 参数选择、编辑、确认与错误提示，在此之前不访问硬件、不改写结果。 */
SgStatus UiMenu_Init(void)
{
    return SG_NOT_IMPLEMENTED;
}

SgStatus UiMenu_HandleInput(uint32_t buttons, int16_t encoder_delta)
{
    (void)buttons;
    (void)encoder_delta;
    return SG_NOT_IMPLEMENTED;
}

SgStatus UiMenu_GetParameters(SgParameters *parameters)
{
    (void)parameters;
    return SG_NOT_IMPLEMENTED;
}

