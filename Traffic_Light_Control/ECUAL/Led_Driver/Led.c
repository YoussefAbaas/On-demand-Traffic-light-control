/*
 * Led.c
 *
 *  Created on: Nov 8, 2022
 *      Author: Yousif
 */

#include "../../MCAL/GPIO_Driver/gpio.h"

uint8 LED_Init(uint8 port_num, uint8 pin_num) {
	//initialize led pin as output pin
	uint8 error=GPIO_Init(port_num, pin_num, PIN_OUTPUT);
	return error;
}

uint8 LED_ON(uint8 port_num, uint8 pin_num) {
	// write logic 1 to led pin
	uint8 error=GPIO_writePin(port_num, pin_num, LOGIC_HIGH);
	return error;
}

uint8 LED_OFF(uint8 port_num, uint8 pin_num) {
	//write logic 0 to led pin
	uint8 error=GPIO_writePin(port_num, pin_num, LOGIC_LOW);
	return error;
}

uint8 LED_Toggle(uint8 port_num, uint8 pin_num) {
	//toggle led pin
	uint8 error=GPIO_togglePin(port_num, pin_num);
	return error;
}

//void LED_Blink(uint8 port_num, uint8 pin_num);
