#include "parameter_store.h"

/* TODO：按计划实现 参数持久化与数据有效性检查，在此之前不访问硬件、不改写结果。 */
SgStatus ParameterStore_Init(void)
{
    return SG_NOT_IMPLEMENTED;
}

SgStatus ParameterStore_Load(SgParameters *parameters)
{
    (void)parameters;
    return SG_NOT_IMPLEMENTED;
}

SgStatus ParameterStore_Save(const SgParameters *parameters)
{
    (void)parameters;
    return SG_NOT_IMPLEMENTED;
}

