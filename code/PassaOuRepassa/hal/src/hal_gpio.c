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
void HAL_GPIO_SetPinDirection(uint32_t port, uint8_t pins, uint32_t direction)
{
    GPIODirModeSet(port, pins, direction);
}

void HAL_GPIO_SetInterruptType(uint32_t port, uint8_t pins, uint32_t interrupt_type)
{
    GPIOIntTypeSet(port, pins, interrupt_type);
}

void HAL_GPIO_EnableInterrupts(uint32_t port, uint32_t interrupt_flags)
{
    GPIOIntEnable(port, interrupt_flags);
}

void HAL_GPIO_DisableInterrupts(uint32_t port, uint32_t interrupt_flags)
{
    GPIOIntDisable(port, interrupt_flags);
}

void HAL_GPIO_ClearInterrupt(uint32_t port, uint32_t interrupt_flags)
{
    GPIOIntClear(port, interrupt_flags);
}

void HAL_GPIO_RegisterPinInterruptHandler(uint32_t port, uint32_t pin, void (*fp_interrupt_handler)(void))
{
    GPIOIntRegisterPin(port, pin, *fp_interrupt_handler);
}

int32_t HAL_GPIO_ReadFromPin(uint32_t port, uint8_t pins)
{
    return GPIOPinRead(port, pins);
}

void HAL_GPIO_WriteToPin(uint32_t port, uint8_t pins, uint8_t value)
{
    GPIOPinWrite(port, pins, value);
}

void HAL_GPIO_ConfigurePinFunction(uint32_t pin_config)
{
    GPIOPinConfigure(pin_config);
}

void HAL_GPIO_SetPinAsInput(uint32_t port, uint8_t pins)
{
    GPIOPinTypeGPIOInput(port, pins);
}

void HAL_GPIO_SetPinAsOutput(uint32_t port, uint8_t pins)
{
    GPIOPinTypeGPIOOutput(port, pins);
}

void HAL_GPIO_SetPinAsOpenDrain(uint32_t port, uint8_t pins)
{
    GPIOPinTypeGPIOOutputOD(port, pins);
}

void HAL_GPIO_PadConfigSet(uint32_t port, uint8_t pins, uint32_t strength, uint32_t pin_type)
{
    GPIOPadConfigSet(port, pins, strength, pin_type);
}
