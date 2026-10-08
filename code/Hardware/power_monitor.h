#ifndef POWER_MONITOR_H
#define POWER_MONITOR_H
#include "sg_types.h"
typedef struct {
    uint32_t rail_3v3_mv;
    uint32_t rail_5v_mv;
    int32_t analog_positive_mv;
    int32_t analog_negative_mv;
    uint8_t valid;
} PowerReadings; /* 仅实际采样成功才可标记 valid。 */
/* 电源状态采样与保护输入：接口已建立，功能尚未实现。 */
SgStatus PowerMonitor_Init(void);
SgStatus PowerMonitor_Read(PowerReadings *readings);
#endif

