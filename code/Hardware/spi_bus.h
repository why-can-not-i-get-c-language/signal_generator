#ifndef SPI_BUS_H
#define SPI_BUS_H
#include "sg_types.h"

/* SPI总线与事务：接口已建立，功能尚未实现。 */
SgStatus SpiBus_Init(void);
SgStatus SpiBus_Write(const uint8_t *data, size_t length);
#endif

