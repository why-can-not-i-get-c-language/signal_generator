#ifndef I2C_BUS_H
#define I2C_BUS_H
#include "sg_types.h"

/* I2C总线与事务：接口已建立，功能尚未实现。 */
SgStatus I2cBus_Init(void);
SgStatus I2cBus_Write(uint8_t address7, const uint8_t *data, size_t length);
SgStatus I2cBus_Probe(uint8_t address7);
#endif

