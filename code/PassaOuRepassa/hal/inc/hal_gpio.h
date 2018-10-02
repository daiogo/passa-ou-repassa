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

void HAL_GPIO_SetPinDirection(uint32_t arg_Port, uint8_t arg_Pins, uint32_t arg_Direction);

void HAL_GPIO_SetInterruptType(uint32_t arg_Port, uint8_t arg_Pins, uint32_t arg_InterruptType);

void HAL_GPIO_EnableInterrupts(uint32_t arg_Port, uint32_t arg_InterruptFlags);

void HAL_GPIO_DisableInterrupts(uint32_t arg_Port, uint32_t arg_InterruptFlags);

void HAL_GPIO_ClearInterrupt(uint32_t arg_Port, uint32_t arg_InterruptFlags);

void HAL_GPIO_RegisterPinInterruptHandler(uint32_t arg_Port, uint32_t arg_Pin, void (*arg_fpInterruptHandler)(void));

int32_t HAL_GPIO_ReadFromPin(uint32_t arg_Port, uint8_t arg_Pins);

void HAL_GPIO_WriteToPin(uint32_t arg_Port, uint8_t arg_Pins, uint8_t arg_Value);

void HAL_GPIO_ConfigurePinFunction(uint32_t arg_PinConfig);

void HAL_GPIO_SetPinAsInput(uint32_t arg_Port, uint8_t arg_Pins);

void HAL_GPIO_SetPinAsOutput(uint32_t arg_Port, uint8_t arg_Pins);

#endif /* HAL_INC_HAL_GPIO_H_ */
