#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "defines.h"

#include "ADC_privtate.h"
#include "ADC_cfg.h"
#include "ADC_interface.h"
#include "ADC_reg.h"

static uint16* ADC_pu16ConversionResut = NULL;
static void(*ADC_pvNotificationFunc)(void) = NULL;
static uint8 ADC_u8BusyFlag = IDLE;
static ADC_ChainConv_t* ADC_pstChainData = NULL;
static uint8 ADC_u8ChannelCounter;

static uint8 ADC_u8IntReason;



void ADC_voidInit(void)
{
#if ADC_u8REF_VOLT	== AREF_REF
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

#elif  ADC_u8REF_VOLT == AVCC_REF
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

#elif  ADC_u8REF_VOLT == INTERNAL_2560mV_REF
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);

#else
#error Wrong ADC_u8REF_VOLT configuration option

#endif

#if ADC_u8RESOLUTION	== EIGHT_BITS
	SET_BIT(ADMUX,ADMUX_ADLAR);

#elif ADC_u8RESOLUTION	== TEN_BITS
	CLR_BIT(ADMUX,ADMUX_ADLAR);

#else
#error wrong ADC_u8RESOLUTION configuration option
#endif

#if ADC_u8INT_ENABLE	== DISABLED
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
#elif ADC_u8INT_ENABLE	== ENABLED
	SET_BIT(ADCSRA,ADCSRA_ADIE);
#else
#error wrong ADC_u8INT_ENABLE configuration option
#endif

	/* configure prescaler bits */
	ADCSRA &= PRESCALER_MASK;
	ADCSRA |= ADC_u8PRESCALER_VAL;

	/*ADC Enable*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}


uint8 ADC_u16StartConversionSynch(uint8 Copy_u8Channel, uint16* Copy_pu16Result)
{
	uint8 Local_u8ErrorState = OK;
	uint32 Local_32TimeOutCounter = 0u;
	if(Copy_pu16Result != NULL)
	{
		if(ADC_u8BusyFlag == IDLE)
		{
			ADC_u8BusyFlag = BUSY;

			/*configure the analog channel*/
			ADMUX &= CHANNEL_MASK;
			ADMUX |= Copy_u8Channel;

			/*Start the conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*wait until the conversion is complete or timeout is passed*/
			while(GET_BIT(ADCSRA,ADCSRA_ADIF) ==0  &&  (Local_32TimeOutCounter < ADC_u32TIMEOUT));
			{
				Local_32TimeOutCounter++;
			}
			if(Local_32TimeOutCounter >= ADC_u32TIMEOUT)
			{
				/*Loop is broken because flag is not raised until timeout passed*/
				Local_u8ErrorState = TIMEOUT_ERR;
			}
			else
			{
				/*flag is raised before timeout passed*/
				/*Clear the conversion complete flag*/
				SET_BIT(ADCSRA,ADCSRA_ADIF);

#if ADC_u8RESOLUTION == EIGHT_BITS
				*Copy_pu16Result =  ADCH;
#elif ADC_u8RESOLUTION == TEN_BITS
				*Copy_pu16Result = ADC;
#endif
				ADC_u8BusyFlag = IDLE;
			}
		}
		else
		{
			/*ADC was busy*/
			Local_u8ErrorState = BUSY_STATE_ERR;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}


uint8 ADC_u8StartSingleConversionAsynch(uint8 Copy_u8Channel, uint16* Copy_pu16Result, void(*Copy_pvNotificationFunc)(void))
{
	uint8 Local_u8ErrorState = OK;

	if( (Copy_pu16Result != NULL) && (Copy_pvNotificationFunc != NULL))
	{
		if(ADC_u8BusyFlag == IDLE)
		{
			ADC_u8BusyFlag = BUSY;
			ADC_u8IntReason = SINGLE_CONV_ASYNCH;

			/*INIT the result pointer global*/
			ADC_pu16ConversionResut = Copy_pu16Result;

			/*INIT the notification function pointer global*/
			ADC_pvNotificationFunc = Copy_pvNotificationFunc;

			/*configure the analog channel*/
			ADMUX &= CHANNEL_MASK;
			ADMUX |= Copy_u8Channel;

			/*Start the conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*Enable the ADC conversion complete interrupt*/
			SET_BIT(ADCSRA, ADCSRA_ADIE);
		}
		else
		{
			/*ADC is busy*/
			Local_u8ErrorState = BUSY_STATE_ERR;
		}
	}

	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}


