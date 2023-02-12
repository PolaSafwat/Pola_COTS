#ifndef TIMERS_CFG_H_
#define TIMERS_CFG_H_

/******************************************************************************************************************************/
/*To set the Prescaler choose: 										Timer_PRESCALER_CLK_1
																	Timer_PRESCALER_CLK_8
																	Timer_PRESCALER_CLK_32
																	Timer_PRESCALER_CLK_64
																	Timer_PRESCALER_CLK_128
																	Timer_PRESCALER_CLK_256
																	Timer_PRESCALER_CLK_1024*/
#define TIMER_Prescaler												Timer_PRESCALER_CLK_8
/******************************************************************************************************************************/

/*To set the wave generation mode for Timer0 and timer2 choose: 	TIMER0_2_WFGen_Mode_NORMAL
																	TIMER0_2_WFGen_Mode_CTC
																	TIMER0_2_WFGen_Mode_FAST_PWM
																	TIMER0_2_WFGen_Mode_PHASE_CORR */
#define TIMER0_2_WFGen_Mode											TIMER0_2_WFGen_Mode_FAST_PWM
/******************************************************************************************************************************/

/*To set the wave generation mode for Timer1 choose:	            TIMER1_WFGen_Mode_NORMAL
														            TIMER1_WFGen_Mode_PWM_PHASE_CORR_8BIT
														            TIMER1_WFGen_Mode_PWM_PHASE_CORR_9BIT
														            TIMER1_WFGen_Mode_PWM_PHASE_CORR_10BIT
														            TIMER1_WFGen_Mode_CTC1
														            TIMER1_WFGen_Mode_FAST_PWM_8BIT
														            TIMER1_WFGen_Mode_FAST_PWM_9BIT
														            TIMER1_WFGen_Mode_FAST_PWM_10BIT
														            TIMER1_WFGen_Mode_PWM_PHASE_FREQ_CORR1
														            TIMER1_WFGen_Mode_PWM_PHASE_FREQ_CORR2
														            TIMER1_WFGen_Mode_PWM_PHASE_CORR1
														            TIMER1_WFGen_Mode_PWM_PHASE_CORR2
														            TIMER1_WFGen_Mode_CTC2
														            TIMER1_WFGen_Mode_FAST_PWM1
														            TIMER1_WFGen_Mode_FAST_PWM2 */
#define TIMER1_WFGen_Mode								            TIMER1_WFGen_Mode_NORMAL
/******************************************************************************************************************************/


/*To set the OUTPUT COMP Action mode for Timers 0 & 2 choose:       TIMER_OUT_0_2_COMP_NORMAL
														            TIMER_OUT_0_2_COMP_CTC_SET_PIN
														            TIMER_OUT_0_2_COMP_CTC_CLR_PIN
														            TIMER_OUT_0_2_COMP_CTC_TOG_PIN
														            TIMER_OUT_0_2_COMP_FAST_PWM_INVERTED_MODE
														            TIMER_OUT_0_2_COMP_FAST_PWM_NON_INVERTED_MODE
														            TIMER_OUT_0_2_COMP_PHASE_CORR_INVERTED_MODE
														            TIMER_OUT_0_2_COMP_PHASE_CORR_NON_INVERTED_MODE*/
#define TIMER_OUT_0_2_COMP							     	        TIMER_OUT_0_2_COMP_FAST_PWM_NON_INVERTED_MODE
/******************************************************************************************************************************/

/*To set the OUTPUT COMP Action mode for Timer1 Channel A choose:   TIMER_OUT_1_COMP_NORMAL
														            TIMER_OUT_1_COMP_CTC_SET_PIN_A
														            TIMER_OUT_1_COMP_CTC_CLR_PIN_A
														            TIMER_OUT_1_COMP_CTC_TOG_PIN_A
														            TIMER_OUT_1_COMP_FAST_PWM_INVERTED_MODE_A
														            TIMER_OUT_1_COMP_FAST_PWM_NON_INVERTED_MODE_A
														            TIMER_OUT_1_COMP_PHASE_CORR_INVERTED_MODE_A
														            TIMER_OUT_1_COMP_PHASE_CORR_NON_INVERTED_MODE_A*/
#define TIMER_OUT_1_COMP_A						          			TIMER_OUT_1_COMP_NORMAL
/******************************************************************************************************************************/

/*To set the OUTPUT COMP Action mode for Timer1 Channel B choose:   TIMER_OUT_1_COMP_NORMAL
														            TIMER_OUT_1_COMP_CTC_SET_PIN_B
														            TIMER_OUT_1_COMP_CTC_CLR_PIN_B
														            TIMER_OUT_1_COMP_CTC_TOG_PIN_B
														            TIMER_OUT_1_COMP_FAST_PWM_INVERTED_MODE_B
														            TIMER_OUT_1_COMP_FAST_PWM_NON_INVERTED_MODE_B
														            TIMER_OUT_1_COMP_PHASE_CORR_INVERTED_MODE_B
														            TIMER_OUT_1_COMP_PHASE_CORR_NON_INVERTED_MODE_B*/
#define TIMER_OUT_1_COMP_B						          			TIMER_OUT_1_COMP_NORMAL
/******************************************************************************************************************************/

/*To set the ICU Trigger SRC choose:   								TIMER1_ICU_TRIGGER_SRC_RISING
 * 																	Timer1_ICU_TRIGGER_SRC_FALLING*/

#define TIMER1_ICU_TriggerSRC										TIMER1_ICU_TRIGGER_SRC_RISING

#endif
