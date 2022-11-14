#include "../GPIO_Driver/gpio.h"

#include "../../Utilities/common_macros.h"
#include "avr/io.h"

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request and return error
 */
uint8 GPIO_Init(uint8 port_num, uint8 pin_num, uint8 direction) {
	// Check if there is error in port or pin number
	if (port_num >= PORTS_NUM || pin_num >= PINS_NUM)
		return E_NOT_OK;
	/* Setup the pin direction as required*/
	switch (port_num) {
	case PORTA_ID:
		if (direction == PIN_OUTPUT) {
			SET_BIT(DDRA, pin_num);
		} else {
			CLEAR_BIT(DDRA, pin_num);
		}
		break;
	case PORTB_ID:
		if (direction == PIN_OUTPUT) {
			SET_BIT(DDRB, pin_num);
		} else {
			CLEAR_BIT(DDRB, pin_num);
		}
		break;
	case PORTC_ID:
		if (direction == PIN_OUTPUT) {
			SET_BIT(DDRC, pin_num);
		} else {
			CLEAR_BIT(DDRC, pin_num);
		}
		break;
	case PORTD_ID:
		if (direction == PIN_OUTPUT) {
			SET_BIT(DDRD, pin_num);
		} else {
			CLEAR_BIT(DDRD, pin_num);
		}
		break;
	}
	return E_OK;
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request and returns error
 */
uint8_t GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value) {

	// Check if there is error in port or pin number
	if (port_num >= PORTS_NUM || pin_num >= PINS_NUM)
		return E_NOT_OK;

	/* Write the pin value as required */
	switch (port_num) {
	case PORTA_ID:
		if (value == LOGIC_HIGH) {
			SET_BIT(PORTA, pin_num);
		} else {
			CLEAR_BIT(PORTA, pin_num);
		}
		break;
	case PORTB_ID:
		if (value == LOGIC_HIGH) {
			SET_BIT(PORTB, pin_num);
		} else {
			CLEAR_BIT(PORTB, pin_num);
		}
		break;
	case PORTC_ID:
		if (value == LOGIC_HIGH) {
			SET_BIT(PORTC, pin_num);
		} else {
			CLEAR_BIT(PORTC, pin_num);
		}
		break;
	case PORTD_ID:
		if (value == LOGIC_HIGH) {
			SET_BIT(PORTD, pin_num);
		} else {
			CLEAR_BIT(PORTD, pin_num);
		}
		break;
	}
	return E_OK;
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return error
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num, uint8 *pin_value) {
	// Check if there is error in port or pin number
	if (port_num >= PORTS_NUM || pin_num >= PINS_NUM)
		return E_NOT_OK;

	/* Read the pin value as required */
	switch (port_num) {
	case PORTA_ID:
		if (BIT_IS_SET(PINA, pin_num)) {
			*pin_value = LOGIC_HIGH;
		} else {
			*pin_value = LOGIC_LOW;
		}
		break;
	case PORTB_ID:
		if (BIT_IS_SET(PINB, pin_num)) {
			*pin_value = LOGIC_HIGH;
		} else {
			*pin_value = LOGIC_LOW;
		}
		break;
	case PORTC_ID:
		if (BIT_IS_SET(PINC, pin_num)) {
			*pin_value = LOGIC_HIGH;
		} else {
			*pin_value = LOGIC_LOW;
		}
		break;
	case PORTD_ID:
		if (BIT_IS_SET(PIND, pin_num)) {
			*pin_value = LOGIC_HIGH;
		} else {
			*pin_value = LOGIC_LOW;
		}
		break;
	}
	return E_OK;
}
/*
 * * Description :
 *  toggle the required pin.
 *  If the input port number or pin number are not correct, The function will not handle the request and returns error
 */
uint8 GPIO_togglePin(uint8 port_num, uint8 pin_num) {
	// Check if there is error in port or pin number
	if (port_num >= PORTS_NUM || pin_num >= PINS_NUM)
		return E_NOT_OK;

	/* toggle the pin as required*/
	switch (port_num) {
	case PORTA_ID:
		TOGGLE_BIT(PORTA, pin_num);
		break;
	case PORTB_ID:
		TOGGLE_BIT(PORTB, pin_num);
		break;
	case PORTC_ID:
		TOGGLE_BIT(PORTC, pin_num);
		break;
	case PORTD_ID:
		TOGGLE_BIT(PORTD, pin_num);
		break;
	}
	return E_OK;
}
