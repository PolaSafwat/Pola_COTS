#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"
#include "Timers_interface.h"
#include "TimerService_interface.h"
#include "GIE_interface.h"

static uint32 READ1=0;
static uint32 READ2=0;
static uint32 READ3=0;



static uint8 OVF_Counter =0;

static uint8 flag =0;

void ICU_Func (void);

void Timer1_OVF_Func (void);

void TimerService_voidPWM_Measure(uint8* Copy_pu8DutyCycle, uint32* Copy_pu32PeriodTime_us)
{
	uint32 Copy_u32OnTime_us=0;

	Timer1_CFG_t Timer1_Normal;
	Timer1_Normal.Prescaler = Timer_0_1_PRESCALER_CLK_64;
	Timer1_Normal.WFG_MODE = TIMER_1_NORMAL;
	Timer1_Normal.OC_A_MODE = TIMER_1_NORMAL_A;
	Timer1_Normal.OC_B_MODE = TIMER_1_NORMAL_OUT_B;

	Timer1_voidICU_SetTriggerSRC(Timer1_ICU_TriggerSRC_Rising);



	Timers_u8SetCallBack(TIMER1_CAPT, &ICU_Func);
	Timers_u8SetCallBack(TIMER1_OVF, &Timer1_OVF_Func);


	Timers_voidInterruptEnable(TIMER1_CAPT);
	Timers_voidInterruptEnable(TIMER1_OVF);

	Timer1_voidInit(&Timer1_Normal);
	GIE_voidEnableGlobal();
	while(flag < 5);
	GIE_voidDisableGlobal();
	Timers_voidInterruptDisable(TIMER1_CAPT);
	Timers_voidInterruptDisable(TIMER1_OVF);
	*Copy_pu32PeriodTime_us = (READ2 - READ1)*4u;
	Copy_u32OnTime_us = (READ3 - READ2)*4u;
	*Copy_pu8DutyCycle = ( (Copy_u32OnTime_us) * 100) / (*Copy_pu32PeriodTime_us);

}

void ICU_Func (void)
{
	static uint8 ICU_Counter=0;

	if (ICU_Counter == 0)
	{
		/*First rising edge*/
		READ1 = ( (Timer1_u16GetInCapVal() ) + ( OVF_Counter * (65536ul) ) );
		ICU_Counter ++;
	}

	else if (ICU_Counter == 1)
	{
		/*Second rising edge*/
		READ2 = ( ( Timer1_u16GetInCapVal() ) + ( OVF_Counter * (65536ul) ) );
		Timer1_voidICU_SetTriggerSRC(Timer1_ICU_TriggerSRC_Falling);
		ICU_Counter ++;
	}

	else if (ICU_Counter == 2)
	{
		/*First Falling edge*/
		READ3 = ( ( Timer1_u16GetInCapVal() ) + ( OVF_Counter * (65536ul) ) ) ;
		flag ++;
		Timer1_voidICU_SetTriggerSRC(Timer1_ICU_TriggerSRC_Rising);
		OVF_Counter = 0;
		ICU_Counter =0;
	}
}


void Timer1_OVF_Func (void)
{
	OVF_Counter ++;
}


/***********************************************************************************************************/

static void (*Copy_pu8FuncScheduleGlobal)(void);
static uint32 Global_u32OvfCounts = 0;
void Timer1_ICR1_OVF_FuncShedule (void);
void Timer1_ICR1_OVF_FuncSheduleOnce (void);
static uint8 Once_Flag =0;

