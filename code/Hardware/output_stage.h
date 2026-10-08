#ifndef OUTPUT_STAGE_H
#define OUTPUT_STAGE_H
#include "sg_types.h"

/* 输出模式、幅度、偏置与门控：接口已建立，功能尚未实现。 */
SgStatus OutputStage_Init(void);
SgStatus OutputStage_Configure(const SgParameters *parameters);
SgStatus OutputStage_Enable(uint8_t enabled);
#endif

