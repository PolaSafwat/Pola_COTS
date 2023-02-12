#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"

#include "Timers_cfg.h"
#include "Timers_interface.h"
#include "Timers_priv.h"
#include "Timers_reg.h"



static void (*TIMERS_pvCallBackFuncArr[8])(void) = {NULL};




/*********************************************************************************************************************/
void Timer0_voidInit_CFG(void)
{
#if TIMER0_2_WFGen_Mode == TIMER0_2_WFGen_Mode_NORMAL
	CLR_BIT(TCCR0, TCCR0_WGM00);
	CLR_BIT(TCCR0, TCCR0_WGM01);

#elif TIMER0_2_WFGen_Mode == TIMER0_2_WFGen_Mode_CTC
	CLR_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);

#elif TIMER0_2_WFGen_Mode == TIMER0_2_WFGen_Mode_FAST_PWM
	SET_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);

#elif TIMER0_2_WFGen_Mode == TIMER0_2_WFGen_Mode_PHASE_CORR
	SET_BIT(TCCR0, TCCR0_WGM00);
	CLR_BIT(TCCR0, TCCR0_WGM01);

#endif

	TCCR0 &= TIMER0_1_2_PRESCALER_MASK;
#if TIMER_Prescaler == Timer_PRESCALER_CLK_1
	TCCR0 |= TIMER0_1_DIVISION_BY_1;

#elif TIMER_Prescaler == Timer_PRESCALER_CLK_8
	TCCR0 |= TIMER0_1_DIVISION_BY_8;

#elif TIMER_Prescaler == Timer_PRESCALER_CLK_64
	TCCR0 |= TIMER0_1_DIVISION_BY_64;

#elif TIMER_Prescaler == Timer_PRESCALER_CLK_56
	TCCR0 |= TIMER0_1_DIVISION_BY_256;

#elif TIMER_Prescaler == Timer_PRESCALER_CLK_1024
	TCCR0 |= TIMER0_1_DIVISION_BY_1024;

#endif


#if TIMER_OUT_0_2_COMP == TIMER_OUT_0_2_COMP_NORMAL
	CLR_BIT(TCCR0, TCCR0_COM00);
	CLR_BIT(TCCR0, TCCR0_COM01);

#elif TIMER_OUT_0_2_COMP == TIMER_OUT_0_2_COMP_CTC_SET_PIN
	SET_BIT(TCCR0, TCCR0_COM00);
	SET_BIT(TCCR0, TCCR0_COM01);

#elif TIMER_OUT_0_2_COMP == TIMER_OUT_0_2_COMP_CTC_CLR_PIN
	CLR_BIT(TCCR0, TCCR0_COM00);
	SET_BIT(TCCR0, TCCR0_COM01);

#elif TIMER_OUT_0_2_COMP == TIMER_OUT_0_2_COMP_CTC_TOG_PIN
	SET_BIT(TCCR0, TCCR0_COM00);
	CLR_BIT(TCCR0, TCCR0_COM01);

#elif TIMER_OUT_0_2_COMP == TIMER_OUT_0_2_COMP_FAST_PWM_INVERTED_MODE
	SET_BIT(TCCR0, TCCR0_COM00);
	SET_BIT(TCCR0, TCCR0_COM01);

#elif TIMER_OUT_0_2_COMP == TIMER_OUT_0_2_COMP_FAST_PWM_NON_INVERTED_MODE
	CLR_BIT(TCCR0, TCCR0_COM00);
	SET_BIT(TCCR0, TCCR0_COM01);

#elif TIMER_OUT_0_2_COMP == TIMER_OUT_0_2_COMP_PHASE_CORR_INVERTED_MODE
	SET_BIT(TCCR0, TCCR0_COM00);
	SET_BIT(TCCR0, TCCR0_COM01);

#elif TIMER_OUT_0_2_COMP == TIMER_OUT_0_2_COMP_PHASE_CORR_NON_INVERTED_MODE
	CLR_BIT(TCCR0, TCCR0_COM00);
	SET_BIT(TCCR0, TCCR0_COM01);

#endif
}

/***********************************************************************************************************************/

void Timer0_voidInit(Timer0_CFG_t* Timer0)
{
	if (Timer0->WFG_MODE == TIMER_0_2_NORMAL)
	{
		CLR_BIT(TCCR0, TCCR0_WGM00);
		CLR_BIT(TCCR0, TCCR0_WGM01);
	}

	else if (Timer0->WFG_MODE == TIMER_0_2_CTC)
	{
		CLR_BIT(TCCR0, TCCR0_WGM00);
		SET_BIT(TCCR0, TCCR0_WGM01);
	}

	else if (Timer0->WFG_MODE == TIMER_0_2_FAST_PWM)
	{
		SET_BIT(TCCR0, TCCR0_WGM00);
		SET_BIT(TCCR0, TCCR0_WGM01);
	}

	else if (Timer0->WFG_MODE == TIMER_0_2_PHASE_CORR)
	{
		SET_BIT(TCCR0, TCCR0_WGM00);
		CLR_BIT(TCCR0, TCCR0_WGM01);
	}


	TCCR0 &= TIMER0_1_2_PRESCALER_MASK;

	if (Timer0->Prescaler == Timer_0_1_PRESCALER_CLK_1)
	{
		TCCR0 |= TIMER0_1_DIVISION_BY_1;
	}

	else if (Timer0->Prescaler == Timer_0_1_PRESCALER_CLK_8)
	{
		TCCR0 |= TIMER0_1_DIVISION_BY_8;
	}

	else if (Timer0->Prescaler == Timer_0_1_PRESCALER_CLK_64)
	{
		TCCR0 |= TIMER0_1_DIVISION_BY_64;
	}

	else if (Timer0->Prescaler == Timer_0_1_PRESCALER_CLK_256)
	{
		TCCR0 |= TIMER0_1_DIVISION_BY_256;
	}

	else if (Timer0->Prescaler == Timer_0_1_PRESCALER_CLK_1024)
	{
		TCCR0 |= TIMER0_1_DIVISION_BY_1024;
	}



	if (Timer0->OC_MODE == TIMER_0_2_NORMAL_OUT)
	{
		CLR_BIT(TCCR0, TCCR0_COM00);
		CLR_BIT(TCCR0, TCCR0_COM01);
	}

	else if (Timer0->OC_MODE == TIMER_0_2_CTC_SET_PIN)
	{
		SET_BIT(TCCR0, TCCR0_COM00);
		SET_BIT(TCCR0, TCCR0_COM01);
	}

	else if (Timer0->OC_MODE == TIMER_0_2_CTC_CLR_PIN)
	{
		CLR_BIT(TCCR0, TCCR0_COM00);
		SET_BIT(TCCR0, TCCR0_COM01);
	}

	else if (Timer0->OC_MODE  == TIMER_0_2_CTC_TOG_PIN)
	{
		SET_BIT(TCCR0, TCCR0_COM00);
		CLR_BIT(TCCR0, TCCR0_COM01);
	}

	else if (Timer0->OC_MODE == TIMER_0_2_FAST_PWM_INVERTED_MODE)
	{
		SET_BIT(TCCR0, TCCR0_COM00);
		SET_BIT(TCCR0, TCCR0_COM01);
	}

	else if (Timer0->OC_MODE == TIMER_0_2_FAST_PWM_NON_INVERTED_MODE)
	{
		CLR_BIT(TCCR0, TCCR0_COM00);
		SET_BIT(TCCR0, TCCR0_COM01);
	}

	else if (Timer0->OC_MODE == TIMER_0_2_PHASE_CORR_INVERTED_MODE)
	{
		SET_BIT(TCCR0, TCCR0_COM00);
		SET_BIT(TCCR0, TCCR0_COM01);
	}

	else if (Timer0->OC_MODE == TIMER_0_2_PHASE_CORR_NON_INVERTED_MODE)
	{
		CLR_BIT(TCCR0, TCCR0_COM00);
		SET_BIT(TCCR0, TCCR0_COM01);
	}
}


