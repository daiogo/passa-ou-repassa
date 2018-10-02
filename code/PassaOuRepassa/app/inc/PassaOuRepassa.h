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
#define TURN_OFF    0
#define TURN_ON     1

#define RED_LED     GPIO_PIN_4

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void POR_Init(void);

void POR_Run(void);

void POR_InitSwitch(uint32_t port, uint8_t pins);

void POR_ConfigLed(uint32_t port, uint8_t pins);

void POR_WriteToLed(uint32_t port, uint8_t pins, uint8_t value);

int32_t POR_ReadFromSwitch(uint32_t port, uint8_t pins);

#endif /* APP_INC_PASSAOUREPASSA_H_ */
