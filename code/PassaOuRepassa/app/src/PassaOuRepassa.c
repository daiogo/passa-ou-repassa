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
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);                                        // Enable port F

    // Configure switch 1
    POR_InitSwitch(GPIO_PORTF_BASE, GPIO_PIN_4);

    // Configure red led
    POR_InitLed(GPIO_PORTF_BASE, GPIO_PIN_1);
}

void POR_Run(void)
{
    while (1)
    {
        if (POR_ReadFromSwitch(GPIO_PORTF_BASE, GPIO_PIN_4) == GPIO_PIN_4)
        {
            POR_WriteToLed(GPIO_PORTF_BASE, GPIO_PIN_1, 0);
        }
        else
        {
            POR_WriteToLed(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
        }
    }
}

void POR_InitSwitch(uint32_t port, uint8_t pins)
{
    // Make the pin a input
    HAL_GPIO_SetPinDirection(port, pins, GPIO_DIR_MODE_IN);

    // Set the pad for standard push-pull with weak pull-up
    HAL_GPIO_PadConfigSet(port, pins, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
}

void POR_InitLed(uint32_t port, uint8_t pins)
{
    HAL_GPIO_SetPinAsOutput(port, pins);
}

void POR_WriteToLed(uint32_t port, uint8_t pins, uint8_t value)
{
    HAL_GPIO_WriteToPin(port, pins, value);
}

int32_t POR_ReadFromSwitch(uint32_t port, uint8_t pins)
{
    return HAL_GPIO_ReadFromPin(port, pins);
}

