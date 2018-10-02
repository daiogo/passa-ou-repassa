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
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);                                        // Enable port D
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);                                        // Enable port E
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);                                        // Enable port F

    // Configure switches
    POR_InitSwitch(GPIO_PORTD_BASE, GPIO_PIN_0);
    POR_InitSwitch(GPIO_PORTD_BASE, GPIO_PIN_1);
    POR_InitSwitch(GPIO_PORTD_BASE, GPIO_PIN_2);
    POR_InitSwitch(GPIO_PORTD_BASE, GPIO_PIN_3);

    // Configure LEDs
    POR_InitLed(GPIO_PORTE_BASE, GPIO_PIN_1);
    POR_InitLed(GPIO_PORTE_BASE, GPIO_PIN_2);
    POR_InitLed(GPIO_PORTE_BASE, GPIO_PIN_3);
    POR_InitLed(GPIO_PORTF_BASE, GPIO_PIN_1);
}

void POR_Run(void)
{

    while (1)
    {
        if (POR_ReadFromSwitch(GPIO_PORTD_BASE, GPIO_PIN_0) == GPIO_PIN_0)
        {
            POR_WriteToLed(GPIO_PORTE_BASE, GPIO_PIN_1, GPIO_PIN_1);
        }
        else if (POR_ReadFromSwitch(GPIO_PORTD_BASE, GPIO_PIN_1) == GPIO_PIN_1)
        {
            POR_WriteToLed(GPIO_PORTE_BASE, GPIO_PIN_2, GPIO_PIN_2);
        }
        else if (POR_ReadFromSwitch(GPIO_PORTD_BASE, GPIO_PIN_2) == GPIO_PIN_2)
        {
            POR_WriteToLed(GPIO_PORTE_BASE, GPIO_PIN_3, GPIO_PIN_3);
        }
        else if (POR_ReadFromSwitch(GPIO_PORTD_BASE, GPIO_PIN_3) == GPIO_PIN_3)
        {
            POR_WriteToLed(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
        }
        else
        {
            POR_WriteToLed(GPIO_PORTE_BASE, GPIO_PIN_1, 0);
            POR_WriteToLed(GPIO_PORTE_BASE, GPIO_PIN_2, 0);
            POR_WriteToLed(GPIO_PORTE_BASE, GPIO_PIN_3, 0);
            POR_WriteToLed(GPIO_PORTF_BASE, GPIO_PIN_1, 0);
        }

    }
}

void POR_InitSwitch(uint32_t port, uint8_t pins)
{
    HAL_GPIO_SetPinAsInput(port, pins);
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

