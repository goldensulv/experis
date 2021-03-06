/*
	Title:			stack.c
	Description:	Stack ADT
	Author:			Shalev Goldfarb
	Last updated:	07.04.19
*/
#include <stdlib.h> /* malloc */
#include "stack.h"
#include "vector.h"

struct stack
{
	vector_t* m_vector;
};

stack_t* StackCreate(size_t _size, size_t _blockSize)
{
	stack_t* stack = (stack_t*)malloc(sizeof(stack_t));
	if (NULL == stack)
	{
		return stack;
	}

	stack->m_vector = VectorCreate(_size, _blockSize);
	if (NULL == stack->m_vector)
	{
		free(stack);
		return NULL;
	}

	return stack;
}

void StackDestroy(stack_t* _stack)
{
	if ((NULL == _stack))
	{
		return;
	}
	VectorDestroy(_stack->m_vector);
	free(_stack);
}

ADTErr StackPush(stack_t* _stack, int _item)
{
	if (NULL == _stack)
	{
		return POINTER_ERROR;
	}
	return VectorAdd(_stack->m_vector, _item);
}

ADTErr StackPop(stack_t* _stack, int* _item)
{
	if (NULL == _stack)
	{
		return POINTER_ERROR;
	}
	return VectorDelete(_stack->m_vector, _item);
}

ADTErr StackTop(const stack_t* _stack, int* _item)
{
	int numOfItems = 0;

	if ((NULL == _stack) || (NULL == _item))
	{
		return POINTER_ERROR;
	}

	VectorItemsNum(_stack->m_vector, &numOfItems);
	return VectorGet(_stack->m_vector, numOfItems, _item);	
}

int StackIsEmpty(const stack_t* _stack)
{
	int numOfItems = -1;
	int status = FALSE;

	if (NULL == _stack)
	{
		return status;
	}

	VectorItemsNum(_stack->m_vector, &numOfItems);
	if (0 == numOfItems)
	{
		status = TRUE;
	}

	return status;
}

void StackPrint(const stack_t* _stack)
{
	VectorPrint(_stack->m_vector);
}