/***********************************************************************************************************************/



void Timer2_voidInit_CFG(void)
{
#if TIMER0_2_WFGen_Mode == TIMER0_2_WFGen_Mode_NORMAL
	CLR_BIT(TCCR2, TCCR2_WGM20);
	CLR_BIT(TCCR2, TCCR2_WGM21);

#elif TIMER0_2_WFGen_Mode == TIMER0_2_WFGen_Mode_CTC
	CLR_BIT(TCCR2, TCCR2_WGM20);
	SET_BIT(TCCR2, TCCR2_WGM21);

#elif TIMER0_2_WFGen_Mode == TIMER0_2_WFGen_Mode_FAST_PWM
	SET_BIT(TCCR2, TCCR2_WGM20);
	SET_BIT(TCCR2, TCCR2_WGM21);

#elif TIMER0_2_WFGen_Mode == TIMER0_2_WFGen_Mode_PHASE_CORR
	SET_BIT(TCCR2, TCCR2_WGM20);
	CLR_BIT(TCCR2, TCCR2_WGM21);

#endif


	TCCR2 &= TIMER0_1_2_PRESCALER_MASK;
#if TIMER_Prescaler == Timer_PRESCALER_CLK_1
	TCCR2 |= TIMER2_DIVISION_BY_1;

#elif TIMER_Prescaler == Timer_PRESCALER_CLK_8
	TCCR2 |= TIMER2_DIVISION_BY_8;

#elif TIMER_Prescaler == Timer_PRESCALER_CLK_32
	TCCR2 |= TIMER2_DIVISION_BY_32;

#elif TIMER_Prescaler == Timer_PRESCALER_CLK_64
	TCCR2 |= TIMER2_DIVISION_BY_64;

#elif TIMER_Prescaler == Timer_PRESCALER_CLK_128
	TCCR2 |= TIMER2_DIVISION_BY_128;

#elif TIMER_Prescaler == Timer_PRESCALER_CLK_256
	TCCR2 |= TIMER2_DIVISION_BY_256;

#elif TIMER_Prescaler == Timer_PRESCALER_CLK_1024
	TCCR2 |= TIMER2_DIVISION_BY_1024;

#endif


#if TIMER_OUT_0_2_COMP == TIMER_OUT_0_2_COMP_NORMAL
	CLR_BIT(TCCR2, TCCR2_COM20);
	CLR_BIT(TCCR2, TCCR2_COM21);

#elif TIMER_OUT_0_2_COMP == TIMER_OUT_0_2_COMP_CTC_SET_PIN
	SET_BIT(TCCR2, TCCR2_COM20);
	SET_BIT(TCCR2, TCCR2_COM21);

#elif TIMER_OUT_0_2_COMP == TIMER_OUT_0_2_COMP_CTC_CLR_PIN
	CLR_BIT(TCCR2, TCCR2_COM20);
	SET_BIT(TCCR2, TCCR2_COM21);

#elif TIMER_OUT_0_2_COMP == TIMER_OUT_0_2_COMP_CTC_TOG_PIN
	SET_BIT(TCCR2, TCCR2_COM20);
	CLR_BIT(TCCR2, TCCR2_COM21);

#elif TIMER_OUT_0_2_COMP == TIMER_OUT_0_2_COMP_FAST_PWM_INVERTED_MODE
	SET_BIT(TCCR2, TCCR2_COM20);
	SET_BIT(TCCR2, TCCR2_COM21);

#elif TIMER_OUT_0_2_COMP == TIMER_OUT_0_2_COMP_FAST_PWM_NON_INVERTED_MODE
	CLR_BIT(TCCR2, TCCR2_COM20);
	SET_BIT(TCCR2, TCCR2_COM21);

#elif TIMER_OUT_0_2_COMP == TIMER_OUT_0_2_COMP_PHASE_CORR_INVERTED_MODE
	SET_BIT(TCCR2, TCCR2_COM20);
	SET_BIT(TCCR2, TCCR2_COM21);

#elif TIMER_OUT_0_2_COMP == TIMER_OUT_0_2_COMP_PHASE_CORR_NON_INVERTED_MODE
	CLR_BIT(TCCR2, TCCR2_COM20);
	SET_BIT(TCCR2, TCCR2_COM21);

#endif
}

/*********************************************************************************************************************************/

