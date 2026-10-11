#ifndef SPI_BUS_H
#define SPI_BUS_H
#include "sg_types.h"

/* DDS 专用软件 SPI：模式 2、高位先发、仅写；调用者控制片选。
 * 不能直接用于其他时钟模式的器件。 */
SgStatus SpiBus_Init(void);
SgStatus SpiBus_Write(const uint8_t *data, size_t length);
#endif
