#ifndef APP_H
#define APP_H
#include "sg_types.h"

/* 整机初始化、任务调度与安全状态：接口已建立，功能尚未实现。 */
SgStatus App_Init(void);
SgStatus App_Update(uint32_t now_ms);
#endif