void Timer2_voidInit(Timer2_CFG_t* Timer2)
{
	if (Timer2->WFG_MODE == TIMER_0_2_NORMAL)
	{
		CLR_BIT(TCCR2, TCCR2_WGM20);
		CLR_BIT(TCCR2, TCCR2_WGM21);
	}

	else if (Timer2->WFG_MODE == TIMER_0_2_CTC)
	{
		CLR_BIT(TCCR2, TCCR2_WGM20);
		SET_BIT(TCCR2, TCCR2_WGM21);
	}

	else if (Timer2->WFG_MODE == TIMER_0_2_FAST_PWM)
	{
		SET_BIT(TCCR2, TCCR2_WGM20);
		SET_BIT(TCCR2, TCCR2_WGM21);
	}

	else if (Timer2->WFG_MODE == TIMER_0_2_PHASE_CORR)
	{
		SET_BIT(TCCR2, TCCR2_WGM20);
		CLR_BIT(TCCR2, TCCR2_WGM21);
	}



	TCCR2 &= TIMER0_1_2_PRESCALER_MASK;

	if (Timer2->Prescaler == Timer_2_PRESCALER_CLK_1)
	{
		TCCR2 |= TIMER2_DIVISION_BY_1;
	}

	else if (Timer2->Prescaler == Timer_2_PRESCALER_CLK_8)
	{
		TCCR2 |= TIMER2_DIVISION_BY_8;
	}

	else if (Timer2->Prescaler == Timer_2_PRESCALER_CLK_32)
	{
		TCCR2 |= TIMER2_DIVISION_BY_32;
	}

	else if (Timer2->Prescaler == Timer_2_PRESCALER_CLK_64)
	{
		TCCR2 |= TIMER2_DIVISION_BY_64;
	}

	else if (Timer2->Prescaler == Timer_2_PRESCALER_CLK_128)
	{
		TCCR2 |= TIMER2_DIVISION_BY_128;
	}

	else if (Timer2->Prescaler == Timer_2_PRESCALER_CLK_256)
	{
		TCCR2 |= TIMER2_DIVISION_BY_256;
	}

	else if (Timer2->Prescaler == Timer_2_PRESCALER_CLK_1024)
	{
		TCCR2 |= TIMER2_DIVISION_BY_1024;
	}



	if (Timer2->OC_MODE == TIMER_0_2_NORMAL_OUT)
	{
		CLR_BIT(TCCR2, TCCR2_COM20);
		CLR_BIT(TCCR2, TCCR2_COM21);
	}

	else if (Timer2->OC_MODE == TIMER_0_2_CTC_SET_PIN)
	{
		SET_BIT(TCCR2, TCCR2_COM20);
		SET_BIT(TCCR2, TCCR2_COM21);
	}

	else if (Timer2->OC_MODE == TIMER_0_2_CTC_CLR_PIN)
	{
		CLR_BIT(TCCR2, TCCR2_COM20);
		SET_BIT(TCCR2, TCCR2_COM21);
	}

	else if (Timer2->OC_MODE == TIMER_0_2_CTC_TOG_PIN)
	{
		SET_BIT(TCCR2, TCCR2_COM20);
		CLR_BIT(TCCR2, TCCR2_COM21);
	}

	else if (Timer2->OC_MODE == TIMER_0_2_FAST_PWM_INVERTED_MODE)
	{
		SET_BIT(TCCR2, TCCR2_COM20);
		SET_BIT(TCCR2, TCCR2_COM21);
	}

	else if (Timer2->OC_MODE == TIMER_0_2_FAST_PWM_NON_INVERTED_MODE)
	{
		CLR_BIT(TCCR2, TCCR2_COM20);
		SET_BIT(TCCR2, TCCR2_COM21);
	}

	else if (Timer2->OC_MODE == TIMER_0_2_PHASE_CORR_INVERTED_MODE)
	{
		SET_BIT(TCCR2, TCCR2_COM20);
		SET_BIT(TCCR2, TCCR2_COM21);
	}

	else if (Timer2->OC_MODE == TIMER_0_2_PHASE_CORR_NON_INVERTED_MODE)
	{
		CLR_BIT(TCCR2, TCCR2_COM20);
		SET_BIT(TCCR2, TCCR2_COM21);
	}

}


/*********************************************************************************************************************************/



