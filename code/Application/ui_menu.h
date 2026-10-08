#ifndef UI_MENU_H
#define UI_MENU_H
#include "sg_types.h"

/* 参数选择、编辑、确认与错误提示：接口已建立，功能尚未实现。 */
SgStatus UiMenu_Init(void);
SgStatus UiMenu_HandleInput(uint32_t buttons, int16_t encoder_delta);
SgStatus UiMenu_GetParameters(SgParameters *parameters);
#endif

