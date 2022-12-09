#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*INT0 is on PD2
 *INT1 is on PD3
 *INT2 is on PB2*/

#define INT0 1
#define INT1 2
#define INT2 3

#define RISING_EDGE		 4
#define FALLING_EGDE	 5
#define LOW_LEVEL		 6
#define ON_CHANGE		 7

uint8 EXTI_u8SetSenseControl (uint8 Copy_u8INT_No, uint8 Copy_u8SenseControl);

uint8 EXTI_u8InterruptEnable(uint8 Copy_u8INT_No);
uint8 EXTI_u8InterruptDisEnable(uint8 Copy_u8INT_No);

#endif