void Timer1_voidInit_CFG(void)
{

	TCCR1A &= TIMER1_TCCR1A_WGM_MASK;
	TCCR1B &= TIMER1_TCCR1B_WGM_MASK;

#if TIMER1_WFGen_Mode == TIMER1_WFGen_Mode_NORMAL
	TCCR1A |= TIMER1_TCCR1A_WGM_NORMAL;
	TCCR1B |= TIMER1_TCCR1B_WGM_NORMAL;

#elif TIMER1_WFGen_Mode == TIMER1_WFGen_Mode_PWM_PHASE_CORR_8BIT
	TCCR1A |= TIMER1_TCCR1A_WGM_PWM_PHASE_CORR_8BIT;
	TCCR1B |= TIMER1_TCCR1B_WGM_PWM_PHASE_CORR_8BIT;

#elif TIMER1_WFGen_Mode == TIMER1_WFGen_Mode_PWM_PHASE_CORR_9BIT
	TCCR1A |= TIMER1_TCCR1A_WGM_PWM_PHASE_CORR_9BIT;
	TCCR1B |= TIMER1_TCCR1B_WGM_PWM_PHASE_CORR_9BIT;

#elif TIMER1_WFGen_Mode == TIMER1_WFGen_Mode_PWM_PHASE_CORR_10BIT
	TCCR1A |= TIMER1_TCCR1A_WGM_PWM_PHASE_CORR_10BIT;
	TCCR1B |= TIMER1_TCCR1B_WGM_PWM_PHASE_CORR_10BIT;

#elif TIMER1_WFGen_Mode == TIMER1_WFGen_Mode_CTC1
	TCCR1A |= TIMER1_TCCR1A_WGM_CTC1;
	TCCR1B |= TIMER1_TCCR1B_WGM_CTC1;

#elif TIMER1_WFGen_Mode == TIMER1_WFGen_Mode_FAST_PWM_8BIT
	TCCR1A |= TIMER1_TCCR1A_WGM_FAST_PWM_8BIT;
	TCCR1B |= TIMER1_TCCR1B_WGM_FAST_PWM_8BIT;

#elif TIMER1_WFGen_Mode == TIMER1_WFGen_Mode_FAST_PWM_9BIT
	TCCR1A |= TIMER1_TCCR1A_WGM_FAST_PWM_9BIT;
	TCCR1B |= TIMER1_TCCR1B_WGM_FAST_PWM_9BIT;

#elif TIMER1_WFGen_Mode == TIMER1_WFGen_Mode_FAST_PWM_10BIT
	TCCR1A |= TIMER1_TCCR1A_WGM_FAST_PWM_10BIT;
	TCCR1B |= TIMER1_TCCR1B_WGM_FAST_PWM_10BIT;

#elif TIMER1_WFGen_Mode == TIMER1_WFGen_Mode_PWM_PHASE_FREQ_CORR1
	TCCR1A |= TIMER1_TCCR1A_WGM_PWM_PHASE_FREQ_CORR1;
	TCCR1B |= TIMER1_TCCR1B_WGM_PWM_PHASE_FREQ_CORR1;


#elif TIMER1_WFGen_Mode == TIMER1_WFGen_Mode_PWM_PHASE_FREQ_CORR2
	TCCR1A |= TIMER1_TCCR1A_WGM_PWM_PHASE_FREQ_CORR2;
	TCCR1B |= TIMER1_TCCR1B_WGM_PWM_PHASE_FREQ_CORR2;


#elif TIMER1_WFGen_Mode == TIMER1_WFGen_Mode_PWM_PHASE_CORR1
	TCCR1A |= TIMER1_TCCR1A_WGM_PWM_PHASE_CORR1;
	TCCR1B |= TIMER1_TCCR1B_WGM_PWM_PHASE_CORR1;


#elif TIMER1_WFGen_Mode == TIMER1_WFGen_Mode_PWM_PHASE_CORR2
	TCCR1A |= TIMER1_TCCR1A_WGM_PWM_PHASE_CORR2;
	TCCR1B |= TIMER1_TCCR1B_WGM_PWM_PHASE_CORR2;


#elif TIMER1_WFGen_Mode == TIMER1_WFGen_Mode_CTC2
	TCCR1A |= TIMER1_TCCR1A_WGM_CTC2;
	TCCR1B |= TIMER1_TCCR1B_WGM_CTC2;


#elif TIMER1_WFGen_Mode == TIMER1_WFGen_Mode_FAST_PWM1
	TCCR1A |= TIMER1_TCCR1A_WGM_FAST_PWM1;
	TCCR1B |= TIMER1_TCCR1B_WGM_FAST_PWM1;


#elif TIMER1_WFGen_Mode == TIMER1_WFGen_Mode_FAST_PWM2
	TCCR1A |= TIMER1_TCCR1A_WGM_FAST_PWM2;
	TCCR1B |= TIMER1_TCCR1B_WGM_FAST_PWM2;

#endif


	TCCR1B &= TIMER0_1_2_PRESCALER_MASK;
#if TIMER_Prescaler == Timer_PRESCALER_CLK_1
	TCCR1B |= TIMER0_1_DIVISION_BY_1;

#elif TIMER_Prescaler == Timer_PRESCALER_CLK_8
	TCCR1B |= TIMER0_1_DIVISION_BY_8;

#elif TIMER_Prescaler == Timer_PRESCALER_CLK_64
	TCCR1B |= TIMER0_1_DIVISION_BY_64;

#elif TIMER_Prescaler == Timer_PRESCALER_CLK_256
	TCCR1B |= TIMER0_1_DIVISION_BY_256;

#elif TIMER_Prescaler == Timer_PRESCALER_CLK_1024
	TCCR1B |= TIMER0_1_DIVISION_BY_1024;
#endif


#if TIMER_OUT_1_COMP_A	== TIMER_OUT_1_COMP_NORMAL
	CLR_BIT(TCCR1A, TCCR1A_COM1A0);
	CLR_BIT(TCCR1A, TCCR1A_COM1A1);

#elif TIMER_OUT_1_COMP_A == TIMER_OUT_1_COMP_CTC_SET_PIN_A
	SET_BIT(TCCR1A, TCCR1A_COM1A0);
	SET_BIT(TCCR1A, TCCR1A_COM1A1);

#elif TIMER_OUT_1_COMP_A == TIMER_OUT_1_COMP_CTC_CLR_PIN_A
	CLR_BIT(TCCR1A, TCCR1A_COM1A0);
	SET_BIT(TCCR1A, TCCR1A_COM1A1);

#elif TIMER_OUT_1_COMP_A == TIMER_OUT_1_COMP_CTC_TOG_PIN_A
	SET_BIT(TCCR1A, TCCR1A_COM1A0);
	CLR_BIT(TCCR1A, TCCR1A_COM1A1);

#elif TIMER_OUT_1_COMP_A == TIMER_OUT_1_COMP_FAST_PWM_INVERTED_MODE_A
	SET_BIT(TCCR1A, TCCR1A_COM1A0);
	SET_BIT(TCCR1A, TCCR1A_COM1A1);

#elif TIMER_OUT_1_COMP_A == TIMER_OUT_1_COMP_FAST_PWM_NON_INVERTED_MODE_A
	CLR_BIT(TCCR1A, TCCR1A_COM1A0);
	SET_BIT(TCCR1A, TCCR1A_COM1A1);

#elif TIMER_OUT_1_COMP_A == TIMER_OUT_1_COMP_PHASE_CORR_INVERTED_MODE_A
	SET_BIT(TCCR1A, TCCR1A_COM1A0);
	SET_BIT(TCCR1A, TCCR1A_COM1A1);

#elif TIMER_OUT_1_COMP_A == TIMER_OUT_1_COMP_PHASE_CORR_NON_INVERTED_MODE_A
	CLR_BIT(TCCR1A, TCCR1A_COM1A0);
	SET_BIT(TCCR1A, TCCR1A_COM1A1);

#endif

#if TIMER_OUT_1_COMP_B	== TIMER_OUT_1_COMP_NORMAL
	CLR_BIT(TCCR1A, TCCR1A_COM1B0);
	CLR_BIT(TCCR1A, TCCR1A_COM1B1);

#elif TIMER_OUT_1_COMP_B == TIMER_OUT_1_COMP_CTC_SET_PIN_B
	SET_BIT(TCCR1A, TCCR1A_COM1B0);
	SET_BIT(TCCR1A, TCCR1A_COM1B1);

#elif TIMER_OUT_1_COMP_B == TIMER_OUT_1_COMP_CTC_CLR_PIN_B
	CLR_BIT(TCCR1A, TCCR1A_COM1B0);
	SET_BIT(TCCR1A, TCCR1A_COM1B1);

#elif TIMER_OUT_1_COMP_B == TIMER_OUT_1_COMP_CTC_TOG_PIN_B
	SET_BIT(TCCR1A, TCCR1A_COM1B0);
	CLR_BIT(TCCR1A, TCCR1A_COM1B1);

#elif TIMER_OUT_1_COMP_B == TIMER_OUT_1_COMP_FAST_PWM_INVERTED_MODE_B
	SET_BIT(TCCR1A, TCCR1A_COM1B0);
	SET_BIT(TCCR1A, TCCR1A_COM1B1);

#elif TIMER_OUT_1_COMP_B == TIMER_OUT_1_COMP_FAST_PWM_NON_INVERTED_MODE_B
	CLR_BIT(TCCR1A, TCCR1A_COM1B0);
	SET_BIT(TCCR1A, TCCR1A_COM1B1);

#elif TIMER_OUT_1_COMP_B == TIMER_OUT_1_COMP_PHASE_CORR_INVERTED_MODE_B
	SET_BIT(TCCR1A, TCCR1A_COM1B0);
	SET_BIT(TCCR1A, TCCR1A_COM1B1);

#elif TIMER_OUT_1_COMP_B == TIMER_OUT_1_COMP_PHASE_CORR_NON_INVERTED_MODE_B
	CLR_BIT(TCCR1A, TCCR1A_COM1B0);
	SET_BIT(TCCR1A, TCCR1A_COM1B1);
#endif

}

