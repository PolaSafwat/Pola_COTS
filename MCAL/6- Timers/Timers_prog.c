#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"

#include "Timers_cfg.h"
#include "Timers_interface.h"
#include "Timers_priv.h"
#include "Timers_reg.h"

static void (*TIMERS_pvCallBackFuncArr[8])(void) = {NULL};
static void (*ICU_CallBackFunc)(void) = NULL;


void Timer0_voidInit(void)
{
	/*wave form generation made:Fast PWM*/
	SET_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);

	/*Adjust pre-scaler*/
	TCCR0 &= PRESCALER_MASK;
	TCCR0 |= DIVISION_BY_64;

	/*CLR ON Compare SET ON Top*/
	CLR_BIT(TCCR0, TCCR0_COM00);
	SET_BIT(TCCR0, TCCR0_COM01);

}

void Timer1_voidInit(void)
{
	/*wave form generation mode:Fast PWM ICR1 as TOP*/
	/*CLR_BIT(TCCR1A, TCCR1A_WGM10);
	SET_BIT(TCCR1A, TCCR1A_WGM11);
	SET_BIT(TCCR1B, TCCR1B_WGM12);
	SET_BIT(TCCR1B, TCCR1B_WGM13);*/

	/*Set Timer1 to work in normal mode*/
	CLR_BIT(TCCR1A, TCCR1A_COM1A0);
	CLR_BIT(TCCR1A, TCCR1A_COM1A1);

	CLR_BIT(TCCR1A, TCCR1A_WGM10);
	CLR_BIT(TCCR1A, TCCR1A_WGM11);
	CLR_BIT(TCCR1B, TCCR1B_WGM12);
	CLR_BIT(TCCR1B, TCCR1B_WGM13);



	/*Adjust Prescaler to be 64*/
	SET_BIT(TCCR1B, TCCR1B_CS10);
	SET_BIT(TCCR1B, TCCR1B_CS11);
	CLR_BIT(TCCR1B, TCCR1B_CS12);

	/*SET ON TOP CLR ON COMP*/
	/*CLR_BIT(TCCR1A, TCCR1A_COM1A0);
	SET_BIT(TCCR1A, TCCR1A_COM1A1);

	ICR1 = 40000;*/

}

uint8 Timers_u8SetCallBack(Timers_Int_Src_t Copy_u8TmrIntSource, void(*copy_pvCallBackFunc)(void))
{
	uint8 Local_u8ERROR_State = OK;
	if(copy_pvCallBackFunc != NULL)
	{
		TIMERS_pvCallBackFuncArr[Copy_u8TmrIntSource] = copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ERROR_State = NOK;
	}

	return Local_u8ERROR_State;
}

void __vector_10(void) __attribute((signal));
void __vector_10(void)
{
	if(TIMERS_pvCallBackFuncArr[TIMER0_COMP] != NULL)
	{
		TIMERS_pvCallBackFuncArr[TIMER0_COMP]();
	}
}

void Timer0_voidSetCompValue(uint8 Copy_u8Val)
{
	OCR0 = Copy_u8Val;
}

void Timer1_voidSetCompValue(uint16 Copy_u16Val)
{
	OCR1A = Copy_u16Val;
}

uint16 Timer1_u16GetTCNT1Value(void)
{
	return TCNT1;
}

void Timer1_u16SetTCNT1Value(uint16 Copy_u16Value)
{
	TCNT1 = Copy_u16Value;
}



void Timer1_voidSetTriggerSRC(uint8 Copy_u8TriggerSRC)
{
	if(Copy_u8TriggerSRC == Timer1_ICU_TriggerSRC_Rising)
	{
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else
	{
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
	}
}


void Timer1_voidICU_Init(void)
{
	/*Set the trigger source as Rising edge*/
	SET_BIT(TCCR1B,TCCR1B_ICES1);

	/*Enable the ICU interrupt*/
	SET_BIT(TIMSK,TIMSK_TICIE1);
}


void Timer1_voidICU_Enabled(void)
{
	SET_BIT(TIMSK,TIMSK_TICIE1);
}

void Timer1_voidICU_Disabled(void)
{
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}

uint16 Timer1_u16GetInCapVal(void)
{
	return ICR1;
}


uint8 Timer1_u8ICU_SetCallBack(void(*copy_pvICU_CallBackFunc)(void))
{
	uint8 Local_u8ERROR_State = OK;
	if(copy_pvICU_CallBackFunc != NULL)
	{
		ICU_CallBackFunc = copy_pvICU_CallBackFunc;
	}
	else
	{
		Local_u8ERROR_State = NOK;
	}

	return Local_u8ERROR_State;
}

/*ICU interrupt ISR*/
void __vector_6(void) __attribute((signal));
void __vector_6(void)
{
	/*Read ICR1*/
	ICU_CallBackFunc();
}
