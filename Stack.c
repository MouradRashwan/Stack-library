#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "Stack.h"

void Stack_allocateStatic(Stack_t *ptStack, void *pvStackArray, int32_t i32StackLen, int32_t i32ElementSize)
{
    ptStack->i32ElementSize = i32ElementSize;
    ptStack->i32Top = -1;
    ptStack->i32StackLen = i32StackLen;
    ptStack->pvArray = pvStackArray;
}

bool Stack_allocateDynamic(Stack_t *ptStack, int32_t i32StackLen, int32_t i32ElementSize)
{
    ptStack->i32ElementSize = i32ElementSize;
    ptStack->i32Top = -1;
    ptStack->i32StackLen = i32StackLen;
    ptStack->pvArray = (void *)calloc(i32StackLen, ptStack->i32ElementSize);

    if(ptStack->pvArray == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Stack_reallocateDynamic(Stack_t *ptStack, int32_t i32NewStackLen)
{
    void *pvData;

    pvData = (void *)realloc(ptStack->pvArray, i32NewStackLen * ptStack->i32ElementSize);

    if(pvData == NULL)
    {
        return false;
    }
    else
    {
        ptStack->pvArray = pvData;
        ptStack->i32StackLen = i32NewStackLen;
        return true;
    }
}

void Stack_deallocateDynamic(Stack_t *ptStack)
{
    free(ptStack->pvArray);
    ptStack->pvArray = NULL;
}

bool Stack_isEmpty(Stack_t *ptStack)
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

bool Stack_isFull(Stack_t *ptStack)
{
    if((ptStack->i32Top + 1) == ptStack->i32StackLen)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int32_t Stack_getActualLength(Stack_t *ptStack)
{
    return ptStack->i32Top + 1;
}

int32_t Stack_getStackLength(Stack_t *ptStack)
{
    return ptStack->i32StackLen;
}

bool Stack_getTop(Stack_t *ptStack, void *pvElement)
{
    void *pvStackElement;

    ptStack->bHeadingDown = true;
    ptStack->i32Next = ptStack->i32Top - 1;

    if(!Stack_isEmpty(ptStack))
    {
        {
            pvStackElement = ((uint8_t *)ptStack->pvArray) + (ptStack->i32Top * ptStack->i32ElementSize);
            memcpy(pvElement, pvStackElement, ptStack->i32ElementSize);
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack_getButtom(Stack_t *ptStack, void *pvElement)
{
    void *pvStackElement;

    ptStack->bHeadingDown = false;
    ptStack->i32Next = 0 + 1;

    if(!Stack_isEmpty(ptStack))
    {
        {
            pvStackElement = ((uint8_t *)ptStack->pvArray) + (0 * ptStack->i32ElementSize);
            memcpy(pvElement, pvStackElement, ptStack->i32ElementSize);
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack_getNext(Stack_t *ptStack, void *pvElement)
{
    void *pvStackElement;

    if((ptStack->i32Next >= 0) && (ptStack->i32Next <= ptStack->i32Top))
    {
        {
            pvStackElement = ((uint8_t *)ptStack->pvArray) + (ptStack->i32Next * ptStack->i32ElementSize);
            memcpy(pvElement, pvStackElement, ptStack->i32ElementSize);
        }

        if(ptStack->bHeadingDown == true)
        {
            ptStack->i32Next -= 1;
        }
        else
        {
            ptStack->i32Next += 1;
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack_pop(Stack_t *ptStack, void *pvElement)
{
    void *pvStackElement;

    if(!Stack_isEmpty(ptStack))
    {
        {
            pvStackElement = ((uint8_t *)ptStack->pvArray) + (ptStack->i32Top * ptStack->i32ElementSize);
            memcpy(pvElement, pvStackElement, ptStack->i32ElementSize);
        }
        ptStack->i32Top -= 1;
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack_push(Stack_t *ptStack, void *pvElement)
{
    void *pvStackElement;

    if(!Stack_isFull(ptStack))
    {
        ptStack->i32Top += 1;
        {
            pvStackElement = ((uint8_t *)ptStack->pvArray) + (ptStack->i32Top * ptStack->i32ElementSize);
            memcpy(pvStackElement, pvElement, ptStack->i32ElementSize);
        }
        return true;
    }
    else
    {
        return false;
    }
}
