#ifndef SWEEP_H
#define SWEEP_H
#include "sg_types.h"
typedef enum { SWEEP_LINEAR, SWEEP_LOGARITHMIC } SweepMode;
typedef struct {
    uint32_t start_hz, end_hz, duration_ms;
    SweepMode mode;
    uint8_t repeat;
} SweepConfig;
/* 线性及对数扫频状态机：接口已建立，功能尚未实现。 */
SgStatus Sweep_Init(void);
SgStatus Sweep_Start(const SweepConfig *config, uint32_t now_ms);
SgStatus Sweep_Update(uint32_t now_ms);
SgStatus Sweep_Stop(void);
#endif

