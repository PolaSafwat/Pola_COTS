#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_

/************************************************************************************************************************************/
/*To make an ISR (SW Interrupt) for each interrupt src*/
typedef enum
{
	TIMER0_OVF=0,
	TIMER0_COMP,
	TIMER2_OVF,
	TIMER2_COMP,
	TIMER1_CAPT,
	TIMER1_COMPA,
	TIMER1_COMPB,
	TIMER1_OVF
}Timers_Int_Src_t;


typedef enum {
	TIMER_0_2_NORMAL=0,
	TIMER_0_2_CTC,
	TIMER_0_2_FAST_PWM,
	TIMER_0_2_PHASE_CORR
}TIMER_0_2_WFGen_Mode_t;

typedef enum {
	TIMER_1_NORMAL=0,
	TIMER_1_PWM_PHASE_CORR_8BIT,
	TIMER_1_PWM_PHASE_CORR_9BIT,
	TIMER_1_PWM_PHASE_CORR_10BIT,
	TIMER_1_CTC1,
	TIMER_1_FAST_PWM_8BIT,
	TIMER_1_FAST_PWM_9BIT,
	TIMER_1_FAST_PWM_10BIT,
	TIMER_1_PWM_PHASE_FREQ_CORR1,
	TIMER_1_PWM_PHASE_FREQ_CORR2,
	TIMER_1_PWM_PHASE_CORR1,
	TIMER_1_PWM_PHASE_CORR2,
	TIMER_1_CTC2,
	TIMER_1_RESERVED,
	TIMER_1_FAST_PWM1,
	TIMER_1_FAST_PWM2,
}TIMER_1_WFGen_Mode_t;


typedef enum {
	TIMER_0_2_NORMAL_OUT,
	TIMER_0_2_CTC_SET_PIN,
	TIMER_0_2_CTC_CLR_PIN,
	TIMER_0_2_CTC_TOG_PIN,
	TIMER_0_2_FAST_PWM_INVERTED_MODE,
	TIMER_0_2_FAST_PWM_NON_INVERTED_MODE,
	TIMER_0_2_PHASE_CORR_INVERTED_MODE,
	TIMER_0_2_PHASE_CORR_NON_INVERTED_MODE,
}TIMER_0_2_OUT_COMP_t;

typedef enum {
	TIMER_1_NORMAL_A,
	TIMER_1_CTC_SET_PIN_A,
	TIMER_1_CTC_CLR_PIN_A,
	TIMER_1_CTC_TOG_PIN_A,
	TIMER_1_FAST_PWM_INVERTED_MODE_A,
	TIMER_1_FAST_PWM_NON_INVERTED_MODE_A,
	TIMER_1_PHASE_CORR_INVERTED_MODE_A,
	TIMER_1_PHASE_CORR_NON_INVERTED_MODE_A,
}TIMER_1_OUT_COMP_A_t;

typedef enum {
	TIMER_1_NORMAL_OUT_B,
	TIMER_1_CTC_SET_PIN_B,
	TIMER_1_CTC_CLR_PIN_B,
	TIMER_1_CTC_TOG_PIN_B,
	TIMER_1_FAST_PWM_INVERTED_MODE_B,
	TIMER_1_FAST_PWM_NON_INVERTED_MODE_B,
	TIMER_1_PHASE_CORR_INVERTED_MODE_B,
	TIMER_1_PHASE_CORR_NON_INVERTED_MODE_B,
}TIMER_1_OUT_COMP_B_t;

typedef enum {
	Timer_0_1_PRESCALER_CLK_1,
	Timer_0_1_PRESCALER_CLK_8,
	Timer_0_1_PRESCALER_CLK_64,
	Timer_0_1_PRESCALER_CLK_256,
	Timer_0_1_PRESCALER_CLK_1024,
}TIMER_0_1_PreScaler_t;


typedef enum {
	Timer_2_PRESCALER_CLK_1,
	Timer_2_PRESCALER_CLK_8,
	Timer_2_PRESCALER_CLK_32,
	Timer_2_PRESCALER_CLK_64,
	Timer_2_PRESCALER_CLK_128,
	Timer_2_PRESCALER_CLK_256,
	Timer_2_PRESCALER_CLK_1024,
}TIMER_2_PreScaler_t;

typedef enum{
	Timer1_ICU_TriggerSRC_Rising=1,
	Timer1_ICU_TriggerSRC_Falling,
}TIMER1_ICU_TriggerSRC_t;

typedef enum{
	WDT_Time_16300us,
	WDT_Time_32500us,
	WDT_Time_65000us,
	WDT_Time_130ms,
	WDT_Time_260ms,
	WDT_Time_520ms,
	WDT_Time_1s,
	WDT_Time_2100ms,
}WDT_Time_Select_t;
/************************************************************************************************************************************/


typedef struct{
	TIMER_0_2_WFGen_Mode_t WFG_MODE;
	TIMER_0_2_OUT_COMP_t OC_MODE;
	TIMER_0_1_PreScaler_t Prescaler;
}Timer0_CFG_t;

typedef struct{
	TIMER_0_2_WFGen_Mode_t WFG_MODE;
	TIMER_0_2_OUT_COMP_t OC_MODE;
	TIMER_2_PreScaler_t Prescaler;
}Timer2_CFG_t;

typedef struct{
	TIMER_1_WFGen_Mode_t WFG_MODE;
	TIMER_1_OUT_COMP_A_t OC_A_MODE;
	TIMER_1_OUT_COMP_B_t OC_B_MODE;
	TIMER_0_1_PreScaler_t Prescaler;
}Timer1_CFG_t;
/************************************************************************************************************************************/


void Timer0_voidInit(Timer0_CFG_t* Timer0);
void Timer0_voidInit_CFG(void);
void Timer1_voidInit(Timer1_CFG_t* Timer1);
void Timer1_voidInit_CFG(void);
void Timer2_voidInit(Timer2_CFG_t* Timer2);
void Timer2_voidInit_CFG(void);
uint8 Timers_u8SetCallBack(Timers_Int_Src_t Copy_u8TmrIntSource, void(*copy_pvCallBackFunc)(void));
void Timer0_SetCompareOutMode(TIMER_0_2_OUT_COMP_t Copy_CompMode);
void Timer2_SetCompareOutMode(TIMER_0_2_OUT_COMP_t Copy_CompMode);
void Timer1_SetCompareOutModeChannel_A(TIMER_1_OUT_COMP_A_t Copy_CompMode);
void Timer1_SetCompareOutModeChannel_B(TIMER_1_OUT_COMP_B_t Copy_CompMode);
void Timers_voidInterruptEnable(Timers_Int_Src_t Copy_IntSRC);
void Timers_voidInterruptDisable(Timers_Int_Src_t Copy_IntSRC);
void Timer1_voidICU_SetTriggerSRC(uint8 Copy_u8TriggerSRC);
void WDT_voidEnable(void);
void WDT_voidDisable(void);
void WDT_voidTimeSelect(WDT_Time_Select_t Copy_Time);

void Timer0_voidSetCompValue(uint8 Copy_u8Val);
void Timer2_voidSetCompValue(uint8 Copy_u8Val);
void Timer1_voidSetCompValue(uint16 Copy_u8Val);
uint16 Timer1_u16GetTCNT1Value(void);
void Timer1_u16SetTCNT1Value(uint16 Copy_u16Value);
void Timer0_u16SetTCNT0Value(uint16 Copy_u16Value);
uint16 Timer1_u16GetInCapVal(void);
uint16 Timer1_u16GetICR1Value_PWM(void);
void Timer1_u16SetICR1Value_PWM(uint16 Copy_u16Value);



#endif
