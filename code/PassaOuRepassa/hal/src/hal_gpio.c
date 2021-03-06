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
#include "Events.h"

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

void HAL_GPIO_RegisterInterruptHandler(uint32_t arg_Port, void (*arg_fpInterruptHandler)(void))
{
    GPIOIntRegister(arg_Port, arg_fpInterruptHandler);
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

void HAL_GPIO_GetInterruptStatus(uint32_t arg_Port, bool arg_Masked)
{
    GPIOIntStatus(arg_Port, arg_Masked);
}

void HAL_GPIO_IrqHandlerPortD(void)
{
    // Get interrupt flag
    uint32_t loc_Status = GPIOIntStatus(GPIO_PORTD_BASE, true);

    // Clear interrupt flag
    GPIOIntClear(GPIO_PORTD_BASE, loc_Status);

    // Call code in events layer
    SWITCH_OnSwitchPressed(loc_Status);
}

void HAL_GPIO_IrqHandlerPortB(void)
{
    // Get interrupt flag
    uint32_t loc_Status = GPIOIntStatus(GPIO_PORTB_BASE, true);

    // Clear interrupt flag
    GPIOIntClear(GPIO_PORTB_BASE, loc_Status);

    // Call code in events layer
    SWITCH_OnSwitchPressed(loc_Status);
}