uint8 ADC_u8startChainConversionAsynch(ADC_ChainConv_t* Copy_pstChain)
{
	uint8 Local_u8Errorstate = OK;
	if ( (Copy_pstChain != NULL) && (Copy_pstChain->ChainArr != NULL) && (Copy_pstChain->NotificationFunc != NULL) && (Copy_pstChain->ResultArr != NULL) )
	{
		/*Check if ADC is Busy*/
		if (ADC_u8BusyFlag == IDLE)
		{
			/*ADC is now busy*/
			ADC_u8BusyFlag = BUSY;
			ADC_u8IntReason = CHAIN_CONV_ASYNCH;

			/*Initialize the global chain data*/
			ADC_pstChainData = Copy_pstChain;
			ADC_u8ChannelCounter = 0u;

			/*Set the first channel*/
			ADMUX &= CHANNEL_MASK;
			ADMUX |= ADC_pstChainData->ChainArr[ADC_u8ChannelCounter];

			/*Start the first Conversion*/
			SET_BIT(ADCSRA, ADCSRA_ADSC);

			/*Enable ADC conversion complete interrupt*/
			SET_BIT(ADCSRA, ADCSRA_ADIE);
		}
		else
		{
			Local_u8Errorstate = BUSY_STATE_ERR;
		}
	}
	else
	{
		Local_u8Errorstate = NULL_PTR_ERR;
	}
	return Local_u8Errorstate;
}



void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	if (ADC_u8IntReason == CHAIN_CONV_ASYNCH)
	{

#if ADC_u8RESOLUTION == EIGHT_BITS
		ADC_pstChainData->ResultArr[ADC_u8ChannelCounter] =  ADCH;
#elif ADC_u8RESOLUTION == TEN_BITS
		ADC_pstChainData->ResultArr[ADC_u8ChannelCounter] = ADC;
#endif

		/*Channel Counter increment*/
		ADC_u8ChannelCounter ++;

		if(ADC_u8ChannelCounter < ADC_pstChainData->ChainSize)
		{
			/*Chain is not finished yet*/

			/*Start the next conversion*/
			/*update the configuration of the next analog channel*/
			ADMUX &= CHANNEL_MASK;
			ADMUX |= ADC_pstChainData->ChainArr[ADC_u8ChannelCounter];

			/*start the next ADC conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);
		}
		else
		{
			/*Chain is finished*/
			/*Disable the ADC conversion complete interrupt*/
			CLR_BIT(ADCSRA, ADCSRA_ADIE);

			/*Return the ADC Busy Flag to be IDLE*/
			ADC_u8BusyFlag = IDLE;

			/*Disable the ADC interrupt*/
			CLR_BIT(ADCSRA, ADCSRA_ADIE);

			/*Invoke the application notification function*/
			if(ADC_pstChainData->NotificationFunc != NULL)
			{
				ADC_pstChainData->NotificationFunc();
			}
			else
			{
				/*Notification function pointer is NULL*/
			}
		}
	}

	/*NOT Chained ISR conversion*/
	else if (ADC_u8IntReason == SINGLE_CONV_ASYNCH)
	{
		if(ADC_pu16ConversionResut != NULL)
		{
#if ADC_u8RESOLUTION == EIGHT_BITS
			*ADC_pu16ConversionResut =  ADCH;
#elif ADC_u8RESOLUTION == TEN_BITS
			*ADC_pu16ConversionResut ADC;
#endif

			/*Disable the ADC conversion complete interrupt*/
			CLR_BIT(ADCSRA, ADCSRA_ADIE);

			ADC_u8BusyFlag = IDLE;

			/*Invoke the application notification function*/
			if(ADC_pvNotificationFunc != NULL)
			{
				ADC_pvNotificationFunc();
			}
			else
			{
				/*Notification function pointer is NULL*/
			}
		}
		else
		{
			/*conversion result pointer is NULL*/
		}
	}
}

