#ifndef INPUT_SERVICE_H
#define INPUT_SERVICE_H
#include "sg_types.h"
typedef struct { uint32_t buttons; int16_t encoder_delta; } InputEvent;
/* 按键与编码器事件整合：接口已建立，功能尚未实现。 */
SgStatus InputService_Init(void);
SgStatus InputService_Poll(uint32_t now_ms, InputEvent *event);
#endif

