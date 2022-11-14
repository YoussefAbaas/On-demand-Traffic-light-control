/*
 * app.h
 *
 *  Created on: Nov 9, 2022
 *      Author: Yousif
 */

#ifndef APP_APP_H_
#define APP_APP_H_

#include "../MCAL/GPIO_Driver/gpio.h"

//Definitions
#define CAR_LEDS_PORT PORTA_ID
#define CAR_GREEN_LED_PIN PIN0_ID
#define CAR_YELLOW_LED_PIN PIN1_ID
#define CAR_RED_LED_PIN PIN2_ID
#define PEDESTRIAN_LEDS_PORT PORTB_ID
#define PEDESTRIAN_GREEN_LED_PIN PIN0_ID
#define PEDESTRIAN_YELLOW_LED_PIN PIN1_ID
#define PEDESTRIAN_RED_LED_PIN PIN2_ID
#define BUTTON_PORT PORTD_ID
#define BUTTON_PIN PIN2_ID

//Functions Prototypes
void App_Init();
void App_Start();

#endif /* APP_APP_H_ */
