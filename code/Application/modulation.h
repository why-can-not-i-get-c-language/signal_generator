#ifndef MODULATION_H
#define MODULATION_H
#include "sg_types.h"
typedef enum { MODULATION_ASK, MODULATION_FSK, MODULATION_PSK } ModulationMode;
typedef struct {
    ModulationMode mode;
    uint32_t carrier_hz, alternate_hz, bitrate_bps;
} ModulationConfig;
/* now_us 的精确时间源与更新调度待实现，不能用毫秒轮询声称达到10 kbps。 */
/* 2ASK、2FSK及2PSK测试序列：接口已建立，功能尚未实现。 */
SgStatus Modulation_Init(void);
SgStatus Modulation_Start(const ModulationConfig *config);
SgStatus Modulation_Update(uint32_t now_us);
SgStatus Modulation_Stop(void);
#endif

