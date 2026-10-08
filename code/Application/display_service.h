#ifndef DISPLAY_SERVICE_H
#define DISPLAY_SERVICE_H
#include "sg_types.h"

/* 设定值与运行状态的显示：接口已建立，功能尚未实现。 */
SgStatus DisplayService_Init(void);
SgStatus DisplayService_Render(const SgParameters *parameters, const SgRuntimeState *state);
#endif

