#ifndef BUTTONS_H
#define BUTTONS_H
#include "sg_types.h"

/* 按键读取与消抖：接口已建立，功能尚未实现。 */
SgStatus Buttons_Init(void);
SgStatus Buttons_ReadEvents(uint32_t now_ms, uint32_t *event_mask);
#endif