uint8 TimerServise_voidSchedule_MS(uint32 Copy_Time_MS, ScheduleFuncState_t Periodic_Once , void (*Copy_pu8Func)(void))
{
	uint8 Local_u8StateError = OK;
	if (Copy_pu8Func != NULL)
	{
		if (Periodic_Once == Periodic)
		{

			Timer1_CFG_t Timer1_PMW_ICR1;
			Timer1_PMW_ICR1.Prescaler = Timer_0_1_PRESCALER_CLK_64;
			Timer1_PMW_ICR1.WFG_MODE = TIMER_1_FAST_PWM1;
			Timer1_PMW_ICR1.OC_A_MODE = TIMER_1_FAST_PWM_NON_INVERTED_MODE_A;
			Timer1_PMW_ICR1.OC_B_MODE = TIMER_1_FAST_PWM_NON_INVERTED_MODE_B;

			uint8 Local_u8ticktime_us = 4u;
			uint16 Local_u16ICR1Counter;
			uint16 Local_u16ICR1Value;
			uint32 Local_u16TotalRequiredTicks = (uint32) ( (Copy_Time_MS * 1000ul) / ( (uint32) (Local_u8ticktime_us) ) );
			for(Local_u16ICR1Counter= 65535u ; Local_u16ICR1Counter >= 0 ; Local_u16ICR1Counter--)
			{
				if ( (Local_u16TotalRequiredTicks % Local_u16ICR1Counter) == 0)
				{
					Local_u16ICR1Value = Local_u16ICR1Counter;
					break;
				}
			}
			Global_u32OvfCounts = Local_u16TotalRequiredTicks / Local_u16ICR1Value;
			Timer1_u16SetICR1Value_PWM(Local_u16ICR1Value);
			Timer1_voidInit(&Timer1_PMW_ICR1);

			Copy_pu8FuncScheduleGlobal = Copy_pu8Func;
			Timers_u8SetCallBack(TIMER1_OVF, &Timer1_ICR1_OVF_FuncShedule);
			Timers_voidInterruptEnable(TIMER1_OVF);
		}
		else
		{
			Once_Flag =0;
			Timer1_CFG_t Timer1_PMW_ICR1;
			Timer1_PMW_ICR1.Prescaler = Timer_0_1_PRESCALER_CLK_64;
			Timer1_PMW_ICR1.WFG_MODE = TIMER_1_FAST_PWM1;
			Timer1_PMW_ICR1.OC_A_MODE = TIMER_1_FAST_PWM_NON_INVERTED_MODE_A;
			Timer1_PMW_ICR1.OC_B_MODE = TIMER_1_FAST_PWM_NON_INVERTED_MODE_B;

			uint8 Local_u8ticktime_us = 4u;
			uint16 Local_u16ICR1Counter;
			uint16 Local_u16ICR1Value;
			uint32 Local_u16TotalRequiredTicks = (uint32) ( (Copy_Time_MS * 1000ul) / ( (uint32) (Local_u8ticktime_us) ) );
			for(Local_u16ICR1Counter= 65535u ; Local_u16ICR1Counter >= 0 ; Local_u16ICR1Counter--)
			{
				if ( (Local_u16TotalRequiredTicks % Local_u16ICR1Counter) == 0)
				{
					Local_u16ICR1Value = Local_u16ICR1Counter;
					break;
				}
			}
			Global_u32OvfCounts = Local_u16TotalRequiredTicks / Local_u16ICR1Value;
			Timer1_u16SetICR1Value_PWM(Local_u16ICR1Value);
			Timer1_voidInit(&Timer1_PMW_ICR1);

			Copy_pu8FuncScheduleGlobal = Copy_pu8Func;
			Timers_u8SetCallBack(TIMER1_OVF, &Timer1_ICR1_OVF_FuncSheduleOnce);
			Timers_voidInterruptEnable(TIMER1_OVF);
			if (Once_Flag == 1)
			{
				Timers_voidInterruptDisable(TIMER1_OVF);
			}
		}
	}
	else
	{
		Local_u8StateError = NULL_PTR_ERR;
	}
	return Local_u8StateError;
}

void Timer1_ICR1_OVF_FuncShedule (void)
{
	static uint32 Counter = 0;
	Counter ++;
	if( Counter == Global_u32OvfCounts )
	{
		Copy_pu8FuncScheduleGlobal();
		Counter = 0;
	}
}

void Timer1_ICR1_OVF_FuncSheduleOnce (void)
{
	static uint32 Counter = 0;
	Counter ++;
	if( Counter == Global_u32OvfCounts )
	{
		Copy_pu8FuncScheduleGlobal();
		Once_Flag = 1;
	}
}


/*******************************************************************************************************************/

void TimerServise_voidSet_PWM(uint16 Copy_u16PWM_KHZ, uint16 Copy_u8DutyCycle_X100)
{
	Timer1_CFG_t Timer1_Fast_PMW_ICR1;
	Timer1_Fast_PMW_ICR1.Prescaler = Timer_0_1_PRESCALER_CLK_8;
	Timer1_Fast_PMW_ICR1.WFG_MODE = TIMER_1_FAST_PWM1;
	Timer1_Fast_PMW_ICR1.OC_A_MODE = TIMER_1_FAST_PWM_NON_INVERTED_MODE_A;
	Timer1_Fast_PMW_ICR1.OC_B_MODE = TIMER_1_FAST_PWM_NON_INVERTED_MODE_B;


	Timer1_SetCompareOutModeChannel_A(TIMER_1_FAST_PWM_NON_INVERTED_MODE_A);

	uint32 Local_u32PeriodTime_us_X1000 = 1000000ul / Copy_u16PWM_KHZ;
	uint8 Local_TickTime_us_X100 = 50u;

	uint32 Local_u32NumberOfOvfTicks = (uint16)( ((Local_u32PeriodTime_us_X1000 *100)/ (uint32) Local_TickTime_us_X100) /1000ul);
	Timer1_u16SetICR1Value_PWM(Local_u32NumberOfOvfTicks);

	uint16 Local_u16OnTicks = (uint16) (( ((uint32) Copy_u8DutyCycle_X100) * Local_u32NumberOfOvfTicks )/100ul);
	Timer1_voidSetCompValue(Local_u16OnTicks);
	Timers_voidInterruptEnable(TIMER1_COMPA);
	Timer1_voidInit(&Timer1_Fast_PMW_ICR1);
}
