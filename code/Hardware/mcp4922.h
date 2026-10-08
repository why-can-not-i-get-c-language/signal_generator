#ifndef MCP4922_H
#define MCP4922_H
#include "sg_types.h"

/* 双通道DAC控制：接口已建立，功能尚未实现。 */
SgStatus Mcp4922_Init(void);
SgStatus Mcp4922_SetCode(uint8_t channel, uint16_t code);
#endif

