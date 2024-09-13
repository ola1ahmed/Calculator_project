#ifndef _APP_H_
#define _APP_H_
#include "stack1.h"
#include "ErrorState.h"
uint8 u8periority(uint8 Copy_u8operator);
uint8* pu8_postfix(const uint8 *Copy_infix);
sint32 su32_Result(uint8 *Local_au8postfix,uint8 *Copy_pu8reminder);
#endif
