#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>

#include "DIO_interface.h"
#include "PusButtonRead_interface.h"



uint8 PushButtonRead (uint8 Copy_u8PORT, uint8 Copy_u8PIN)
{
	uint8 Local_u8Read[3];
	uint8 i;
	uint8 flag =0;
	while(flag==0)
	{
		for(i=0;i<3;i++)
		{
			if (Copy_u8PORT == PBR_u8PORTA)
			{
				switch(Copy_u8PIN)
				{
				case 0: DIO_u8GetPinValue(DIO_u8PORTA,DIO_u8PIN0,&Local_u8Read[i]); break;
				case 1: DIO_u8GetPinValue(DIO_u8PORTA,DIO_u8PIN1,&Local_u8Read[i]); break;
				case 2: DIO_u8GetPinValue(DIO_u8PORTA,DIO_u8PIN2,&Local_u8Read[i]); break;
				case 3: DIO_u8GetPinValue(DIO_u8PORTA,DIO_u8PIN3,&Local_u8Read[i]); break;
				case 4: DIO_u8GetPinValue(DIO_u8PORTA,DIO_u8PIN4,&Local_u8Read[i]); break;
				case 5: DIO_u8GetPinValue(DIO_u8PORTA,DIO_u8PIN5,&Local_u8Read[i]); break;
				case 6: DIO_u8GetPinValue(DIO_u8PORTA,DIO_u8PIN6,&Local_u8Read[i]); break;
				case 7: DIO_u8GetPinValue(DIO_u8PORTA,DIO_u8PIN7,&Local_u8Read[i]); break;
				}
			}
			else if (Copy_u8PORT == PBR_u8PORTB)
			{
				switch(Copy_u8PIN)
				{
				case 0: DIO_u8GetPinValue(DIO_u8PORTB,DIO_u8PIN0,&Local_u8Read[i]); break;
				case 1: DIO_u8GetPinValue(DIO_u8PORTB,DIO_u8PIN1,&Local_u8Read[i]); break;
				case 2: DIO_u8GetPinValue(DIO_u8PORTB,DIO_u8PIN2,&Local_u8Read[i]); break;
				case 3: DIO_u8GetPinValue(DIO_u8PORTB,DIO_u8PIN3,&Local_u8Read[i]); break;
				case 4: DIO_u8GetPinValue(DIO_u8PORTB,DIO_u8PIN4,&Local_u8Read[i]); break;
				case 5: DIO_u8GetPinValue(DIO_u8PORTB,DIO_u8PIN5,&Local_u8Read[i]); break;
				case 6: DIO_u8GetPinValue(DIO_u8PORTB,DIO_u8PIN6,&Local_u8Read[i]); break;
				case 7: DIO_u8GetPinValue(DIO_u8PORTB,DIO_u8PIN7,&Local_u8Read[i]); break;
				}
			}
			else if (Copy_u8PORT == PBR_u8PORTC)
			{
				switch(Copy_u8PIN)
				{
				case 0: DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN0,&Local_u8Read[i]); break;
				case 1: DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN1,&Local_u8Read[i]); break;
				case 2: DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN2,&Local_u8Read[i]); break;
				case 3: DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN3,&Local_u8Read[i]); break;
				case 4: DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN4,&Local_u8Read[i]); break;
				case 5: DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN5,&Local_u8Read[i]); break;
				case 6: DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN6,&Local_u8Read[i]); break;
				case 7: DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN7,&Local_u8Read[i]); break;
				}
			}
			else if (Copy_u8PORT == PBR_u8PORTD)
			{
				switch(Copy_u8PIN)
				{
				case 0: DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN0,&Local_u8Read[i]); break;
				case 1: DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN1,&Local_u8Read[i]); break;
				case 2: DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN2,&Local_u8Read[i]); break;
				case 3: DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN3,&Local_u8Read[i]); break;
				case 4: DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN4,&Local_u8Read[i]); break;
				case 5: DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN5,&Local_u8Read[i]); break;
				case 6: DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN6,&Local_u8Read[i]); break;
				case 7: DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN7,&Local_u8Read[i]); break;
				}
			}
			_delay_ms(1);
		}
		if (Local_u8Read[0]==Local_u8Read[1] && Local_u8Read[1] == Local_u8Read[2])
		{
			flag = 1;
		}
	}
	return Local_u8Read[1];
}
