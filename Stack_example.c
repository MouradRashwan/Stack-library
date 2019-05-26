#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#include "Stack.h"

#define STACK_LENGTH                5
#define STACK_STATIC_ALLOCATION     0

typedef struct Object
{
    int32_t i32Val1;
    int32_t i32Val2;
} Object_t;

int main(void)
{
    printf("Stack Starting ...\n\n");

    int32_t ii;
    Stack_t tStack;
    Object_t tObject;

#if(STACK_STATIC_ALLOCATION == 0)
    if(Stack_allocateDynamic(&tStack, STACK_LENGTH, sizeof(Object_t)) == false)
    {
        printf("<<ERROR>> Heap Memory is Full");
        return 0;
    }
#else
    static Object_t atObject[STACK_LENGTH];
    Stack_allocateStatic(&tStack, atObject, STACK_LENGTH, sizeof(Object_t));
#endif

    for(ii=0; ii<STACK_LENGTH; ii++)
    {
        tObject.i32Val1 = ii + 1;
        tObject.i32Val2 = (ii + 1) * 10;
        Stack_push(&tStack, &tObject);
    }

    Stack_pop(&tStack, &tObject);
    tObject.i32Val1 = 6;
    tObject.i32Val2 = 60;
    Stack_push(&tStack, &tObject);

    Stack_getTop(&tStack, &tObject);
    printf("(%u|%u) ", tObject.i32Val1, tObject.i32Val2);
    while(Stack_getNext(&tStack, &tObject))
    {
        printf("(%u|%u) ", tObject.i32Val1, tObject.i32Val2);
    }
    printf("\n\n");

    Stack_getButtom(&tStack, &tObject);
    printf("(%u|%u) ", tObject.i32Val1, tObject.i32Val2);
    while(Stack_getNext(&tStack, &tObject))
    {
        printf("(%u|%u) ", tObject.i32Val1, tObject.i32Val2);
    }
    printf("\n\n");

#if(STACK_STATIC_ALLOCATION == 0)
    Stack_deallocateDynamic(&tStack);
#endif

    return 0;
}
