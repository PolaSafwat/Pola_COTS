#include "STD_TYPES.h"


sint32 Map (sint32 InputRangeMin, sint32 InputRangeMax, sint32 OutputRangeMin, sint32 OutputRangeMax, sint32 InputValue)
{
	sint32 Local_s32OutputValue;
	Local_s32OutputValue = ( ((OutputRangeMax - OutputRangeMin) * (InputValue - InputRangeMin)) / (InputRangeMax - InputRangeMin) ) + OutputRangeMin;
	return Local_s32OutputValue;
}
