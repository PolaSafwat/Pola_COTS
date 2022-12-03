/**************************************************************/
/**************************************************************/
/*********		Author: Pola Safwat			*******************/
/*********		File: Stepper_program.c		*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>


#include "DIO_interface.h"

#include "Stepper_interface.h"




uint8 Stepper_u8Rotate(const Stepper_Motor_t* Copy_Stepper_Motor_Ptr, uint16 Copy_Stepper_Angle, uint8 Copy_Stepper_Direction)
{
	uint8 Local_Error_State = 1;
	if (Copy_Stepper_Motor_Ptr != NULL)
	{
		Local_Error_State = 0;

		uint16 Local_u16Counter;
		uint16 Local_u16_Steps;

		Local_u16_Steps = (uint16)(( (uint32)Copy_Stepper_Angle * 2048ul) / 360ul);

		if(Copy_Stepper_Direction == Stepper_Motor_ClOCK_WISE)
		{
			for(Local_u16Counter = 0 ; Local_u16Counter <Local_u16_Steps ; Local_u16Counter++)
			{
				if (Local_u16Counter%4==0)
				{
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Blue_Pin,DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Pink_Pin,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Yellow_Pin,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Orange_Pin,DIO_u8PIN_HIGH);
					_delay_ms(2);
				}

				else if (Local_u16Counter%4==1)
				{
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Blue_Pin,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Pink_Pin,DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Yellow_Pin,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Orange_Pin,DIO_u8PIN_HIGH);
					_delay_ms(2);
				}
				else if (Local_u16Counter%4==2)
				{
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Blue_Pin,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Pink_Pin,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Yellow_Pin,DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Orange_Pin,DIO_u8PIN_HIGH);
					_delay_ms(2);

				}

				else if (Local_u16Counter%4==3)
				{
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Blue_Pin,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Pink_Pin,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Yellow_Pin,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Orange_Pin,DIO_u8PIN_LOW);
					_delay_ms(2);
				}
			}
		}
		else if (Copy_Stepper_Direction == Stepper_Motor_COUNTER_CLOCK_WISE)
		{

			for(Local_u16Counter = 0 ; Local_u16Counter <Local_u16_Steps ; Local_u16Counter++)
			{
				if (Local_u16Counter%4==0)
				{
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Blue_Pin,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Pink_Pin,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Yellow_Pin,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Orange_Pin,DIO_u8PIN_LOW);
					_delay_ms(2);
				}

				else if (Local_u16Counter%4==1)
				{
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Blue_Pin,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Pink_Pin,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Yellow_Pin,DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Orange_Pin,DIO_u8PIN_HIGH);
					_delay_ms(2);
				}
				else if (Local_u16Counter%4==2)
				{
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Blue_Pin,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Pink_Pin,DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Yellow_Pin,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Orange_Pin,DIO_u8PIN_HIGH);
					_delay_ms(2);

				}

				else if (Local_u16Counter%4==3)
				{
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Blue_Pin,DIO_u8PIN_LOW);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Pink_Pin,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Yellow_Pin,DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_Stepper_Motor_Ptr->PORT,Copy_Stepper_Motor_Ptr->Orange_Pin,DIO_u8PIN_HIGH);
					_delay_ms(2);
				}
			}

		}
	}
	return Local_Error_State;
}
