#include "calibration.h"

/* TODO：按计划实现 原始校准点与修正值计算，在此之前不访问硬件、不改写结果。 */
SgStatus Calibration_Init(void)
{
    return SG_NOT_IMPLEMENTED;
}

SgStatus Calibration_AddPoint(const CalibrationPoint *point)
{
    (void)point;
    return SG_NOT_IMPLEMENTED;
}

SgStatus Calibration_Apply(const SgParameters *requested, SgParameters *corrected)
{
    (void)requested;
    (void)corrected;
    return SG_NOT_IMPLEMENTED;
}

