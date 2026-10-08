#ifndef CALIBRATION_H
#define CALIBRATION_H
#include "sg_types.h"
typedef struct {
    SgLoadMode load_mode;
    uint32_t frequency_hz, set_mvpp, measured_mvpp;
    uint16_t sample_count;
} CalibrationPoint; /* measured_mvpp 必须来源于真实测量。 */
/* 原始校准点与修正值计算：接口已建立，功能尚未实现。 */
SgStatus Calibration_Init(void);
SgStatus Calibration_AddPoint(const CalibrationPoint *point);
SgStatus Calibration_Apply(const SgParameters *requested, SgParameters *corrected);
#endif

