#include "oled_font.h"

/* TODO：按计划实现 OLED字形数据访问，在此之前不访问硬件、不改写结果。 */
SgStatus OledFont_Init(void)
{
    return SG_NOT_IMPLEMENTED;
}

SgStatus OledFont_GetGlyph(uint32_t codepoint, const uint8_t **bitmap)
{
    (void)codepoint;
    (void)bitmap;
    return SG_NOT_IMPLEMENTED;
}

