#ifndef MCP41010_H
#define MCP41010_H
#include "sg_types.h"

/* 数字电位器控制：接口已建立，功能尚未实现。 */
SgStatus Mcp41010_Init(void);
SgStatus Mcp41010_SetWiper(uint8_t code);
#endif

