/*
 * PassaOuRepassa.c
 *
 *  Created on: 30 de set de 2018
 *      Author: diogo
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "PassaOuRepassa.h"

/*******************************************************************************
 * Function Definitions
 ******************************************************************************/
void POR_Init(void)
{
    // Board hardware init
    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);   // Set up the clock
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);                                        // Enable arg_Port D
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);                                        // Enable arg_Port E
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);                                        // Enable arg_Port F

    // Init switches
    POR_InitSwitch(SW0_PORT, SW0);
    POR_InitSwitch(SW1_PORT, SW1);
    POR_InitSwitch(SW2_PORT, SW2);
    POR_InitSwitch(SW3_PORT, SW3);

    // Init LEDs
    POR_InitLed(LED0_PORT, LED0);
    POR_InitLed(LED1_PORT, LED1);
    POR_InitLed(LED2_PORT, LED2);
    POR_InitLed(LED3_PORT, LED3);

    // Init Interrupts
    POR_SetInterrupts();
}

void POR_Run(void)
{
    while (1)
    {
        if (POR_ReadFromSwitch(SW0_PORT, SW0) == SW0)
        {
            POR_WriteToLed(LED0_PORT, LED0, LED0);
        }
        else if (POR_ReadFromSwitch(SW1_PORT, SW1) == SW1)
        {
            POR_WriteToLed(LED1_PORT, LED1, LED1);
        }
        else if (POR_ReadFromSwitch(SW2_PORT, SW2) == SW2)
        {
            POR_WriteToLed(LED2_PORT, LED2, LED2);
        }
        else if (POR_ReadFromSwitch(SW3_PORT, SW3) == SW3)
        {
            POR_WriteToLed(LED3_PORT, LED3, LED3);
        }
        else
        {
            POR_WriteToLed(LED0_PORT, LED0, 0);
            POR_WriteToLed(LED1_PORT, LED1, 0);
            POR_WriteToLed(LED2_PORT, LED2, 0);
            POR_WriteToLed(LED3_PORT, LED3, 0);
        }
    }
}

void POR_InitSwitch(uint32_t arg_Port, uint8_t arg_Pins)
{
    HAL_GPIO_SetPinAsInput(arg_Port, arg_Pins);
}

void POR_InitLed(uint32_t arg_Port, uint8_t arg_Pins)
{
    HAL_GPIO_SetPinAsOutput(arg_Port, arg_Pins);
}

void POR_WriteToLed(uint32_t arg_Port, uint8_t arg_Pins, uint8_t arg_Value)
{
    HAL_GPIO_WriteToPin(arg_Port, arg_Pins, arg_Value);
}

int32_t POR_ReadFromSwitch(uint32_t arg_Port, uint8_t arg_Pins)
{
    return HAL_GPIO_ReadFromPin(arg_Port, arg_Pins);
}

void POR_SetInterrupts(void)
{
    HAL_GPIO_SetInterruptType(SW0_PORT, SW0, INTERRUPT_TYPE);
    HAL_GPIO_SetInterruptType(SW1_PORT, SW1, INTERRUPT_TYPE);
    HAL_GPIO_SetInterruptType(SW2_PORT, SW2, INTERRUPT_TYPE);
    HAL_GPIO_SetInterruptType(SW3_PORT, SW3, INTERRUPT_TYPE);

    HAL_GPIO_RegisterInterruptHandler(SW0_PORT, HAL_GPIO_IrqHandlerPortD);

    HAL_GPIO_EnableInterrupts(SW0_PORT, SW0);
}
