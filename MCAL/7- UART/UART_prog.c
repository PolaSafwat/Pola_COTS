#include "STD_TYPES.h"
#include "defines.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_reg.h"
#include "UART_CFG.h"

void UART_voidInit(void)
{
	uint8 Local_u8UCSRCVal=0u;

	/*Transmitter and Receiver Enable */
	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_TXEN);

	/*8Bits, no parity, One stop bit*/
	/*Asynchronous Mode*/
	CLR_BIT(Local_u8UCSRCVal, UCSRC_UMSEL);

	/*Disable Parity*/
	CLR_BIT(Local_u8UCSRCVal, UCSRC_UPM0);
	CLR_BIT(Local_u8UCSRCVal, UCSRC_UPM1);

	/*1 Stop Bit*/
	SET_BIT(Local_u8UCSRCVal, UCSRC_USBS);

	/*Character size*/
	SET_BIT(Local_u8UCSRCVal, UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRCVal, UCSRC_UCSZ1);

	/*Register Select: UCSRC*/
	SET_BIT(Local_u8UCSRCVal, UCSRC_URSEL);

	UCSRC = Local_u8UCSRCVal;

	/*Baud rate: 9600bps*/
	UBRRH = 0;
	UBRRL = 103;

}

void UART_voidTransmit(uint8 Data)
{
	while(GET_BIT(UCSRA, UCSRA_UDRE) == 0);
	UDR = Data;
}

uint8 UART_u8ReceiveData(void)
{
	while(GET_BIT(UCSRA, UCSRA_RXC) == 0);
	return UDR;
}

uint8 UART_u8SendStringSynch(ch8 string[])
{
	uint8 Local_u8ErrorState = OK;
	if (string != NULL)
	{
		uint8 Local_u8Counter=0;
		while(string[Local_u8Counter] != '\0')
		{
			UART_voidTransmit(string[Local_u8Counter]);
			Local_u8Counter ++;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}


void UART_voidReceiveBufferSynch(uint8 Copy_Pu8BufferArr[], uint8 Copy_u8Size)
{
	uint8 Local_u8Counter=0 ;
	for(Local_u8Counter=0 ; Local_u8Counter<Copy_u8Size ; Local_u8Counter++)
	{
		Copy_Pu8BufferArr[Local_u8Counter] = UART_u8ReceiveData();
	}
	//CLR_BIT(UCSRA, UCSRA_RXC);
}
