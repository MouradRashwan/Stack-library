#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct Stack
{
    int32_t i32Top;
    int32_t i32Len;
    void *pvArray;
} Stack_t;

void STACK_allocateStatic(Stack_t *ptStack, void *pvStackArray, int32_t i32StackLen, int32_t i32ElementSize);

bool STACK_allocateDynamic(Stack_t *ptStack, int32_t i32StackLen, int32_t i32ElementSize);

void STACK_deallocateDynamic(Stack_t *ptStack);

bool STACK_isEmpty(Stack_t *ptStack);

bool STACK_isFull(Stack_t *ptStack);

int32_t STACK_getCurrentLength(Stack_t *ptStack);

int32_t STACK_getActualLength(Stack_t *ptStack);

bool STACK_getTop(Stack_t *ptStack, void *pvElement);

bool STACK_getButtom(Stack_t *ptStack, void *pvElement);

bool STACK_getNext(Stack_t *ptStack, void *pvElement);

bool STACK_pop(Stack_t *ptStack, void *pvElement);

bool STACK_push(Stack_t *ptStack, void *pvElement);

#endif // STACK_H_INCLUDED
