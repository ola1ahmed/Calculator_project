/*
 * app.c
 *
 *  Created on: Sep 12, 2024
 *      Author: olaah
 */

#include "app.h"

stack_t *mystack = NULL;
stutes_t stutes;

uint8 u8periority(uint8 Copy_u8operator)
{
    switch (Copy_u8operator)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

uint8* pu8_postfix(const uint8 *Copy_infix)
{
    uint8 Local_counter = 0;
    uint8 Local_repcounter = 0;
    uint8 Local_opIdx = 0;
    uint8 per = 0;

    mystack = createstack(&stutes, 16);
    static uint8 Local_au8output[32];

    if (Copy_infix != NULL)
    {
        while (Copy_infix[Local_counter] != '\0')
        {
            if (Copy_infix[Local_counter] >= '0' && Copy_infix[Local_counter] <= '9')
            {

                // Handle multi-digit numbers
                while (Copy_infix[Local_counter] >= '0' && Copy_infix[Local_counter] <= '9')
                {
                    Local_au8output[Local_opIdx] = Copy_infix[Local_counter];
                    Local_opIdx++;
                    Local_counter++;
                }
                Local_au8output[Local_opIdx++] = ' '; // Add space to separate numbers
                Local_counter--; // Adjust to process next character correctly

            }
            else
            {
                per = u8periority(Copy_infix[Local_counter]);

                /*handle multiple input operator*/
                Local_repcounter=Local_counter;
                if((Copy_infix[Local_repcounter]==Copy_infix[Local_repcounter-1])&&Local_repcounter!=0)
                {
                	Local_counter++;
                	Local_repcounter++;
                	continue;
                }

                while (!IsEmpty(mystack) && per <= u8periority(stacktop(mystack, &stutes)))
                {
                    Local_au8output[Local_opIdx] = pop(mystack, &stutes);
                    Local_opIdx++;
                }
                push(mystack, Copy_infix[Local_counter]);
            }

            Local_counter++;
        }


        while (!IsEmpty(mystack))
        {
            Local_au8output[Local_opIdx] = pop(mystack, &stutes);
            Local_opIdx++;
        }


        Local_au8output[Local_opIdx] = '\0';
        destroystack(mystack);
        return Local_au8output;
    }

    return NULL;
}
sint32 su32_Result(uint8 *Local_au8postfix,uint8 *Copy_pu8reminder)
{
    uint8 Local_counter = 0;
    uint8 Local_opercounter= 0;

    sint32 Result = 0;
    uint32 first_op = 0, second_op = 0;
    uint8 rem=0;
    *Copy_pu8reminder=0;


    mystack = createstack(&stutes, 16);

    if (Local_au8postfix != NULL)
    {
        while (Local_au8postfix[Local_counter] != '=')
        {

            if (Local_au8postfix[Local_counter] >= '0' && Local_au8postfix[Local_counter] <= '9')
            {
            	uint32 num = 0;
            	while (Local_au8postfix[Local_counter] >= '0' && Local_au8postfix[Local_counter] <= '9')
            	{

            	    num = num * 10 + (Local_au8postfix[Local_counter] - '0');
            	    Local_counter++;
            	}
                push(mystack,num);
                Local_counter--; // Adjust counter

            }
            else if (Local_au8postfix[Local_counter] == ' ')
            {
            	Local_counter++;
            	continue;
            }
            else
            {
                if (IsEmpty(mystack)) return -1;
                second_op = pop(mystack, &stutes);

                if (IsEmpty(mystack)) return -1;
                first_op = pop(mystack, &stutes);

                switch (Local_au8postfix[Local_counter])
                {
                case '+':
                    Result = first_op + second_op;
                    break;
                case '-':
                    Result = first_op - second_op;
                    break;
                case '*':
                    Result = first_op * second_op;
                    break;
                case '/':
                    if (second_op == 0) return -1; // Error: division by zero
					rem=first_op % second_op;
					*Copy_pu8reminder=(( (float32)(float32)rem/(float32)second_op) *10);
                    Result = first_op / second_op;
                    break;
                default:
                    return -1;
                }


                push(mystack, Result);
            }
            Local_counter++;
        }

        if (IsEmpty(mystack)) return 0;
        Result = pop(mystack, &stutes);

        destroystack(mystack);
        return Result;
    }
    else
    {
        return -1;
    }
}
