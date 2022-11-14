
#ifndef GPIO_H_
#define GPIO_H_

#include "../../Utilities/std_types.h"

//Definitions

#define PORTS_NUM              4
#define PINS_NUM               8

#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3

#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7

#define PIN_INPUT    0
#define PIN_OUTPUT   1

#define E_OK     1
#define E_NOT_OK 0


//Functions Prototypes

uint8 GPIO_Init(uint8 port_num, uint8 pin_num, uint8 direction);

uint8 GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value);

uint8 GPIO_readPin(uint8 port_num, uint8 pin_num,uint8* pin_value);

uint8 GPIO_togglePin(uint8 port_num, uint8 pin_num);

#endif /* GPIO_H_ */
