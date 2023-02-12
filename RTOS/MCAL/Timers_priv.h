#ifndef TIMERS_PRV_H_
#define TIMERS_PRV_H_

#define TIMER0_1_2_PRESCALER_MASK				0b11111000
#define TIMER0_1_DIVISION_BY_1					0b001


#define TIMER0_1_DIVISION_BY_8					0b010


#define TIMER0_1_DIVISION_BY_64					0b011


#define TIMER0_1_DIVISION_BY_256				0b0100


#define TIMER0_1_DIVISION_BY_1024				0b101


/***************************************************************************************************************************/


#define TIMER2_DIVISION_BY_1					0b001


#define TIMER2_DIVISION_BY_8					0b010


#define TIMER2_DIVISION_BY_32					0b011


#define TIMER2_DIVISION_BY_64					0b100


#define TIMER2_DIVISION_BY_128					0b0101


#define TIMER2_DIVISION_BY_256					0b110


#define TIMER2_DIVISION_BY_1024					0b111
/***************************************************************************************************************************/

#define TIMER1_TCCR1A_WGM_MASK					0b11111100
#define TIMER1_TCCR1B_WGM_MASK					0b11100111

#define TIMER1_TCCR1A_WGM_NORMAL				0b00000000
#define TIMER1_TCCR1B_WGM_NORMAL				0b00000000

#define TIMER1_TCCR1A_WGM_PWM_PHASE_CORR_8BIT	0b00000001
#define TIMER1_TCCR1B_WGM_PWM_PHASE_CORR_8BIT	0b00000000

#define TIMER1_TCCR1A_WGM_PWM_PHASE_CORR_9BIT	0b00000010
#define TIMER1_TCCR1B_WGM_PWM_PHASE_CORR_9BIT	0b00000000

#define TIMER1_TCCR1A_WGM_PWM_PHASE_CORR_10BIT	0b00000011
#define TIMER1_TCCR1B_WGM_PWM_PHASE_CORR_10BIT	0b00000000

#define TIMER1_TCCR1A_WGM_CTC1					0b00000000
#define TIMER1_TCCR1B_WGM_CTC1					0b00001000

#define TIMER1_TCCR1A_WGM_FAST_PWM_8BIT			0b00000001
#define TIMER1_TCCR1B_WGM_FAST_PWM_8BIT			0b00001000

#define TIMER1_TCCR1A_WGM_FAST_PWM_9BIT			0b00000010
#define TIMER1_TCCR1B_WGM_FAST_PWM_9BIT			0b00001000

#define TIMER1_TCCR1A_WGM_FAST_PWM_10BIT		0b00000011
#define TIMER1_TCCR1B_WGM_FAST_PWM_10BIT		0b00001000

#define TIMER1_TCCR1A_WGM_PWM_PHASE_FREQ_CORR1	0b00000000
#define TIMER1_TCCR1B_WGM_PWM_PHASE_FREQ_CORR1	0b00010000

#define TIMER1_TCCR1A_WGM_PWM_PHASE_FREQ_CORR2	0b00000001
#define TIMER1_TCCR1B_WGM_PWM_PHASE_FREQ_CORR2	0b00010000

#define TIMER1_TCCR1A_WGM_PWM_PHASE_CORR1		0b00000010
#define TIMER1_TCCR1B_WGM_PWM_PHASE_CORR1		0b00010000

#define TIMER1_TCCR1A_WGM_PWM_PHASE_CORR2		0b00000011
#define TIMER1_TCCR1B_WGM_PWM_PHASE_CORR2		0b00010000

#define TIMER1_TCCR1A_WGM_CTC2					0b00000000
#define TIMER1_TCCR1B_WGM_CTC2					0b00011000

#define TIMER1_TCCR1A_WGM_FAST_PWM1				0b00000010
#define TIMER1_TCCR1B_WGM_FAST_PWM1				0b00011000

#define TIMER1_TCCR1A_WGM_FAST_PWM2				0b00000011
#define TIMER1_TCCR1B_WGM_FAST_PWM2				0b00011000

/***************************************************************************************************************************/

#define WDT_Time_MASK							0b11111000
#define WDT_Time_16300us						0b000


#define WDT_Time_32500us						0b001


#define WDT_Time_65000us						0b010


#define WDT_Time_130ms							0b0011


#define WDT_Time_260ms							0b100


#define WDT_Time_520ms							0b101


#define WDT_Time_1s								0b110


#define WDT_Time_2100ms							0b111
/***************************************************************************************************************************/

