#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_reg.h"

void GIE_u8GlobalInterruptEnable (void)
{
	SET_BIT(SREG,7);
}

void GIE_u8GlobalInterruptDisable (void)
{
	CLR_BIT(SREG,7);
}
