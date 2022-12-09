#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_cfg.h"
#include "EXTI_interface.h"
#include "EXTI_piv.h"
#include "EXTI_reg.h"

uint8 EXTI_u8SetSenseControl (uint8 Copy_u8INT_No, uint8 Copy_u8SenseControl)
{
	uint8 Local_u8ErrorState = 1;
	if (Copy_u8INT_No == INT0 && Copy_u8SenseControl == RISING_EDGE)
	{
		Local_u8ErrorState = 0;
		SET_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
	}
	else if (Copy_u8INT_No == INT0 && Copy_u8SenseControl == FALLING_EGDE)
	{
		Local_u8ErrorState = 0;
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
	}
	else if (Copy_u8INT_No == INT0 && Copy_u8SenseControl == ON_CHANGE)
	{
		Local_u8ErrorState = 0;
		SET_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
	}
	else if (Copy_u8INT_No == INT0 && Copy_u8SenseControl == LOW_LEVEL)
	{
		Local_u8ErrorState = 0;
		CLR_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
	}
	/**INT1**/
	else if (Copy_u8INT_No == INT1 && Copy_u8SenseControl == RISING_EDGE)
	{
		Local_u8ErrorState = 0;
		SET_BIT(MCUCR,2);
		SET_BIT(MCUCR,3);
	}
	else if (Copy_u8INT_No == INT1 && Copy_u8SenseControl == FALLING_EGDE)
	{
		Local_u8ErrorState = 0;
		CLR_BIT(MCUCR,2);
		SET_BIT(MCUCR,3);
	}
	else if (Copy_u8INT_No == INT1 && Copy_u8SenseControl == ON_CHANGE)
	{
		Local_u8ErrorState = 0;
		SET_BIT(MCUCR,2);
		CLR_BIT(MCUCR,3);
	}
	else if (Copy_u8INT_No == INT1 && Copy_u8SenseControl == LOW_LEVEL)
	{
		Local_u8ErrorState = 0;
		CLR_BIT(MCUCR,2);
		CLR_BIT(MCUCR,3);
	}

	/**INT2**/
	else if (Copy_u8INT_No == INT2 && Copy_u8SenseControl == RISING_EDGE)
	{
		Local_u8ErrorState = 0;
		SET_BIT(MCUCSR,6);
	}
	else if (Copy_u8INT_No == INT2 && Copy_u8SenseControl == FALLING_EGDE)
	{
		Local_u8ErrorState = 0;
		CLR_BIT(MCUCSR,6);
	}

	return Local_u8ErrorState;
}


uint8 EXTI_u8InterruptEnable(uint8 Copy_u8INT_No)
{
	uint8 Local_u8ErrorState = 1;
	if (Copy_u8INT_No == INT0)
	{
		Local_u8ErrorState =0;
		SET_BIT(GICR,6);
	}
	else if (Copy_u8INT_No == INT1)
	{
		Local_u8ErrorState = 0;
		SET_BIT(GICR,7);
	}
	else if (Copy_u8INT_No == INT2)
	{
		Local_u8ErrorState = 0;
		SET_BIT(GICR,5);

	}
	return Local_u8ErrorState;
}


uint8 EXTI_u8InterruptDisEnable(uint8 Copy_u8INT_No)
{
	uint8 Local_u8ErrorState = 1;
	if (Copy_u8INT_No == INT0)
	{
		Local_u8ErrorState =0;
		CLR_BIT(GICR,6);
	}
	else if (Copy_u8INT_No == INT1)
	{
		Local_u8ErrorState = 0;
		CLR_BIT(GICR,7);
	}
	else if (Copy_u8INT_No == INT2)
	{
		Local_u8ErrorState = 0;
		CLR_BIT(GICR,5);

	}
	return Local_u8ErrorState;
}
