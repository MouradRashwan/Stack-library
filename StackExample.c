#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#include "STACK.h"

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
    if(STACK_allocateDynamic(&tStack, STACK_LENGTH, sizeof(Object_t)) == false)
    {
        printf("<<ERROR>> Heap Memory is Full");
    }
#else
    static Object_t atObject[STACK_LENGTH];
    STACK_allocateStatic(&tStack, atObject, STACK_LENGTH, sizeof(Object_t));
#endif

    for(ii=0; ii<STACK_LENGTH; ii++)
    {
        tObject.i32Val1 = ii + 1;
        tObject.i32Val2 = (ii + 1) * 10;
        STACK_push(&tStack, &tObject);
    }

    STACK_pop(&tStack, &tObject);
    tObject.i32Val1 = 6;
    tObject.i32Val2 = 60;
    STACK_push(&tStack, &tObject);

    STACK_getTop(&tStack, &tObject);
    printf("(%u|%u) ", tObject.i32Val1, tObject.i32Val2);
    while(STACK_getNext(&tStack, &tObject))
    {
        printf("(%u|%u) ", tObject.i32Val1, tObject.i32Val2);
    }
    printf("\n\n");

    STACK_getButtom(&tStack, &tObject);
    printf("(%u|%u) ", tObject.i32Val1, tObject.i32Val2);
    while(STACK_getNext(&tStack, &tObject))
    {
        printf("(%u|%u) ", tObject.i32Val1, tObject.i32Val2);
    }
    printf("\n\n");

    return 0;
}
