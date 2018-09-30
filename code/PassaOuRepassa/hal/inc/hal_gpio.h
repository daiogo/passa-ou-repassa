

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

void HAL_GPIO_SetPinDirection(uint32_t ui32Port, uint8_t ui8Pins, uint32_t ui32PinIO);

void HAL_GPIO_SetInterruptType(uint32_t ui32Port, uint8_t ui8Pins, uint32_t ui32IntType);

void HAL_GPIO_EnableInterrupts(uint32_t ui32Port, uint32_t ui32IntFlags);

void HAL_GPIO_DisableInterrupts(uint32_t ui32Port, uint32_t ui32IntFlags);

void HAL_GPIO_ClearInterrupt(uint32_t ui32Port, uint32_t ui32IntFlags);

void HAL_GPIO_RegisterPinInterruptHandler(uint32_t ui32Port, uint32_t ui32Pin, void (*pfnIntHandler)(void));

int32_t HAL_GPIO_ReadFromPin(uint32_t ui32Port, uint8_t ui8Pins);

void HAL_GPIO_WriteToPin(uint32_t ui32Port, uint8_t ui8Pins, uint8_t ui8Val);

void HAL_GPIO_ConfigurePinFunction(uint32_t ui32PinConfig);
