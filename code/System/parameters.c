#include "parameters.h"
void Parameters_Default(SgParameters *parameters, SgRuntimeState *state)
{
    if (parameters != NULL) {
        parameters->waveform = SG_SINE;
        parameters->frequency_hz = 1000U;
        parameters->amplitude_mvpp = 200U;
        parameters->offset_mv = 0;
        parameters->load_mode = SG_HIGH_IMPEDANCE;
    }
    if (state != NULL) {
        state->status = SG_NOT_READY;
        state->output_enabled = 0U;
        state->measurement_valid = 0U;
    }
}
SgStatus Parameters_ValidateTarget(const SgParameters *parameters)
{
    uint32_t max_hz, max_mvpp, magnitude_mv;
    if (parameters == NULL) return SG_INVALID_ARGUMENT;
    if (parameters->waveform != SG_SINE && parameters->waveform != SG_TRIANGLE &&
        parameters->waveform != SG_SQUARE) return SG_INVALID_ARGUMENT;
    if (parameters->load_mode != SG_HIGH_IMPEDANCE &&
        parameters->load_mode != SG_LOAD_50_OHM) return SG_INVALID_ARGUMENT;
    max_hz = (parameters->waveform == SG_TRIANGLE) ? 100000U : 1000000U;
    if (parameters->frequency_hz < 10U || parameters->frequency_hz > max_hz)
        return SG_OUT_OF_RANGE;
    max_mvpp = (parameters->load_mode == SG_LOAD_50_OHM) ? 1000U :
        ((parameters->frequency_hz <= 100000U) ? 5000U : 2000U);
    if (parameters->amplitude_mvpp < 200U || parameters->amplitude_mvpp > max_mvpp)
        return SG_OUT_OF_RANGE;
    if (parameters->offset_mv < -2000 || parameters->offset_mv > 2000)
        return SG_OUT_OF_RANGE;
    if (parameters->load_mode == SG_LOAD_50_OHM && parameters->offset_mv != 0)
        return SG_OUT_OF_RANGE;
    /* 整数形式检查 |偏置| + Vpp/2 <= 3500 mV，避免除法截断。 */
    magnitude_mv = (uint32_t)((parameters->offset_mv < 0) ?
                             -parameters->offset_mv : parameters->offset_mv);
    if (2U * magnitude_mv + parameters->amplitude_mvpp > 7000U)
        return SG_OUT_OF_RANGE;
    return SG_OK;
}
uint32_t Parameters_FrequencyStep(uint32_t frequency_hz)
{
    return (frequency_hz < 1000U) ? 1U : ((frequency_hz < 100000U) ? 10U : 100U);
}

