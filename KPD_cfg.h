#ifndef KPD_CFG_h
#define KPD_CFG_h

#include "DIO_interface.h"
#include "KPD_prv.h"
#include "ErrorState.h"
#include "STD_TYPES.h"

#define KEYPAD_COL_PORT		DIO_u8PORTC
#define KEYPAD_ROW_PORT		DIO_u8PORTC

#define KEYPAD_COL0_PIN     DIO_u8PIN0
#define KEYPAD_COL1_PIN     DIO_u8PIN1
#define KEYPAD_COL2_PIN     DIO_u8PIN2
#define KEYPAD_COL3_PIN     DIO_u8PIN3

#define KEYPAD_ROW0_PIN     DIO_u8PIN4
#define KEYPAD_ROW1_PIN     DIO_u8PIN5
#define KEYPAD_ROW2_PIN     DIO_u8PIN6
#define KEYPAD_ROW3_PIN     DIO_u8PIN7

#define KEYPAD_ARR			{{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'c','0','=','+'}}
#define KEYPAD_PRESSED_KEY	0xff

#endif
