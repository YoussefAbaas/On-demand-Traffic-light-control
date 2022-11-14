/*
 * app.c
 *
 *  Created on: Nov 9, 2022
 *      Author: Yousif
 */

#ifndef APP_APP_C_
#define APP_APP_C_

#include "app.h"
#include "../ECUAL/Led_Driver/Led.h"
#include "../ECUAL/Button_driver/button.h"
#include "avr/interrupt.h"

uint8 normal_mode = 1; // 1 for normal mode 0 for pedestrain mode
uint8 prev_led; //0 for green 1 for yellow 2 for red

void App_Init() {
	Button_Init(BUTTON_PORT, BUTTON_PIN);
	LED_Init(CAR_LEDS_PORT, CAR_GREEN_LED_PIN);
	LED_Init(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
	LED_Init(CAR_LEDS_PORT, CAR_RED_LED_PIN);
	LED_Init(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_GREEN_LED_PIN);
	LED_Init(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_YELLOW_LED_PIN);
	LED_Init(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_RED_LED_PIN);
	Timer0_Init();
	INT0_Init();
}
void App_Start() {
	//check if system works in normal mode or not
	if (normal_mode) {
		Timer0_Start();
		LED_ON(CAR_LEDS_PORT, CAR_GREEN_LED_PIN);
		Timer0_Delay_InSeconds(5);
		prev_led = 0;
		if (!normal_mode)
			return;

		LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
		Timer0_Delay_InSeconds(1);
		prev_led = 1;
		if (!normal_mode)
		return;
		LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
		Timer0_Delay_InSeconds(1);
		if (!normal_mode)
		return;
		LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
		Timer0_Delay_InSeconds(1);
        if (!normal_mode)
		return;
		LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
		Timer0_Delay_InSeconds(1);
		if (!normal_mode)
		return;
		LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
		Timer0_Delay_InSeconds(1);
		if (!normal_mode)
		return;
		LED_OFF(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
		LED_OFF(CAR_LEDS_PORT, CAR_GREEN_LED_PIN);
		if (!normal_mode)
			return;

		LED_ON(CAR_LEDS_PORT, CAR_RED_LED_PIN);
		Timer0_Delay_InSeconds(5);
		prev_led = 2;
		if (!normal_mode)
			return;

		LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
		Timer0_Delay_InSeconds(1);
		prev_led = 1;
		if (!normal_mode)
		return;
		LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
		Timer0_Delay_InSeconds(1);
		if (!normal_mode)
		return;
		LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
		Timer0_Delay_InSeconds(1);
		if (!normal_mode)
		return;
		LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
		Timer0_Delay_InSeconds(1);
		if (!normal_mode)
		return;
		LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
		Timer0_Delay_InSeconds(1);
		if (!normal_mode)
		return;
		LED_OFF(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
		LED_OFF(CAR_LEDS_PORT, CAR_RED_LED_PIN);
		if (!normal_mode)
			return;

	} else {
		if (prev_led == 2) //car led was red
				{
			Timer0_Start();
			//car red led and pedestrain green led will be open for 5 seconds
			LED_ON(CAR_LEDS_PORT, CAR_RED_LED_PIN);
			LED_ON(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_GREEN_LED_PIN);
			Timer0_Delay_InSeconds(5);
			LED_OFF(CAR_LEDS_PORT, CAR_RED_LED_PIN);
			//pedestrain green led will still be open and two yellow leds will blink for 5 seconds
			LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
			LED_Toggle(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_YELLOW_LED_PIN);
			Timer0_Delay_InSeconds(1);
			LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
			LED_Toggle(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_YELLOW_LED_PIN);
			Timer0_Delay_InSeconds(1);
			LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
			LED_Toggle(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_YELLOW_LED_PIN);
			Timer0_Delay_InSeconds(1);
			LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
			LED_Toggle(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_YELLOW_LED_PIN);
			Timer0_Delay_InSeconds(1);
			LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
			LED_Toggle(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_YELLOW_LED_PIN);
			Timer0_Delay_InSeconds(1);
			LED_OFF(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
			LED_OFF(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_YELLOW_LED_PIN);
			//pedestrain led green will be off and both pedestrain red led and cars green led will be open
			LED_OFF(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_GREEN_LED_PIN);
			LED_ON(CAR_LEDS_PORT, CAR_GREEN_LED_PIN);
			LED_ON(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_RED_LED_PIN);
			Timer0_Delay_InSeconds(1);
			LED_OFF(CAR_LEDS_PORT, CAR_GREEN_LED_PIN);
			LED_OFF(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_RED_LED_PIN);
			normal_mode = 1;
		} else //car led was yellow or green
		{
			Timer0_Start();
			// pedestrain red led will be on then both yellow leds start to blink for 5 seconds
			LED_ON(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_RED_LED_PIN);
			LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
			LED_Toggle(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_YELLOW_LED_PIN);
			Timer0_Delay_InSeconds(1);
			LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
			LED_Toggle(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_YELLOW_LED_PIN);
			Timer0_Delay_InSeconds(1);
			LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
			LED_Toggle(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_YELLOW_LED_PIN);
			Timer0_Delay_InSeconds(1);
			LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
			LED_Toggle(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_YELLOW_LED_PIN);
			Timer0_Delay_InSeconds(1);
			LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
			LED_Toggle(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_YELLOW_LED_PIN);
			Timer0_Delay_InSeconds(1);
			LED_OFF(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_RED_LED_PIN);
			LED_OFF(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
			LED_OFF(CAR_LEDS_PORT, CAR_GREEN_LED_PIN);
			LED_OFF(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_YELLOW_LED_PIN);
			//then car led red and pedestrain green led will be on for 5 seconds
			LED_ON(CAR_LEDS_PORT, CAR_RED_LED_PIN);
			LED_ON(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_GREEN_LED_PIN);
			Timer0_Delay_InSeconds(5);
			LED_OFF(CAR_LEDS_PORT, CAR_RED_LED_PIN);
			//pedestrain green led will still be open and two yellow leds will blink for 5 seconds
			LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
			LED_Toggle(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_YELLOW_LED_PIN);
			Timer0_Delay_InSeconds(1);
			LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
			LED_Toggle(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_YELLOW_LED_PIN);
			Timer0_Delay_InSeconds(1);
			LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
			LED_Toggle(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_YELLOW_LED_PIN);
			Timer0_Delay_InSeconds(1);
			LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
			LED_Toggle(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_YELLOW_LED_PIN);
			Timer0_Delay_InSeconds(1);
			LED_Toggle(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
			LED_Toggle(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_YELLOW_LED_PIN);
			Timer0_Delay_InSeconds(1);
			LED_OFF(CAR_LEDS_PORT, CAR_YELLOW_LED_PIN);
			LED_OFF(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_YELLOW_LED_PIN);
			//pedestrain led green will be off and both pedestrain red led and cars green led will be open
			LED_OFF(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_GREEN_LED_PIN);
			LED_ON(CAR_LEDS_PORT, CAR_GREEN_LED_PIN);
			LED_ON(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_RED_LED_PIN);
			Timer0_Delay_InSeconds(1);
			LED_OFF(CAR_LEDS_PORT, CAR_GREEN_LED_PIN);
			LED_OFF(PEDESTRIAN_LEDS_PORT, PEDESTRIAN_RED_LED_PIN);
			normal_mode = 1;
		}

	}

}

ISR(INT0_vect) {
	//button is pressed
	normal_mode = 0;
}

#endif /* APP_APP_C_ */
