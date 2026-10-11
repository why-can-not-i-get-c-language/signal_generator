#ifndef I2C_BUS_H
#define I2C_BUS_H
#include "sg_types.h"

/* 软件 I2C，单控制器、只写。地址参数采用 7 位地址。
 * Init成功只表示总线空闲；Probe/Write成功才表示本次发送收到了应答。
 * SG_IO_ERROR：未应答；SG_NOT_READY：总线未就绪或超时。
 * 当前保守低速，依赖模块上拉；释放线时启用弱上拉辅助，不代替高速外部上拉。 */
SgStatus I2cBus_Init(void);
SgStatus I2cBus_Write(uint8_t address7, const uint8_t *data, size_t length);
SgStatus I2cBus_Probe(uint8_t address7);
#endif
