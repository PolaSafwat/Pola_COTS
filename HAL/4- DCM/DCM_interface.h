#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_

#define DCM_ROTATE_CLKWISE		1u
#define DCM_ROTATE_C_CLKWISE	2u
#define DCM_STOP				3u


typedef struct {
	uint8 DCM_PORT;
	uint8 DCM_PIN1;
	uint8 DCM_PIN2;
}DCM_T;


uint8 DCM_u8RotateStatus(uint8 Copy_u8RotateStatus, const DCM_T *Copy_pu8DCMPtr);

#endif
