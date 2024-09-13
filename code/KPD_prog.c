#include "KPD_interface.h"

uint8 KEYPAD_u8PressedKey(void){
	uint8 Local_u8ColIdx=0, Local_u8RowIdx=0;
	uint8 Local_u8preesedkey=KEYPAD_PRESSED_KEY;
	uint8 Local_au8ARR[ROW_NUM][COL_NUM]=KEYPAD_ARR;
	uint8 Local_au8Colpin[COL_NUM]={KEYPAD_COL0_PIN,KEYPAD_COL1_PIN,KEYPAD_COL2_PIN,KEYPAD_COL3_PIN};
	uint8 Local_au8Rowpin[ROW_NUM]={KEYPAD_ROW0_PIN,KEYPAD_ROW1_PIN,KEYPAD_ROW2_PIN,KEYPAD_ROW3_PIN};
	uint8 Local_ButtonState;

	for(Local_u8ColIdx=0;Local_u8ColIdx<COL_NUM;Local_u8ColIdx++)
	{
		DIO_u8SetPinValue(KEYPAD_COL_PORT,Local_au8Colpin[Local_u8ColIdx],DIO_u8PIN_LOW);
		for(Local_u8RowIdx=0;Local_u8RowIdx<ROW_NUM;Local_u8RowIdx++)
		{
			DIO_u8ReadPinValue(KEYPAD_ROW_PORT,Local_au8Rowpin[Local_u8RowIdx],&Local_ButtonState);
			if(Local_ButtonState==DIO_u8PIN_LOW)
			{
				Local_u8preesedkey=Local_au8ARR[Local_u8RowIdx][Local_u8ColIdx];
				while(Local_ButtonState==DIO_u8PIN_LOW)
				{
					DIO_u8ReadPinValue(KEYPAD_ROW_PORT,Local_au8Rowpin[Local_u8RowIdx],&Local_ButtonState);
				}
				return Local_u8preesedkey;

			}
		}
		DIO_u8SetPinValue(KEYPAD_COL_PORT,Local_au8Colpin[Local_u8ColIdx],DIO_u8PIN_HIGH);
	}


	return Local_u8preesedkey;

}
