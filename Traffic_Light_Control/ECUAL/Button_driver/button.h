/*
 * button.h
 *
 *  Created on: Nov 8, 2022
 *      Author: Yousif
 */

#ifndef ECUAL_BUTTON_DRIVER_BUTTON_H_
#define ECUAL_BUTTON_DRIVER_BUTTON_H_

#include "../../Utilities/std_types.h"
#include "../../MCAL/Timer_Driver/Timer.h"
#include "../../MCAL/Interrupt_Driver/Interrupt.h"
#include "../../MCAL/GPIO_Driver/gpio.h"

//Definitions

#define NOT_PRESSED    0
#define PRESSED        1

#define PULL_UP_BUTTON   0
#define PULL_DOWN_BUTTON 1


//Functions Prototypes

uint8 Button_Init(uint8 port_num, uint8 pin_num);

uint8 Button_Read(uint8 port_num, uint8 pin_num,uint8 type,uint8* value);

#endif /* ECUAL_BUTTON_DRIVER_BUTTON_H_ */
