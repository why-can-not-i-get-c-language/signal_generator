#include "i2c_bus.h"

/* TODO：按计划实现 I2C总线与事务，在此之前不访问硬件、不改写结果。 */
SgStatus I2cBus_Init(void)
{
    return SG_NOT_IMPLEMENTED;
}

SgStatus I2cBus_Write(uint8_t address7, const uint8_t *data, size_t length)
{
    (void)address7;
    (void)data;
    (void)length;
    return SG_NOT_IMPLEMENTED;
}

SgStatus I2cBus_Probe(uint8_t address7)
{
    (void)address7;
    return SG_NOT_IMPLEMENTED;
}

