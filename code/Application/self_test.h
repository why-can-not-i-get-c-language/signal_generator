#ifndef SELF_TEST_H
#define SELF_TEST_H
#include "sg_types.h"

/* 模块检测与故障报告：接口已建立，功能尚未实现。 */
SgStatus SelfTest_Init(void);
SgStatus SelfTest_Run(uint32_t *failed_modules);
#endif

