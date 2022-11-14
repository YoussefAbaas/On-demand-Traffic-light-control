/*
 * Timer.c
 *
 *  Created on: Nov 9, 2022
 *      Author: Yousif
 */
#include "Timer.h"
#include "avr/io.h"
#include "../../Utilities/std_types.h"

uint8 no_of_overflows = 0;

void Timer0_Init() {
	//Setting timer configurations
	//1-choosing normal mode
	TCCR0 = (1 << FOC0);
	//2-set timer starting value of TCNT0 register
	TCNT0 = 0;
}
void Timer0_Start() {
	//setting prescaler
	//clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
	TCCR0 = (1 << CS02) | (1 << CS00);
}
void Timer0_Stop() {
	// Stop Timer0 by clear the Clock bits (CS00, CS01 and CS02)
	TCCR0 = 0;
}
void Timer0_Delay_InSeconds(uint8 seconds) {
	// F_CPU = 1000000 , clock = F_CPU/1024 so each tick takes 1ms
	// so overflow happens every 256ms
	// for 1 seconds we need 4 overflows
	for (int i = 0; i < seconds; i++) {
		while (no_of_overflows < MAX_NO_OF_OVERFLOWS) {
			while (!(TIFR & (1 << TOV0))); // Wait until the Timer0 Overflow occurs (wait until TOV0 = 1)
			TIFR |= (1 << TOV0); // Clear TOV0 bit by set its value
			no_of_overflows++;
		}
		no_of_overflows=0;
	}
}

