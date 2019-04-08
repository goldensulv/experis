/*
	Title:			stack.h
	Description:	Stack ADT - header
	Author:			Shalev Goldfarb
	Last updated:	07.04.19
*/

#ifndef __STACK_H__
#define __STACK_H__

#include "ADTErr.h"

#define FALSE 0
#define TRUE 1
#define ERROR -1
#define EOS '\0'

typedef struct stack stack_t;

/*
	Description: Creates a stack with an initial size of _size and blockSize of _blockSize.
	Errors\Return: NULL on failure, a pointer to stack_t on success.
*/
extern stack_t* StackCreate(size_t _size, size_t _blockSize);

/*
	Description: Frees the memory previously allocated by StackCreate().
*/
extern void StackDestroy(stack_t* _stack);

/*
	Description: Adds an element to the top of the stack.
	Errors\Return: POINTER_ERROR, OVERFLOW_ERROR, REALLOCATION_ERROR, OK.
*/
extern ADTErr StackPush(stack_t* _stack, int _item);

/*
	Description: Removes the top element from the stack, and copies it to *_item.
	Errors\Return: POINTER_ERROR, UNDERFLOW_ERROR, OK.
*/
extern ADTErr StackPop(stack_t* _stack, int* _item);

/*
	Description: Copies the item at the top of the stack to *_item.
	Errors\Return: POINTER_ERROR, OK.
*/
extern ADTErr StackTop(const stack_t* _stack, int* _item);

/*
	Description: Checks if the stack is empty.
	Errors\Return: TRUE if empty, FALSE if not-empty, and ERROR for error.
*/
extern int StackIsEmpty(const stack_t* _stack);

extern void StackPrint(const stack_t* _stack);

#endif /* __STACK_H__ */