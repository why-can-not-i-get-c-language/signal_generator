#ifndef OLED_FONT_H
#define OLED_FONT_H
#include "sg_types.h"

/* OLED字形数据访问：接口已建立，功能尚未实现。 */
SgStatus OledFont_Init(void);
SgStatus OledFont_GetGlyph(uint32_t codepoint, const uint8_t **bitmap);
#endif