void Timer1_voidInit(Timer1_CFG_t* Timer1)
{
	TCCR1A &= TIMER1_TCCR1A_WGM_MASK;
	TCCR1B &= TIMER1_TCCR1B_WGM_MASK;

	if (Timer1->WFG_MODE == TIMER_1_NORMAL)
	{
		TCCR1A |= TIMER1_TCCR1A_WGM_NORMAL;
		TCCR1B |= TIMER1_TCCR1B_WGM_NORMAL;
	}

	else if (Timer1->WFG_MODE == TIMER_1_PWM_PHASE_CORR_8BIT)
	{
		TCCR1A |= TIMER1_TCCR1A_WGM_PWM_PHASE_CORR_8BIT;
		TCCR1B |= TIMER1_TCCR1B_WGM_PWM_PHASE_CORR_8BIT;
	}

	else if (Timer1->WFG_MODE == TIMER_1_PWM_PHASE_CORR_9BIT)
	{
		TCCR1A |= TIMER1_TCCR1A_WGM_PWM_PHASE_CORR_9BIT;
		TCCR1B |= TIMER1_TCCR1B_WGM_PWM_PHASE_CORR_9BIT;
	}

	else if (Timer1->WFG_MODE == TIMER_1_PWM_PHASE_CORR_10BIT)
	{
		TCCR1A |= TIMER1_TCCR1A_WGM_PWM_PHASE_CORR_10BIT;
		TCCR1B |= TIMER1_TCCR1B_WGM_PWM_PHASE_CORR_10BIT;
	}

	else if (Timer1->WFG_MODE == TIMER_1_CTC1)
	{
		TCCR1A |= TIMER1_TCCR1A_WGM_CTC1;
		TCCR1B |= TIMER1_TCCR1B_WGM_CTC1;
	}

	else if (Timer1->WFG_MODE == TIMER_1_FAST_PWM_8BIT)
	{
		TCCR1A |= TIMER1_TCCR1A_WGM_FAST_PWM_8BIT;
		TCCR1B |= TIMER1_TCCR1B_WGM_FAST_PWM_8BIT;
	}

	else if (Timer1->WFG_MODE == TIMER_1_FAST_PWM_9BIT)
	{
		TCCR1A |= TIMER1_TCCR1A_WGM_FAST_PWM_9BIT;
		TCCR1B |= TIMER1_TCCR1B_WGM_FAST_PWM_9BIT;
	}

	else if (Timer1->WFG_MODE == TIMER_1_FAST_PWM_10BIT)
	{
		TCCR1A |= TIMER1_TCCR1A_WGM_FAST_PWM_10BIT;
		TCCR1B |= TIMER1_TCCR1B_WGM_FAST_PWM_10BIT;
	}

	else if (Timer1->WFG_MODE == TIMER_1_PWM_PHASE_FREQ_CORR1)
	{
		TCCR1A |= TIMER1_TCCR1A_WGM_PWM_PHASE_FREQ_CORR1;
		TCCR1B |= TIMER1_TCCR1B_WGM_PWM_PHASE_FREQ_CORR1;
	}


	else if (Timer1->WFG_MODE == TIMER_1_PWM_PHASE_FREQ_CORR2)
	{
		TCCR1A |= TIMER1_TCCR1A_WGM_PWM_PHASE_FREQ_CORR2;
		TCCR1B |= TIMER1_TCCR1B_WGM_PWM_PHASE_FREQ_CORR2;
	}


	else if (Timer1->WFG_MODE == TIMER_1_PWM_PHASE_CORR1)
	{
		TCCR1A |= TIMER1_TCCR1A_WGM_PWM_PHASE_CORR1;
		TCCR1B |= TIMER1_TCCR1B_WGM_PWM_PHASE_CORR1;
	}


	else if (Timer1->WFG_MODE == TIMER_1_PWM_PHASE_CORR2)
	{
		TCCR1A |= TIMER1_TCCR1A_WGM_PWM_PHASE_CORR2;
		TCCR1B |= TIMER1_TCCR1B_WGM_PWM_PHASE_CORR2;
	}


	else if (Timer1->WFG_MODE == TIMER_1_CTC2)
	{
		TCCR1A |= TIMER1_TCCR1A_WGM_CTC2;
		TCCR1B |= TIMER1_TCCR1B_WGM_CTC2;
	}


	else if (Timer1->WFG_MODE == TIMER_1_FAST_PWM1)
	{
		TCCR1A |= TIMER1_TCCR1A_WGM_FAST_PWM1;
		TCCR1B |= TIMER1_TCCR1B_WGM_FAST_PWM1;
	}


	else if (Timer1->WFG_MODE == TIMER_1_FAST_PWM2)
	{
		TCCR1A |= TIMER1_TCCR1A_WGM_FAST_PWM2;
		TCCR1B |= TIMER1_TCCR1B_WGM_FAST_PWM2;
	}


	TCCR1B &= TIMER0_1_2_PRESCALER_MASK;
	if (Timer1->Prescaler == Timer_0_1_PRESCALER_CLK_1)
	{
		TCCR1B |= TIMER0_1_DIVISION_BY_1;
	}

	else if (Timer1->Prescaler == Timer_0_1_PRESCALER_CLK_8)
	{
		TCCR1B |= TIMER0_1_DIVISION_BY_8;
	}

	else if (Timer1->Prescaler == Timer_0_1_PRESCALER_CLK_64)
	{
		TCCR1B |= TIMER0_1_DIVISION_BY_64;
	}

	else if (Timer1->Prescaler == Timer_0_1_PRESCALER_CLK_256)
	{
		TCCR1B |= TIMER0_1_DIVISION_BY_256;
	}

	else if (Timer1->Prescaler == Timer_0_1_PRESCALER_CLK_1024)
	{
		TCCR1B |= TIMER0_1_DIVISION_BY_1024;
	}


	if (Timer1->OC_A_MODE == TIMER_1_NORMAL_A)
	{
		CLR_BIT(TCCR1A, TCCR1A_COM1A0);
		CLR_BIT(TCCR1A, TCCR1A_COM1A1);
	}

	else if (Timer1->OC_A_MODE == TIMER_1_CTC_SET_PIN_A)
	{
		SET_BIT(TCCR1A, TCCR1A_COM1A0);
		SET_BIT(TCCR1A, TCCR1A_COM1A1);
	}

	else if (Timer1->OC_A_MODE == TIMER_1_CTC_CLR_PIN_A)
	{
		CLR_BIT(TCCR1A, TCCR1A_COM1A0);
		SET_BIT(TCCR1A, TCCR1A_COM1A1);
	}

	else if (Timer1->OC_A_MODE == TIMER_1_CTC_TOG_PIN_A)
	{
		SET_BIT(TCCR1A, TCCR1A_COM1A0);
		CLR_BIT(TCCR1A, TCCR1A_COM1A1);
	}

	else if (Timer1->OC_A_MODE == TIMER_1_FAST_PWM_INVERTED_MODE_A)
	{
		SET_BIT(TCCR1A, TCCR1A_COM1A0);
		SET_BIT(TCCR1A, TCCR1A_COM1A1);
	}

	else if (Timer1->OC_A_MODE == TIMER_1_FAST_PWM_NON_INVERTED_MODE_A)
	{
		CLR_BIT(TCCR1A, TCCR1A_COM1A0);
		SET_BIT(TCCR1A, TCCR1A_COM1A1);
	}

	else if (Timer1->OC_A_MODE == TIMER_1_PHASE_CORR_INVERTED_MODE_A)
	{
		SET_BIT(TCCR1A, TCCR1A_COM1A0);
		SET_BIT(TCCR1A, TCCR1A_COM1A1);
	}

	else if (Timer1->OC_A_MODE == TIMER_1_PHASE_CORR_NON_INVERTED_MODE_A)
	{
		CLR_BIT(TCCR1A, TCCR1A_COM1A0);
		SET_BIT(TCCR1A, TCCR1A_COM1A1);
	}


	if (Timer1->OC_B_MODE == TIMER_1_NORMAL_OUT_B)
	{
		CLR_BIT(TCCR1A, TCCR1A_COM1B0);
		CLR_BIT(TCCR1A, TCCR1A_COM1B1);
	}

	else if (Timer1->OC_B_MODE == TIMER_1_CTC_SET_PIN_B)
	{
		SET_BIT(TCCR1A, TCCR1A_COM1B0);
		SET_BIT(TCCR1A, TCCR1A_COM1B1);
	}

	else if (Timer1->OC_B_MODE == TIMER_1_CTC_CLR_PIN_B)
	{
		CLR_BIT(TCCR1A, TCCR1A_COM1B0);
		SET_BIT(TCCR1A, TCCR1A_COM1B1);
	}

	else if (Timer1->OC_B_MODE == TIMER_1_CTC_TOG_PIN_B)
	{
		SET_BIT(TCCR1A, TCCR1A_COM1B0);
		CLR_BIT(TCCR1A, TCCR1A_COM1B1);
	}

	else if (Timer1->OC_B_MODE == TIMER_1_FAST_PWM_INVERTED_MODE_B)
	{
		SET_BIT(TCCR1A, TCCR1A_COM1B0);
		SET_BIT(TCCR1A, TCCR1A_COM1B1);
	}

	else if (Timer1->OC_B_MODE == TIMER_1_FAST_PWM_NON_INVERTED_MODE_B)
	{
		CLR_BIT(TCCR1A, TCCR1A_COM1B0);
		SET_BIT(TCCR1A, TCCR1A_COM1B1);
	}

	else if (Timer1->OC_B_MODE == TIMER_1_PHASE_CORR_INVERTED_MODE_B)
	{
		SET_BIT(TCCR1A, TCCR1A_COM1B0);
		SET_BIT(TCCR1A, TCCR1A_COM1B1);
	}

	else if (Timer1->OC_B_MODE == TIMER_1_PHASE_CORR_NON_INVERTED_MODE_B)
	{
		CLR_BIT(TCCR1A, TCCR1A_COM1B0);
		SET_BIT(TCCR1A, TCCR1A_COM1B1);
	}

}


