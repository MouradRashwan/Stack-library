#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct Stack
{
    int32_t i32Top;
    int32_t i32StackLen;
    int32_t i32ElementSize;
    int32_t i32Next;
    bool bHeadingDown;
    void *pvArray;
} Stack_t;

void Stack_allocateStatic(Stack_t *ptStack, void *pvStackArray, int32_t i32StackLen, int32_t i32ElementSize);

bool Stack_allocateDynamic(Stack_t *ptStack, int32_t i32StackLen, int32_t i32ElementSize);

void Stack_deallocateDynamic(Stack_t *ptStack);

bool Stack_isEmpty(Stack_t *ptStack);

bool Stack_isFull(Stack_t *ptStack);

int32_t Stack_getCurrentLen(Stack_t *ptStack);

int32_t Stack_getStackLen(Stack_t *ptStack);

bool Stack_getTop(Stack_t *ptStack, void *pvElement);

bool Stack_getButtom(Stack_t *ptStack, void *pvElement);

bool Stack_getNext(Stack_t *ptStack, void *pvElement);

bool Stack_pop(Stack_t *ptStack, void *pvElement);

bool Stack_push(Stack_t *ptStack, void *pvElement);

#endif // STACK_H_INCLUDED
