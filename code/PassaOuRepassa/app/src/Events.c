/*
 * Events.c
 *
 *  Created on: 2 de out de 2018
 *      Author: diogo
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Events.h"

/*******************************************************************************
 * Function Definitions
 ******************************************************************************/
void SWITCH_OnSwitchPressed(uint32_t arg_SwitchIndex)
{
    POR_SetFirstPressedSwitch(arg_SwitchIndex);
}