/***************************************************************************************************************************************/
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


void __vector_4(void) __attribute((signal));
void __vector_4(void)
{
	if(TIMERS_pvCallBackFuncArr[TIMER2_COMP] != NULL)
	{
		TIMERS_pvCallBackFuncArr[TIMER2_COMP]();
	}
}

void __vector_5(void) __attribute((signal));
void __vector_5(void)
{
	if(TIMERS_pvCallBackFuncArr[TIMER2_OVF] != NULL)
	{
		TIMERS_pvCallBackFuncArr[TIMER2_OVF]();
	}
}

void __vector_6(void) __attribute((signal));
void __vector_6(void)
{
	if(TIMERS_pvCallBackFuncArr[TIMER1_CAPT] != NULL)
	{
		TIMERS_pvCallBackFuncArr[TIMER1_CAPT]();
	}
}

void __vector_7(void) __attribute((signal));
void __vector_7(void)
{
	if(TIMERS_pvCallBackFuncArr[TIMER1_COMPA] != NULL)
	{
		TIMERS_pvCallBackFuncArr[TIMER1_COMPA]();
	}
}

void __vector_8(void) __attribute((signal));
void __vector_8(void)
{
	if(TIMERS_pvCallBackFuncArr[TIMER1_COMPB] != NULL)
	{
		TIMERS_pvCallBackFuncArr[TIMER1_COMPB]();
	}
}

void __vector_9(void) __attribute((signal));
void __vector_9(void)
{
	if(TIMERS_pvCallBackFuncArr[TIMER1_OVF] != NULL)
	{
		TIMERS_pvCallBackFuncArr[TIMER1_OVF]();
	}
}

void __vector_10(void) __attribute((signal));
void __vector_10(void)
{
	if(TIMERS_pvCallBackFuncArr[TIMER0_COMP] != NULL)
	{
		TIMERS_pvCallBackFuncArr[TIMER0_COMP]();
	}
}

void __vector_11(void) __attribute((signal));
void __vector_11(void)
{
	if(TIMERS_pvCallBackFuncArr[TIMER0_OVF] != NULL)
	{
		TIMERS_pvCallBackFuncArr[TIMER0_OVF]();
	}
}
/***************************************************************************************************************************************/

