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
void HAL_GPIO_SetPinDirection(uint32_t ui32Port, uint8_t ui8Pins, uint32_t ui32PinIO)
{
    GPIODirModeSet(ui32Port, ui8Pins, ui32PinIO);
}

void HAL_GPIO_SetInterruptType(uint32_t ui32Port, uint8_t ui8Pins, uint32_t ui32IntType)
{
    GPIOIntTypeSet(ui32Port, ui8Pins, ui32IntType);
}

void HAL_GPIO_EnableInterrupts(uint32_t ui32Port, uint32_t ui32IntFlags)
{
    GPIOIntEnable(ui32Port, ui32IntFlags);
}

void HAL_GPIO_DisableInterrupts(uint32_t ui32Port, uint32_t ui32IntFlags)
{
    GPIOIntDisable(ui32Port, ui32IntFlags);
}

void HAL_GPIO_ClearInterrupt(uint32_t ui32Port, uint32_t ui32IntFlags)
{
    GPIOIntClear(ui32Port, ui32IntFlags);
}

void HAL_GPIO_RegisterPinInterruptHandler(uint32_t ui32Port, uint32_t ui32Pin, void (*pfnIntHandler)(void))
{
    GPIOIntRegisterPin(ui32Port, ui32Pin, *pfnIntHandler);
}

int32_t HAL_GPIO_ReadFromPin(uint32_t ui32Port, uint8_t ui8Pins)
{
    return GPIOPinRead(ui32Port, ui8Pins);
}

void HAL_GPIO_WriteToPin(uint32_t ui32Port, uint8_t ui8Pins, uint8_t ui8Val)
{

}

void HAL_GPIO_ConfigurePinFunction(uint32_t ui32PinConfig)
{

}
