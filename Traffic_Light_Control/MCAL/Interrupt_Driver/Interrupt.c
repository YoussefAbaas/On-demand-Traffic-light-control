/*
 * Interrupt.c
 *
 *  Created on: Nov 9, 2022
 *      Author: Yousif
 */

#include "Interrupt.h"
#include "avr/io.h"
#include "avr/interrupt.h"


/* External INT0 enable and configuration function */
void INT0_Init(void)
{
	// Enable interrupts by setting I-bit
	SREG  |= (1<<7);
	// Trigger INT0 with the raising edge
	MCUCR |= (1<<ISC00) | (1<<ISC01);
    // Enable external interrupt pin INT0
	GICR  |= (1<<INT0);
}


