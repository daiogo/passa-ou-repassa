/*
 * hal_gpio.h
 *
 *  Created on: 30 de set de 2018
 *      Author: diogo
 */

#ifndef HAL_INC_HAL_GPIO_H_
#define HAL_INC_HAL_GPIO_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

void HAL_GPIO_SetPinDirection(uint32_t port, uint8_t pin, uint32_t direction);

void HAL_GPIO_SetInterruptType(uint32_t ui32Port, uint8_t ui8Pins, uint32_t ui32IntType);

void HAL_GPIO_EnableInterrupts(uint32_t ui32Port, uint32_t ui32IntFlags);

void HAL_GPIO_DisableInterrupts(uint32_t ui32Port, uint32_t ui32IntFlags);

void HAL_GPIO_ClearInterrupt(uint32_t ui32Port, uint32_t ui32IntFlags);

void HAL_GPIO_RegisterPinInterruptHandler(uint32_t ui32Port, uint32_t ui32Pin, void (*pfnIntHandler)(void));

int32_t HAL_GPIO_ReadFromPin(uint32_t ui32Port, uint8_t ui8Pins);

void HAL_GPIO_WriteToPin(uint32_t ui32Port, uint8_t ui8Pins, uint8_t ui8Val);

void HAL_GPIO_ConfigurePinFunction(uint32_t ui32PinConfig);

void HAL_GPIO_SetPinAsInput(uint32_t ui32Port, uint8_t ui8Pins);

void HAL_GPIO_SetPinAsOutput(uint32_t ui32Port, uint8_t ui8Pins);

void HAL_GPIO_SetPinAsOpenDrain(uint32_t ui32Port, uint8_t ui8Pins);

void HAL_GPIO_PadConfigSet(uint32_t ui32Port, uint8_t ui8Pins, uint32_t ui32Strength, uint32_t ui32PinType);

#endif /* HAL_INC_HAL_GPIO_H_ */
