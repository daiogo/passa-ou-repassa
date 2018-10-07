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
 * Global variables
 ******************************************************************************/
state_t glb_FsmState;      // FSM state

/*******************************************************************************
 * Function Definitions
 ******************************************************************************/
void POR_Init(void)
{
    // Board hardware init
    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);   // Set up the clock
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);                                        // Enable port B
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);                                        // Enable port D
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);                                        // Enable port E
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);                                        // Enable port F

    // Init switches
    POR_InitSwitch(SWITCHES_PORT, SW0);
    POR_InitSwitch(SWITCHES_PORT, SW1);
    POR_InitSwitch(SWITCHES_PORT, SW2);
    POR_InitSwitch(SWITCHES_PORT, SW3);
    POR_InitSwitch(RESET_PORT, RESET_SWITCH);

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
        // Classic infinite loop
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
    HAL_GPIO_SetInterruptType(SWITCHES_PORT, ALL_SWITCHES, INTERRUPT_TYPE);
    HAL_GPIO_SetInterruptType(RESET_PORT, RESET_SWITCH, INTERRUPT_TYPE);

    HAL_GPIO_RegisterInterruptHandler(SWITCHES_PORT, HAL_GPIO_IrqHandlerPortD);
    HAL_GPIO_RegisterInterruptHandler(RESET_PORT, HAL_GPIO_IrqHandlerPortB);

    HAL_GPIO_EnableInterrupts(SWITCHES_PORT, ALL_SWITCHES);
    HAL_GPIO_EnableInterrupts(RESET_PORT, RESET_SWITCH);
}

void POR_SetState(uint32_t arg_SwitchIndex)
{
    switch (arg_SwitchIndex)
    {
        case SW0:
            if (glb_FsmState == IDLE)
            {
                POR_WriteToLed(LED0_PORT, LED0, LED0);
                glb_FsmState = SW0_PRESSED;
            }
            break;
        case SW1:
            if (glb_FsmState == IDLE)
            {
                POR_WriteToLed(LED1_PORT, LED1, LED1);
                glb_FsmState = SW1_PRESSED;
            }
            break;
        case SW2:
            if (glb_FsmState == IDLE)
            {
                POR_WriteToLed(LED2_PORT, LED2, LED2);
                glb_FsmState = SW2_PRESSED;
            }
            break;
        case SW3:
            if (glb_FsmState == IDLE)
            {
                POR_WriteToLed(LED3_PORT, LED3, LED3);
                glb_FsmState = SW3_PRESSED;
            }
            break;
        default:    // Reset case
            POR_WriteToLed(LED0_PORT, LED0, OFF);
            POR_WriteToLed(LED1_PORT, LED1, OFF);
            POR_WriteToLed(LED2_PORT, LED2, OFF);
            POR_WriteToLed(LED3_PORT, LED3, OFF);
            glb_FsmState = IDLE;
            break;
    }
}

