/*
	Title:			stack.h
	Description:	Stack ADT - header
	Author:			Shalev Goldfarb
	Last updated:	07.04.19
*/

#ifndef __STACK_H__
#define __STACK_H__

#include "vector.h"
#include "ADTErr.h"

typedef struct stack
{
	vector_t* m_vector;
} stack_t;

stack_t* StackCreate(size_t _size, size_t _blockSize);

void StackDestroy(stack_t* _stack);

ADTErr StackPush(stack_t* _stack, int _item);

ADTErr StackPop(stack_t* _stack, int* _item);

ADTerr StackTop(stack_t* _stack, int* _item);

int StackIsEmpty(stack_t* _stack);

#endif /* __STACK_H__ */