/*
 * PassaOuRepassa.h
 *
 *  Created on: 30 de set de 2018
 *      Author: diogo
 */

#ifndef APP_INC_PASSAOUREPASSA_H_
#define APP_INC_PASSAOUREPASSA_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hal_gpio.h"
#include "driverlib/sysctl.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define OFF             0x00

#define SW0             GPIO_PIN_0
#define SW1             GPIO_PIN_1
#define SW2             GPIO_PIN_2
#define SW3             GPIO_PIN_3
#define ALL_SWITCHES    GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3
#define SWITCHES_PORT   GPIO_PORTD_BASE

#define LED0            GPIO_PIN_1
#define LED1            GPIO_PIN_2
#define LED2            GPIO_PIN_3
#define LED3            GPIO_PIN_1
#define LED0_PORT       GPIO_PORTE_BASE
#define LED1_PORT       GPIO_PORTE_BASE
#define LED2_PORT       GPIO_PORTE_BASE
#define LED3_PORT       GPIO_PORTF_BASE

#define INTERRUPT_TYPE  GPIO_BOTH_EDGES

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void POR_Init(void);

void POR_Run(void);

void POR_InitSwitch(uint32_t arg_Port, uint8_t arg_Pins);

void POR_InitLed(uint32_t arg_Port, uint8_t arg_Pins);

void POR_WriteToLed(uint32_t arg_Port, uint8_t arg_Pins, uint8_t arg_Value);

int32_t POR_ReadFromSwitch(uint32_t arg_Port, uint8_t arg_Pins);

void POR_SetInterrupts(void);

void POR_SetFirstPressedSwitch(uint32_t arg_SwitchIndex);

#endif /* APP_INC_PASSAOUREPASSA_H_ */