#define	TIMER0_2_WFGen_Mode_NORMAL      				1u
#define	TIMER0_2_WFGen_Mode_CTC         				2u
#define	TIMER0_2_WFGen_Mode_FAST_PWM    				3u
#define	TIMER0_2_WFGen_Mode_PHASE_CORR  				4u
/****************************************************************************************************************************/

#define	TIMER1_WFGen_Mode_NORMAL						1u
#define	TIMER1_WFGen_Mode_PWM_PHASE_CORR_8BIT			2u
#define	TIMER1_WFGen_Mode_PWM_PHASE_CORR_9BIT			3u
#define	TIMER1_WFGen_Mode_PWM_PHASE_CORR_10BIT			4u
#define	TIMER1_WFGen_Mode_CTC1							5u
#define	TIMER1_WFGen_Mode_FAST_PWM_8BIT					6u
#define	TIMER1_WFGen_Mode_FAST_PWM_9BIT					7u
#define	TIMER1_WFGen_Mode_FAST_PWM_10BIT				8u
#define	TIMER1_WFGen_Mode_PWM_PHASE_FREQ_CORR1			9u
#define	TIMER1_WFGen_Mode_PWM_PHASE_FREQ_CORR2			10u
#define	TIMER1_WFGen_Mode_PWM_PHASE_CORR1				11u
#define	TIMER1_WFGen_Mode_PWM_PHASE_CORR2				12u
#define	TIMER1_WFGen_Mode_CTC2							13u
#define	TIMER1_WFGen_Mode_FAST_PWM1						15u
#define	TIMER1_WFGen_Mode_FAST_PWM2						16u
/***************************************************************************************************************************/

#define TIMER_OUT_0_2_COMP_NORMAL						1u
#define TIMER_OUT_0_2_COMP_CTC_SET_PIN					2u
#define TIMER_OUT_0_2_COMP_CTC_CLR_PIN					3u
#define TIMER_OUT_0_2_COMP_CTC_TOG_PIN           	    4u
#define TIMER_OUT_0_2_COMP_FAST_PWM_INVERTED_MODE   	5u
#define TIMER_OUT_0_2_COMP_FAST_PWM_NON_INVERTED_MODE	6u
#define TIMER_OUT_0_2_COMP_PHASE_CORR_INVERTED_MODE		7u
#define TIMER_OUT_0_2_COMP_PHASE_CORR_NON_INVERTED_MODE	8u
/***************************************************************************************************************************/

#define TIMER_OUT_1_COMP_NORMAL							1u

#define TIMER_OUT_1_COMP_CTC_SET_PIN_A					2u
#define TIMER_OUT_1_COMP_CTC_CLR_PIN_A					3u
#define TIMER_OUT_1_COMP_CTC_TOG_PIN_A          	    4u
#define TIMER_OUT_1_COMP_FAST_PWM_INVERTED_MODE_A  		5u
#define TIMER_OUT_1_COMP_FAST_PWM_NON_INVERTED_MODE_A	6u
#define TIMER_OUT_1_COMP_PHASE_CORR_INVERTED_MODE_A		7u
#define TIMER_OUT_1_COMP_PHASE_CORR_NON_INVERTED_MODE_A	8u

#define TIMER_OUT_1_COMP_CTC_SET_PIN_B					9u
#define TIMER_OUT_1_COMP_CTC_CLR_PIN_B					10u
#define TIMER_OUT_1_COMP_CTC_TOG_PIN_B          		11u
#define TIMER_OUT_1_COMP_FAST_PWM_INVERTED_MODE_B  		12u
#define TIMER_OUT_1_COMP_FAST_PWM_NON_INVERTED_MODE_B	13u
#define TIMER_OUT_1_COMP_PHASE_CORR_INVERTED_MODE_B		14u
#define TIMER_OUT_1_COMP_PHASE_CORR_NON_INVERTED_MODE_B	15u
/***************************************************************************************************************************/

#define Timer_PRESCALER_CLK_1							1u
#define Timer_PRESCALER_CLK_8							2u
#define Timer_PRESCALER_CLK_32							3u
#define Timer_PRESCALER_CLK_64							4u
#define Timer_PRESCALER_CLK_128							5u
#define Timer_PRESCALER_CLK_256							6u
#define Timer_PRESCALER_CLK_1024						7u
/***************************************************************************************************************************/

#define TIMER1_ICU_TRIGGER_SRC_RISING					1u
#define Timer1_ICU_TRIGGER_SRC_FALLING					2u
/***************************************************************************************************************************/

#endif
