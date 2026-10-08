#ifndef ENCODER_H
#define ENCODER_H
#include "sg_types.h"

/* EC11旋转方向、步进与按压：接口已建立，功能尚未实现。 */
SgStatus Encoder_Init(void);
SgStatus Encoder_ReadDelta(uint32_t now_ms, int16_t *delta);
#endif

