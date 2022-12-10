#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"

#include "DIO_interface.h"
#include "DCM_interface.h"
#include "DCM_priv.h"




uint8 DCM_u8RotateStatus(uint8 Copy_u8RotateStatus, const DCM_T *Copy_pu8DCMPtr)
{
	uint8 Local_u8ErrorState = OK;
	if (Copy_pu8DCMPtr != NULL)
	{
		if(Copy_u8RotateStatus == DCM_ROTATE_CLKWISE)
		{
			DIO_u8SetPinValue(Copy_pu8DCMPtr->DCM_PORT,Copy_pu8DCMPtr->DCM_PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(Copy_pu8DCMPtr->DCM_PORT,Copy_pu8DCMPtr->DCM_PIN2,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(Copy_pu8DCMPtr->DCM_PORT,Copy_pu8DCMPtr->DCM_PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(Copy_pu8DCMPtr->DCM_PORT,Copy_pu8DCMPtr->DCM_PIN2,DIO_u8PIN_LOW);
		}
		else if(Copy_u8RotateStatus == DCM_ROTATE_C_CLKWISE)
		{
			DIO_u8SetPinValue(Copy_pu8DCMPtr->DCM_PORT,Copy_pu8DCMPtr->DCM_PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(Copy_pu8DCMPtr->DCM_PORT,Copy_pu8DCMPtr->DCM_PIN2,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(Copy_pu8DCMPtr->DCM_PORT,Copy_pu8DCMPtr->DCM_PIN1,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(Copy_pu8DCMPtr->DCM_PORT,Copy_pu8DCMPtr->DCM_PIN2,DIO_u8PIN_HIGH);
		}
		else if(Copy_u8RotateStatus == DCM_STOP)
		{
			DIO_u8SetPinValue(Copy_pu8DCMPtr->DCM_PORT,Copy_pu8DCMPtr->DCM_PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(Copy_pu8DCMPtr->DCM_PORT,Copy_pu8DCMPtr->DCM_PIN2,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(Copy_pu8DCMPtr->DCM_PORT,Copy_pu8DCMPtr->DCM_PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(Copy_pu8DCMPtr->DCM_PORT,Copy_pu8DCMPtr->DCM_PIN2,DIO_u8PIN_HIGH);
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}
