#ifndef OLED_H
#define OLED_H
#include "sg_types.h"

/* OLED初始化、绘制与刷新：接口已建立，功能尚未实现。 */
SgStatus Oled_Init(void);
SgStatus Oled_Clear(void);
SgStatus Oled_DrawText(uint8_t x, uint8_t y, const char *text);
SgStatus Oled_Refresh(void);
#endif

