#ifndef SG_TYPES_H
#define SG_TYPES_H
#include <stdint.h>
#include <stddef.h>
/* 未实现与硬件失败必须分别处理，不得把接口占位当作成功。 */
typedef enum {
    SG_OK = 0, SG_INVALID_ARGUMENT, SG_NOT_IMPLEMENTED,
    SG_NOT_READY, SG_IO_ERROR, SG_OUT_OF_RANGE
} SgStatus;
typedef enum { SG_SINE, SG_TRIANGLE, SG_SQUARE } SgWaveform;
typedef enum { SG_HIGH_IMPEDANCE, SG_LOAD_50_OHM } SgLoadMode;
typedef struct {
    SgWaveform waveform;
    uint32_t frequency_hz;
    uint32_t amplitude_mvpp; /* 设定峰峰值，不是实测幅度。 */
    int32_t offset_mv;
    SgLoadMode load_mode;
} SgParameters;
typedef struct {
    SgStatus status;
    uint8_t output_enabled;
    uint8_t measurement_valid; /* 未测量时必须为零。 */
} SgRuntimeState;
#endif