void Timer0_SetCompareOutMode(TIMER_0_2_OUT_COMP_t Copy_CompMode)
{
	if (Copy_CompMode == TIMER_0_2_NORMAL_OUT)
	{
		CLR_BIT(TCCR0, TCCR0_COM00);
		CLR_BIT(TCCR0, TCCR0_COM01);
	}

	else if (Copy_CompMode == TIMER_0_2_CTC_SET_PIN)
	{
		SET_BIT(TCCR0, TCCR0_COM00);
		SET_BIT(TCCR0, TCCR0_COM01);
	}

	else if (Copy_CompMode == TIMER_0_2_CTC_CLR_PIN)
	{
		CLR_BIT(TCCR0, TCCR0_COM00);
		SET_BIT(TCCR0, TCCR0_COM01);
	}

	else if (Copy_CompMode == TIMER_0_2_CTC_TOG_PIN)
	{
		SET_BIT(TCCR0, TCCR0_COM00);
		CLR_BIT(TCCR0, TCCR0_COM01);
	}

	else if (Copy_CompMode == TIMER_0_2_FAST_PWM_INVERTED_MODE)
	{
		SET_BIT(TCCR0, TCCR0_COM00);
		SET_BIT(TCCR0, TCCR0_COM01);
	}

	else if (Copy_CompMode == TIMER_0_2_FAST_PWM_NON_INVERTED_MODE)
	{
		CLR_BIT(TCCR0, TCCR0_COM00);
		SET_BIT(TCCR0, TCCR0_COM01);
	}

	else if (Copy_CompMode == TIMER_0_2_PHASE_CORR_INVERTED_MODE)
	{
		SET_BIT(TCCR0, TCCR0_COM00);
		SET_BIT(TCCR0, TCCR0_COM01);
	}

	else if (Copy_CompMode == TIMER_0_2_PHASE_CORR_NON_INVERTED_MODE)
	{
		CLR_BIT(TCCR0, TCCR0_COM00);
		SET_BIT(TCCR0, TCCR0_COM01);
	}
}
/***************************************************************************************************************************************/

void Timer2_SetCompareOutMode(TIMER_0_2_OUT_COMP_t Copy_CompMode)
{
	if (Copy_CompMode == TIMER_0_2_NORMAL_OUT)
	{
		CLR_BIT(TCCR2, TCCR2_COM20);
		CLR_BIT(TCCR2, TCCR2_COM21);
	}

	else if (Copy_CompMode == TIMER_0_2_CTC_SET_PIN)
	{
		SET_BIT(TCCR2, TCCR2_COM20);
		SET_BIT(TCCR2, TCCR2_COM21);
	}

	else if (Copy_CompMode == TIMER_0_2_CTC_CLR_PIN)
	{
		CLR_BIT(TCCR2, TCCR2_COM20);
		SET_BIT(TCCR2, TCCR2_COM21);
	}

	else if (Copy_CompMode == TIMER_0_2_CTC_TOG_PIN)
	{
		SET_BIT(TCCR2, TCCR2_COM20);
		CLR_BIT(TCCR2, TCCR2_COM21);
	}

	else if (Copy_CompMode == TIMER_0_2_FAST_PWM_INVERTED_MODE)
	{
		SET_BIT(TCCR2, TCCR2_COM20);
		SET_BIT(TCCR2, TCCR2_COM21);
	}

	else if (Copy_CompMode == TIMER_0_2_FAST_PWM_NON_INVERTED_MODE)
	{
		CLR_BIT(TCCR2, TCCR2_COM20);
		SET_BIT(TCCR2, TCCR2_COM21);
	}

	else if (Copy_CompMode == TIMER_0_2_PHASE_CORR_INVERTED_MODE)
	{
		SET_BIT(TCCR2, TCCR2_COM20);
		SET_BIT(TCCR2, TCCR2_COM21);
	}

	else if (Copy_CompMode == TIMER_0_2_PHASE_CORR_NON_INVERTED_MODE)
	{
		CLR_BIT(TCCR2, TCCR2_COM20);
		SET_BIT(TCCR2, TCCR2_COM21);
	}

}
/***************************************************************************************************************************************/

void Timer1_SetCompareOutModeChannel_A (TIMER_1_OUT_COMP_A_t Copy_CompMode)
{
	if (Copy_CompMode	== TIMER_1_NORMAL_A)
	{
		CLR_BIT(TCCR1A, TCCR1A_COM1A0);
		CLR_BIT(TCCR1A, TCCR1A_COM1A1);
	}

	else if (Copy_CompMode == TIMER_1_CTC_SET_PIN_A)
	{
		SET_BIT(TCCR1A, TCCR1A_COM1A0);
		SET_BIT(TCCR1A, TCCR1A_COM1A1);
	}

	else if (Copy_CompMode == TIMER_1_CTC_CLR_PIN_A)
	{
		CLR_BIT(TCCR1A, TCCR1A_COM1A0);
		SET_BIT(TCCR1A, TCCR1A_COM1A1);
	}

	else if (Copy_CompMode == TIMER_1_CTC_TOG_PIN_A)
	{
		SET_BIT(TCCR1A, TCCR1A_COM1A0);
		CLR_BIT(TCCR1A, TCCR1A_COM1A1);
	}

	else if (Copy_CompMode == TIMER_1_FAST_PWM_INVERTED_MODE_A)
	{
		SET_BIT(TCCR1A, TCCR1A_COM1A0);
		SET_BIT(TCCR1A, TCCR1A_COM1A1);
	}

	else if (Copy_CompMode == TIMER_1_FAST_PWM_NON_INVERTED_MODE_A)
	{
		CLR_BIT(TCCR1A, TCCR1A_COM1A0);
		SET_BIT(TCCR1A, TCCR1A_COM1A1);
	}

	else if (Copy_CompMode == TIMER_1_PHASE_CORR_INVERTED_MODE_A)
	{
		SET_BIT(TCCR1A, TCCR1A_COM1A0);
		SET_BIT(TCCR1A, TCCR1A_COM1A1);
	}

	else if (Copy_CompMode == TIMER_1_PHASE_CORR_NON_INVERTED_MODE_A)
	{
		CLR_BIT(TCCR1A, TCCR1A_COM1A0);
		SET_BIT(TCCR1A, TCCR1A_COM1A1);
	}

}
/***************************************************************************************************************************************/

