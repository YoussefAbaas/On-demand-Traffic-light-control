/*
 * Timer.h
 *
 *  Created on: Nov 9, 2022
 *      Author: Yousif
 */

#ifndef MCAL_TIMER_DRIVER_TIMER_H_
#define MCAL_TIMER_DRIVER_TIMER_H_
#include "../../Utilities/std_types.h"

//Definitions
#define MAX_NO_OF_OVERFLOWS 4
//Functions Prototypes
void Timer0_Init();
void Timer0_Start();
void Timer0_Stop();
void Timer0_Delay_InSeconds(uint8 seconds);

#endif /* MCAL_TIMER_DRIVER_TIMER_H_ */
