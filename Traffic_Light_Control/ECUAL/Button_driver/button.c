/*
 * button.c
 *
 *  Created on: Nov 8, 2022
 *      Author: Yousif
 */

#include "button.h"
#include "../../MCAL/GPIO_Driver/gpio.h"

uint8 Button_Init(uint8 port_num, uint8 pin_num)
{
//initialize button pin as input using Gpio driver
uint8 error=GPIO_Init(port_num, pin_num, PIN_INPUT);
return error;
}

uint8 Button_Read(uint8 port_num, uint8 pin_num,uint8 type,uint8* value)
{
//1.read button pin
uint8 pin_value;
uint8 error=GPIO_readPin(port_num, pin_num, &pin_value);
//2.check pin value with button connection type
if(error==E_OK)
{
if(pin_value==LOGIC_HIGH&&type==PULL_DOWN_BUTTON)
	*value=PRESSED;
else if(pin_value==LOGIC_LOW&&type==PULL_DOWN_BUTTON)
	*value=NOT_PRESSED;
else if(pin_value==LOGIC_HIGH&&type==PULL_UP_BUTTON)
	*value=PRESSED;
else if(pin_value==LOGIC_LOW&&type==PULL_UP_BUTTON)
	*value=NOT_PRESSED;
}
return error;
}

