/**************************************/
/**************************************/
/******  Author: Pola Safwat       ****/
/******  File: Stepper_interface.h ****/
/******  Version: 1.00          *******/
/**************************************/
/**************************************/

#ifndef STEPPER_interface_H_
#define STEPPER_interface_H_

#define Stepper_Motor_ClOCK_WISE				1u
#define Stepper_Motor_COUNTER_CLOCK_WISE		2u

typedef struct{
	uint8 PORT;
	uint8 Blue_Pin;
	uint8 Pink_Pin;
	uint8 Yellow_Pin;
	uint8 Orange_Pin;
}Stepper_Motor_t;

uint8 Stepper_u8Rotate(const Stepper_Motor_t* Copy_Stepper_Motor_Ptr, uint16 Copy_Stepper_Angle, uint8 Copy_Stepper_Direction);


#endif
