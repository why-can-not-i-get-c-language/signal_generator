#include "i2c_bus.h"
#include "stm32f1xx_hal.h"
#include "board_config.h"

#define I2C_CLOCK_TIMEOUT_MS 5U
static uint8_t initialized;

static void BusDelay(void)
{
    /* HSI 8MHz 下保守低速；不宣称精确时钟频率。 */
    for (volatile uint32_t i = 0; i < 64U; ++i) { __NOP(); }
}
static void DriveLow(uint16_t pin)
{
    GPIO_InitTypeDef gpio = {0};
    HAL_GPIO_WritePin(BOARD_I2C_GPIO, pin, GPIO_PIN_RESET);
    gpio.Pin = pin;
    gpio.Mode = GPIO_MODE_OUTPUT_OD;
    gpio.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(BOARD_I2C_GPIO, &gpio);
}
static void ReleaseLine(uint16_t pin)
{
    GPIO_InitTypeDef gpio = {0};
    /* 先释放开漏输出，再改成带弱上拉的输入；始终不强推高电平。
     * F1 输出开漏模式不能直接启用内部上拉，故在释放阶段切输入。 */
    HAL_GPIO_WritePin(BOARD_I2C_GPIO, pin, GPIO_PIN_SET);
    gpio.Pin = pin;
    gpio.Mode = GPIO_MODE_INPUT;
    gpio.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(BOARD_I2C_GPIO, &gpio);
}
static SgStatus RaiseClock(void)
{
    ReleaseLine(BOARD_I2C_SCL_PIN);
    const uint32_t start_ms = HAL_GetTick();
    /* 从机可能暂时拉住时钟，必须读到实际高电平再继续。 */
    while (HAL_GPIO_ReadPin(BOARD_I2C_GPIO, BOARD_I2C_SCL_PIN) == GPIO_PIN_RESET)
    {
        if ((uint32_t)(HAL_GetTick() - start_ms) >= I2C_CLOCK_TIMEOUT_MS)
        { return SG_NOT_READY; }
    }
    BusDelay();
    return SG_OK;
}
static SgStatus Start(void)
{
    ReleaseLine(BOARD_I2C_SDA_PIN);
    SgStatus result = RaiseClock();
    if (result != SG_OK) { return result; }
    if (HAL_GPIO_ReadPin(BOARD_I2C_GPIO, BOARD_I2C_SDA_PIN) == GPIO_PIN_RESET)
    { return SG_NOT_READY; }
    /* SCL 高期间，SDA 从高变低表示开始；其余数据在 SCL 低期间准备。 */
    DriveLow(BOARD_I2C_SDA_PIN);
    BusDelay();
    DriveLow(BOARD_I2C_SCL_PIN);
    BusDelay();
    return SG_OK;
}
static SgStatus Stop(void)
{
    DriveLow(BOARD_I2C_SCL_PIN);
    DriveLow(BOARD_I2C_SDA_PIN);
    BusDelay();
    SgStatus result = RaiseClock();
    /* 即使时钟异常也释放数据线，不保持强制拉低。 */
    ReleaseLine(BOARD_I2C_SDA_PIN);
    BusDelay();
    if (result != SG_OK) { return result; }
    return HAL_GPIO_ReadPin(BOARD_I2C_GPIO, BOARD_I2C_SDA_PIN) == GPIO_PIN_SET
        ? SG_OK : SG_NOT_READY;
}
static SgStatus WriteByte(uint8_t value)
{
    for (uint8_t mask = 0x80U; mask != 0U; mask >>= 1)
    {
        if ((value & mask) != 0U) { ReleaseLine(BOARD_I2C_SDA_PIN); }
        else { DriveLow(BOARD_I2C_SDA_PIN); }
        BusDelay();
        SgStatus result = RaiseClock();
        if (result != SG_OK) { return result; }
        DriveLow(BOARD_I2C_SCL_PIN);
        BusDelay();
    }
    /* 第九个时钟让接收方拉低 SDA，作为应答 ACK。 */
    ReleaseLine(BOARD_I2C_SDA_PIN);
    BusDelay();
    SgStatus result = RaiseClock();
    if (result != SG_OK) { return result; }
    const uint8_t acknowledged = (uint8_t)(HAL_GPIO_ReadPin(
        BOARD_I2C_GPIO, BOARD_I2C_SDA_PIN) == GPIO_PIN_RESET);
    DriveLow(BOARD_I2C_SCL_PIN);
    BusDelay();
    return acknowledged != 0U ? SG_OK : SG_IO_ERROR;
}
static SgStatus Transfer(uint8_t address7, const uint8_t *data, size_t length)
{
    if (address7 < 0x08U || address7 > 0x77U) { return SG_INVALID_ARGUMENT; }
    if (initialized == 0U) { return SG_NOT_READY; }
    SgStatus result = Start();
    if (result != SG_OK) { return result; }
    /* 地址后附加一位读写选择；本驱动只写，因此最低位是 0。 */
    result = WriteByte((uint8_t)(address7 << 1));
    for (size_t i = 0; i < length && result == SG_OK; ++i)
    { result = WriteByte(data[i]); }
    SgStatus stop_result = Stop();
    return stop_result != SG_OK ? stop_result : result;
}
SgStatus I2cBus_Init(void)
{
    initialized = 0U;
    __HAL_RCC_GPIOB_CLK_ENABLE();
    ReleaseLine(BOARD_I2C_SDA_PIN);
    SgStatus result = RaiseClock();
    if (result != SG_OK) { return result; }
    if (HAL_GPIO_ReadPin(BOARD_I2C_GPIO, BOARD_I2C_SDA_PIN) == GPIO_PIN_RESET)
    { return SG_NOT_READY; }
    initialized = 1U;
    return SG_OK;
}
SgStatus I2cBus_Write(uint8_t address7, const uint8_t *data, size_t length)
{
    if (data == NULL || length == 0U) { return SG_INVALID_ARGUMENT; }
    return Transfer(address7, data, length);
}
SgStatus I2cBus_Probe(uint8_t address7)
{
    return Transfer(address7, NULL, 0U);
}
