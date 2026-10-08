#ifndef PARAMETER_STORE_H
#define PARAMETER_STORE_H
#include "sg_types.h"

/* 参数持久化与数据有效性检查：接口已建立，功能尚未实现。 */
SgStatus ParameterStore_Init(void);
SgStatus ParameterStore_Load(SgParameters *parameters);
SgStatus ParameterStore_Save(const SgParameters *parameters);
#endif

