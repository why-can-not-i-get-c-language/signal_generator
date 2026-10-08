#ifndef TIMEBASE_H
#define TIMEBASE_H
#include "sg_types.h"

/* 微秒计时与精确调度的时间源：接口已建立，功能尚未实现。 */
SgStatus Timebase_Init(void);
SgStatus Timebase_ReadMicroseconds(uint32_t *now_us);
#endif

