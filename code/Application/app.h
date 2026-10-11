#ifndef APP_H
#define APP_H
#include "sg_types.h"

/* 当前只调度 DDS 台架测试与 LED，整机功能尚未实现。 */
SgStatus App_Init(void);
SgStatus App_Update(uint32_t now_ms);
#endif
