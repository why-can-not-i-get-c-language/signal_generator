#ifndef AM_CONTROL_H
#define AM_CONTROL_H
#include "sg_types.h"

/* AD633模拟调幅辅助控制：接口已建立，功能尚未实现。 */
SgStatus AmControl_Init(void);
SgStatus AmControl_Configure(uint32_t modulation_hz, uint8_t depth_percent);
SgStatus AmControl_Enable(uint8_t enabled);
#endif

