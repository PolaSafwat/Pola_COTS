/***********************************/
/***********************************/
/******  Author: Pola Safwat    ****/
/******  File: PORT_CFG.H		****/
/******  Version: 1.00          ****/
/***********************************/
/***********************************/

#ifndef PORT_cfg_H_
#define PORT_cfg_H_

/*Configure Pins directions, OPtions:   1- Input
										2-Output*/
#define PORTA_PIN0_DIR 		Input
#define PORTA_PIN1_DIR 		OUTPUT
#define PORTA_PIN2_DIR 		OUTPUT
#define PORTA_PIN3_DIR 		OUTPUT
#define PORTA_PIN4_DIR 		OUTPUT
#define PORTA_PIN5_DIR 		OUTPUT
#define PORTA_PIN6_DIR 		OUTPUT
#define PORTA_PIN7_DIR 		Input

#define PORTB_PIN0_DIR 		OUTPUT
#define PORTB_PIN1_DIR 		Input
#define PORTB_PIN2_DIR 		Input
#define PORTB_PIN3_DIR 		Input
#define PORTB_PIN4_DIR 		Input
#define PORTB_PIN5_DIR 		Input
#define PORTB_PIN6_DIR 		Input
#define PORTB_PIN7_DIR 		Input


#define PORTC_PIN0_DIR 		OUTPUT
#define PORTC_PIN1_DIR 		OUTPUT
#define PORTC_PIN2_DIR 		OUTPUT
#define PORTC_PIN3_DIR 		OUTPUT
#define PORTC_PIN4_DIR 		OUTPUT
#define PORTC_PIN5_DIR 		Input
#define PORTC_PIN6_DIR 		Input
#define PORTC_PIN7_DIR 		Input


#define PORTD_PIN0_DIR 		Input
#define PORTD_PIN1_DIR 		Input
#define PORTD_PIN2_DIR 		Input
#define PORTD_PIN3_DIR 		Input
#define PORTD_PIN4_DIR 		Input
#define PORTD_PIN5_DIR 		Input
#define PORTD_PIN6_DIR 		Input
#define PORTD_PIN7_DIR 		Input

/*Configure the initial value, options for input pin: 1- FLOATING
 * 													  2- PULLED_UP
 * 							   options of output pin: 1- LOW
 * 							   						  2- HIGH*/
#define PORTA_PIN0_INITIAL_VAL		FLOATING
#define PORTA_PIN1_INITIAL_VAL		LOW
#define PORTA_PIN2_INITIAL_VAL		LOW
#define PORTA_PIN3_INITIAL_VAL		LOW
#define PORTA_PIN4_INITIAL_VAL		LOW
#define PORTA_PIN5_INITIAL_VAL		LOW
#define PORTA_PIN6_INITIAL_VAL		LOW
#define PORTA_PIN7_INITIAL_VAL		FLOATING

#define PORTB_PIN0_INITIAL_VAL		LOW
#define PORTB_PIN1_INITIAL_VAL		FLOATING
#define PORTB_PIN2_INITIAL_VAL		FLOATING
#define PORTB_PIN3_INITIAL_VAL		FLOATING
#define PORTB_PIN4_INITIAL_VAL		FLOATING
#define PORTB_PIN5_INITIAL_VAL		FLOATING
#define PORTB_PIN6_INITIAL_VAL		FLOATING
#define PORTB_PIN7_INITIAL_VAL		FLOATING

#define PORTC_PIN0_INITIAL_VAL		LOW
#define PORTC_PIN1_INITIAL_VAL		LOW
#define PORTC_PIN2_INITIAL_VAL		LOW
#define PORTC_PIN3_INITIAL_VAL		LOW
#define PORTC_PIN4_INITIAL_VAL		FLOATING
#define PORTC_PIN5_INITIAL_VAL		FLOATING
#define PORTC_PIN6_INITIAL_VAL		FLOATING
#define PORTC_PIN7_INITIAL_VAL		FLOATING

#define PORTD_PIN0_INITIAL_VAL		FLOATING
#define PORTD_PIN1_INITIAL_VAL		FLOATING
#define PORTD_PIN2_INITIAL_VAL		FLOATING
#define PORTD_PIN3_INITIAL_VAL		FLOATING
#define PORTD_PIN4_INITIAL_VAL		FLOATING
#define PORTD_PIN5_INITIAL_VAL		FLOATING
#define PORTD_PIN6_INITIAL_VAL		FLOATING
#define PORTD_PIN7_INITIAL_VAL		FLOATING



#endif
