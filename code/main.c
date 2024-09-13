/*
 * main.c
 *
 *  Created on: Sep 8, 2024
 *      Author: olaah
 */

#include "DIO_interface.h"
#include "KPD_interface.h"
#include "CLCD_interface.h"
#include "PORT_interface.h"
#include "app.h"

void main()
{
    uint8 PressedKey;
    uint8 Local_au8operation[16];
    uint8 Local_counter = 0;
    uint8 *Local_au8output;
    sint32 Result;
    uint8 reminder=0;

    PORT_voidInit();
    CLCD_voidInit();

    while (1)
    {
        do
        {
            PressedKey = KEYPAD_u8PressedKey();
            if (PressedKey != 0xff )
            {
            	if(PressedKey=='c' )
            	{
            		if(Local_counter==0)
            		{
            			CLCD_voidClearDisplay();
            	        Local_counter = 0;
            	        Result=0;
            	        Local_au8operation[0]='\0';
            	        voidGotoXY(0,0);
            		}
            		else
            		{
						Local_counter=Local_counter-1;
						voidGotoXY(Local_counter,0);
						CLCD_voidSendData(' ');
						voidGotoXY(Local_counter, 0);
            		}
            	}
            	else
            	{
					CLCD_voidSendData(PressedKey);
					Local_au8operation[Local_counter] = PressedKey;
					Local_counter++;
            	}
            }

        }while (PressedKey != '=');
        Local_au8operation[Local_counter] = '\0';



        // Convert to postfix and display
        Local_au8output=pu8_postfix(Local_au8operation);

        voidGotoXY(0, 1);
        CLCD_u8SendString("Result=");
        Result=su32_Result(Local_au8output,&reminder);
        if(Result!=-1)
        {
        // Display result on LCD
        CLCD_u8SendNumber(Result);
        CLCD_voidSendData('.');
        CLCD_u8SendNumber(reminder);
        }
        else
        {
        	CLCD_u8SendString("error");
        }

        // Reset counter for next input
        Local_counter = 0;

    }
}