void Timer1_SetCompareOutModeChannel_B(TIMER_1_OUT_COMP_B_t Copy_CompMode)
{
	if (Copy_CompMode	== TIMER_1_NORMAL_OUT_B)
	{
		CLR_BIT(TCCR1A, TCCR1A_COM1B0);
		CLR_BIT(TCCR1A, TCCR1A_COM1B1);
	}

	else if (Copy_CompMode == TIMER_1_CTC_SET_PIN_B)
	{
		SET_BIT(TCCR1A, TCCR1A_COM1B0);
		SET_BIT(TCCR1A, TCCR1A_COM1B1);
	}

	else if (Copy_CompMode == TIMER_1_CTC_CLR_PIN_B)
	{
		CLR_BIT(TCCR1A, TCCR1A_COM1B0);
		SET_BIT(TCCR1A, TCCR1A_COM1B1);
	}

	else if (Copy_CompMode == TIMER_1_CTC_TOG_PIN_B)
	{
		SET_BIT(TCCR1A, TCCR1A_COM1B0);
		CLR_BIT(TCCR1A, TCCR1A_COM1B1);
	}

	else if (Copy_CompMode == TIMER_1_FAST_PWM_INVERTED_MODE_B)
	{
		SET_BIT(TCCR1A, TCCR1A_COM1B0);
		SET_BIT(TCCR1A, TCCR1A_COM1B1);
	}

	else if (Copy_CompMode == TIMER_1_FAST_PWM_NON_INVERTED_MODE_B)
	{
		CLR_BIT(TCCR1A, TCCR1A_COM1B0);
		SET_BIT(TCCR1A, TCCR1A_COM1B1);
	}

	else if (Copy_CompMode == TIMER_1_PHASE_CORR_INVERTED_MODE_B)
	{
		SET_BIT(TCCR1A, TCCR1A_COM1B0);
		SET_BIT(TCCR1A, TCCR1A_COM1B1);
	}

	else if (Copy_CompMode == TIMER_1_PHASE_CORR_NON_INVERTED_MODE_B)
	{
		CLR_BIT(TCCR1A, TCCR1A_COM1B0);
		SET_BIT(TCCR1A, TCCR1A_COM1B1);
	}

}
/***************************************************************************************************************************************/

void Timers_voidInterruptEnable(Timers_Int_Src_t Copy_IntSRC)
{
	if (Copy_IntSRC == TIMER0_OVF)
	{
		SET_BIT(TIMSK, TIMSK_TOIE0);
	}
	else if (Copy_IntSRC == TIMER0_COMP)
	{
		SET_BIT(TIMSK, TIMSK_OCIE0);
	}
	else if (Copy_IntSRC == TIMER2_OVF)
	{
		SET_BIT(TIMSK, TIMSK_TOIE2);
	}
	else if (Copy_IntSRC == TIMER2_COMP)
	{
		SET_BIT(TIMSK, TIMSK_OCIE2);
	}
	else if (Copy_IntSRC == TIMER1_CAPT)
	{
		SET_BIT(TIMSK, TIMSK_TICIE1);
	}
	else if(Copy_IntSRC == TIMER1_COMPA)
	{
		SET_BIT(TIMSK, TIMSK_OCIE1A);
	}
	else if (Copy_IntSRC == TIMER1_COMPB)
	{
		SET_BIT(TIMSK, TIMSK_OCIE1B);
	}
	else if (Copy_IntSRC == TIMER1_OVF)
	{
		SET_BIT(TIMSK, TIMSK_TOIE1);
	}
}
/***************************************************************************************************************************************/

void Timers_voidInterruptDisable(Timers_Int_Src_t Copy_IntSRC)
{
	if (Copy_IntSRC == TIMER0_OVF)
	{
		CLR_BIT(TIMSK, TIMSK_TOIE0);
	}
	else if (Copy_IntSRC == TIMER0_COMP)
	{
		CLR_BIT(TIMSK, TIMSK_OCIE0);
	}
	else if (Copy_IntSRC == TIMER2_OVF)
	{
		CLR_BIT(TIMSK, TIMSK_TOIE2);
	}
	else if (Copy_IntSRC == TIMER2_COMP)
	{
		CLR_BIT(TIMSK, TIMSK_OCIE2);
	}
	else if (Copy_IntSRC == TIMER1_CAPT)
	{
		CLR_BIT(TIMSK, TIMSK_TICIE1);
	}
	else if(Copy_IntSRC == TIMER1_COMPA)
	{
		CLR_BIT(TIMSK, TIMSK_OCIE1A);
	}
	else if (Copy_IntSRC == TIMER1_COMPB)
	{
		CLR_BIT(TIMSK, TIMSK_OCIE1B);
	}
	else if (Copy_IntSRC == TIMER1_OVF)
	{
		CLR_BIT(TIMSK, TIMSK_TOIE1);
	}
}
/***************************************************************************************************************************************/

void Timer0_voidSetCompValue(uint8 Copy_u8Val)
{
	OCR0 = Copy_u8Val;
}

void Timer2_voidSetCompValue(uint8 Copy_u8Val)
{
	OCR2 = Copy_u8Val;
}

void Timer1_voidSetCompValue(uint16 Copy_u16Val)
{
	OCR1A = Copy_u16Val;
}
/***************************************************************************************************************************************/


void Timer1_voidICU_SetTriggerSRC(uint8 Copy_u8TriggerSRC)
{
	if(Copy_u8TriggerSRC == Timer1_ICU_TriggerSRC_Rising)
	{
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else if(Copy_u8TriggerSRC == Timer1_ICU_TriggerSRC_Falling)
	{
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
	}
}
/***************************************************************************************************************************************/

void WDT_voidEnable(void)
{
	SET_BIT(WDTCR,WDTCR_WDE);
}

void WDT_voidDisable(void)
{
	WDTCR |= 1<<WDTCR_WDTOE | 1<<WDTCR_WDE;
	WDTCR = 0x00;
}

void WDT_voidTimeSelect(WDT_Time_Select_t Copy_Time)
{
	WDTCR &= WDT_Time_MASK;
	if (Copy_Time == WDT_Time_16300us)
	{
		WDTCR |= WDT_Time_16300us;
	}
	else if (Copy_Time == WDT_Time_32500us)
	{
		WDTCR |= WDT_Time_32500us;
	}
	else if (Copy_Time == WDT_Time_65000us)
	{
		WDTCR |= WDT_Time_65000us;
	}
	else if (Copy_Time == WDT_Time_130ms)
	{
		WDTCR |= WDT_Time_130ms;
	}
	else if (Copy_Time == WDT_Time_260ms)
	{
		WDTCR |= WDT_Time_260ms;
	}
	else if (Copy_Time == WDT_Time_520ms)
	{
		WDTCR |= WDT_Time_520ms;
	}
	else if (Copy_Time == WDT_Time_1s)
	{
		WDTCR |= WDT_Time_1s;
	}
	else if (Copy_Time == WDT_Time_2100ms)
	{
		WDTCR |= WDT_Time_2100ms;
	}
}

/***************************************************************************************************************************************/

uint16 Timer1_u16GetTCNT1Value(void)
{
	return TCNT1;
}

void Timer1_u16SetTCNT1Value(uint16 Copy_u16Value)
{
	TCNT1 = Copy_u16Value;
}


uint16 Timer1_u16GetInCapVal(void)
{
	return ICR1;
}

void Timer0_u16SetTCNT0Value(uint16 Copy_u16Value)
{
	TCNT0 = Copy_u16Value;
}


uint16 Timer1_u16GetICR1Value_PWM(void)
{
	return ICR1;
}

void Timer1_u16SetICR1Value_PWM(uint16 Copy_u16Value)
{
	ICR1 = Copy_u16Value;
}
