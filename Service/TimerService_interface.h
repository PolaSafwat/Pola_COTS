#ifndef TIMERSERVICE_INTERFACE_H_
#define TIMERSERVICE_INTERFACE_H_


typedef enum {
	Periodic,
	Once,
}ScheduleFuncState_t;

void TimerService_voidPWM_Measure(uint8* Copy_pu8DutyCycle, uint32* Copy_pu32PeriodTime);

uint8 TimerServise_voidSchedule_MS(uint32 Copy_Time_MS, ScheduleFuncState_t Periodic_Once , void (*Copy_pu8Func)(void));

void TimerServise_voidSet_PWM(uint16 Copy_u16PWM_KHZ, uint16 Copy_u8DutyCycle_X100);

#endif
