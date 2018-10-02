/*
 * hal_gpio.c
 *
 *  Created on: 30 de set de 2018
 *      Author: diogo
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hal_gpio.h"

/*******************************************************************************
 * Function Definitions
 ******************************************************************************/
void HAL_GPIO_SetPinDirection(uint32_t arg_Port, uint8_t arg_Pins, uint32_t arg_Direction)
{
    GPIODirModeSet(arg_Port, arg_Pins, arg_Direction);
}

void HAL_GPIO_SetInterruptType(uint32_t arg_Port, uint8_t arg_Pins, uint32_t arg_InterruptType)
{
    GPIOIntTypeSet(arg_Port, arg_Pins, arg_InterruptType);
}

void HAL_GPIO_EnableInterrupts(uint32_t arg_Port, uint32_t arg_InterruptFlags)
{
    GPIOIntEnable(arg_Port, arg_InterruptFlags);
}

void HAL_GPIO_DisableInterrupts(uint32_t arg_Port, uint32_t arg_InterruptFlags)
{
    GPIOIntDisable(arg_Port, arg_InterruptFlags);
}

void HAL_GPIO_ClearInterrupt(uint32_t arg_Port, uint32_t arg_InterruptFlags)
{
    GPIOIntClear(arg_Port, arg_InterruptFlags);
}

void HAL_GPIO_RegisterPinInterruptHandler(uint32_t arg_Port, uint32_t arg_Pin, void (*arg_fpInterruptHandler)(void))
{
    GPIOIntRegisterPin(arg_Port, arg_Pin, *arg_fpInterruptHandler);
}

int32_t HAL_GPIO_ReadFromPin(uint32_t arg_Port, uint8_t arg_Pins)
{
    return GPIOPinRead(arg_Port, arg_Pins);
}

void HAL_GPIO_WriteToPin(uint32_t arg_Port, uint8_t arg_Pins, uint8_t arg_Value)
{
    GPIOPinWrite(arg_Port, arg_Pins, arg_Value);
}

void HAL_GPIO_ConfigurePinFunction(uint32_t arg_PinConfig)
{
    GPIOPinConfigure(arg_PinConfig);
}

void HAL_GPIO_SetPinAsInput(uint32_t arg_Port, uint8_t arg_Pins)
{
    GPIOPinTypeGPIOInput(arg_Port, arg_Pins);
}

void HAL_GPIO_SetPinAsOutput(uint32_t arg_Port, uint8_t arg_Pins)
{
    GPIOPinTypeGPIOOutput(arg_Port, arg_Pins);
}

void HAL_GPIO_SetPinAsOpenDrain(uint32_t arg_Port, uint8_t arg_Pins)
{
    GPIOPinTypeGPIOOutputOD(arg_Port, arg_Pins);
}

void HAL_GPIO_PadConfigSet(uint32_t arg_Port, uint8_t arg_Pins, uint32_t arg_Strength, uint32_t arg_PinType)
{
    GPIOPadConfigSet(arg_Port, arg_Pins, arg_Strength, arg_PinType);
}
