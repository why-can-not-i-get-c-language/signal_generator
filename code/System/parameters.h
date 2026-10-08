#ifndef PARAMETERS_H
#define PARAMETERS_H
#include "sg_types.h"
void Parameters_Default(SgParameters *parameters, SgRuntimeState *state);
SgStatus Parameters_ValidateTarget(const SgParameters *parameters);
uint32_t Parameters_FrequencyStep(uint32_t frequency_hz);
/* ValidateTarget 仅检查最终题目设定边界，不代表当前硬件具备这些能力。 */
#endif

