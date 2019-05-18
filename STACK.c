#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "STACK.h"

bool g_bHeadingDown;
int32_t g_i32Next;
int32_t g_i32ElementSize;

void STACK_allocateStatic(Stack_t *ptStack, void *pvStackArray, int32_t i32StackLen, int32_t i32ElementSize)
{
    g_i32ElementSize = i32ElementSize;
    ptStack->i32Top = -1;
    ptStack->i32Len = i32StackLen;
    ptStack->pvArray = pvStackArray;
}

bool STACK_allocateDynamic(Stack_t *ptStack, int32_t i32StackLen, int32_t i32ElementSize)
{
    g_i32ElementSize = i32ElementSize;
    ptStack->i32Top = -1;
    ptStack->i32Len = i32StackLen;
    ptStack->pvArray = (void *)calloc(i32StackLen, g_i32ElementSize);

    if(ptStack->pvArray == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void STACK_deallocateDynamic(Stack_t *ptStack)
{
    free(ptStack->pvArray);
    ptStack->pvArray = NULL;
}

bool STACK_isEmpty(Stack_t *ptStack)
{
    if(ptStack->i32Top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool STACK_isFull(Stack_t *ptStack)
{
    if((ptStack->i32Top + 1) == ptStack->i32Len)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int32_t STACK_getCurrentLength(Stack_t *ptStack)
{
    return ptStack->i32Top + 1;
}

int32_t STACK_getActualLength(Stack_t *ptStack)
{
    return ptStack->i32Len;
}

bool STACK_getTop(Stack_t *ptStack, void *pvElement)
{
    void *pvStackElement;

    g_bHeadingDown = true;
    g_i32Next = ptStack->i32Top - 1;

    if(!STACK_isEmpty(ptStack))
    {
        {
            pvStackElement = ((uint8_t *)ptStack->pvArray) + (ptStack->i32Top * g_i32ElementSize);
            memcpy(pvElement, pvStackElement, g_i32ElementSize);
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool STACK_getButtom(Stack_t *ptStack, void *pvElement)
{
    void *pvStackElement;

    g_bHeadingDown = false;
    g_i32Next = 0 + 1;

    if(!STACK_isEmpty(ptStack))
    {
        {
            pvStackElement = ((uint8_t *)ptStack->pvArray) + (0 * g_i32ElementSize);
            memcpy(pvElement, pvStackElement, g_i32ElementSize);
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool STACK_getNext(Stack_t *ptStack, void *pvElement)
{
    void *pvStackElement;

    if((g_i32Next >= 0) && (g_i32Next <= ptStack->i32Top))
    {
        {
            pvStackElement = ((uint8_t *)ptStack->pvArray) + (g_i32Next * g_i32ElementSize);
            memcpy(pvElement, pvStackElement, g_i32ElementSize);
        }

        if(g_bHeadingDown == true)
        {
            g_i32Next -= 1;
        }
        else
        {
            g_i32Next += 1;
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool STACK_pop(Stack_t *ptStack, void *pvElement)
{
    void *pvStackElement;

    if(!STACK_isEmpty(ptStack))
    {
        {
            pvStackElement = ((uint8_t *)ptStack->pvArray) + (ptStack->i32Top * g_i32ElementSize);
            memcpy(pvElement, pvStackElement, g_i32ElementSize);
        }
        ptStack->i32Top -= 1;
        return true;
    }
    else
    {
        return false;
    }
}

bool STACK_push(Stack_t *ptStack, void *pvElement)
{
    void *pvStackElement;

    if(!STACK_isFull(ptStack))
    {
        ptStack->i32Top += 1;
        {
            pvStackElement = ((uint8_t *)ptStack->pvArray) + (ptStack->i32Top * g_i32ElementSize);
            memcpy(pvStackElement, pvElement, g_i32ElementSize);
        }
        return true;
    }
    else
    {
        return false;
    }
}
