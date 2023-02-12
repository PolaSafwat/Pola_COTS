#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_

typedef enum
{
	TIMER0_OVF=0,
	TIMER0_COMP
}Timers_Int_Src_t;

#define Timer1_ICU_TriggerSRC_Rising	1u
#define Timer1_ICU_TriggerSRC_Falling	2u

void Timer1_voidInit(void);
void Timer0_voidInit(void);
uint8 Timers_u8SetCallBack(Timers_Int_Src_t Copy_u8TmrIntSource, void(*copy_pvCallBackFunc)(void));
void Timer0_voidSetCompValue(uint8 Copy_u8Val);
void Timer1_voidSetCompValue(uint16 Copy_u8Val);
uint16 Timer1_u16GetTCNT1Value(void);
void Timer1_u16SetTCNT1Value(uint16 Copy_u16Value);
void Timer1_voidICU_Init(void);
void Timer1_voidSetTriggerSRC(uint8 Copy_u8TriggerSRC);
void Timer1_voidICU_Enabled(void);
void Timer1_voidICU_Disabled(void);
uint16 Timer1_u16GetInCapVal(void);
uint8 Timer1_u8ICU_SetCallBack(void(*copy_pvICU_CallBackFunc)(void));

#endif
