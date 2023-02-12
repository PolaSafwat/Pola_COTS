#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


void UART_voidInit(void);

void UART_voidTransmit(uint8 Data);

uint8 UART_u8ReceiveData(void);

uint8 UART_u8SendStringSynch(ch8 string[]);

void UART_voidReceiveBufferSynch(uint8 Copy_Pu8BufferArr[], uint8 Copy_u8Size);


#endif
