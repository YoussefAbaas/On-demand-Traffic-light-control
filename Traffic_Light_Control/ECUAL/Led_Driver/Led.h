/*
 * Led.h
 *
 *  Created on: Nov 8, 2022
 *      Author: Yousif
 */

#ifndef ECUAL_LED_DRIVER_LED_H_
#define ECUAL_LED_DRIVER_LED_H_

#include "../../Utilities/std_types.h"
#include "../../MCAL/Timer_Driver/Timer.h"
#include "../../MCAL/Interrupt_Driver/Interrupt.h"
#include "../../MCAL/GPIO_Driver/gpio.h"

//Definitions

#define LED_LOW    0
#define LED_HIGH   1


//Functions Prototypes

uint8 LED_Init(uint8 port_num, uint8 pin_num);

uint8 LED_ON(uint8 port_num, uint8 pin_num);

uint8 LED_OFF(uint8 port_num, uint8 pin_num);

uint8 LED_Toggle(uint8 port_num, uint8 pin_num);



#endif /* ECUAL_LED_DRIVER_LED_H_ */
