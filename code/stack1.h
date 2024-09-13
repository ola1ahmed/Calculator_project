#ifndef _STACK_H_
#define _STACK_H_

#include "STD_TYPES.h"
typedef struct stack {
    sint8 top_index;
    uint8 stack_size;
    uint8 number_of_element;
    uint8 *ptr;  
} stack_t;

typedef enum {
    S_NOK=0,
    S_OK,
    S_EMPTY,
    S_FULL,
    S_NULL,
} stutes_t;

stack_t* createstack(stutes_t *stutes, sint8 size);
stutes_t push(stack_t *mystack, uint32 item);
uint32 pop(stack_t *mystack, stutes_t *stutes);
uint8 stacktop(stack_t *mystack, stutes_t *stutes);
sint8 IsEmpty(stack_t *mystack);
stutes_t destroystack(stack_t *mystack);

#endif
