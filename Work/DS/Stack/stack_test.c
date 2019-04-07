/*
	Title:			stack_test.c
	Description:	Stack ADT - test
	Author:			Shalev Goldfarb
	Last updated:	07.04.19
*/
#include <stdio.h>
#include <string.h>
#include "stack.h"

#define LOG_ERROR(s)    (strcpy(errors[index], s))
#define ITEM_DEFAULT 5

void StackPrint(stack_t* _stack);
void TestStackCreate(void);
void TestStackPush(void);
void TestStackPop(void);
void TestStackTop(void);
void TestStackIsEmpty(void);
void PrintErrors(char* _moduleName);

char errors[20][30] = {0};
unsigned short total = 0;
unsigned short passed = 0;
unsigned short index = 1;

int main(void)
{
	TestStackCreate();
	TestStackPush();
	TestStackPop();
	TestStackTop();
	TestStackIsEmpty();

	PrintErrors("Stack");

	return 0;
}

void TestStackCreate(void)
{
	stack_t* stack = StackCreate(4, 4);
	total++;
	if (NULL == stack)
	{
		LOG_ERROR("TestStackCreate - 1");
	}
	else
	{
		passed++;
	}
	StackDestroy(stack);
	index++;

	total++;
	stack = StackCreate(9999999999999, 9);
	if (NULL != stack)
	{
		LOG_ERROR("TestStackCreate - 2");
	}
	else
	{
		passed++;
	}
	StackDestroy(stack);
	index++;
}

void TestStackPush(void)
{
	int status = 0;
	stack_t* stack = StackCreate(4, 4);
	status = StackPush(stack, ITEM_DEFAULT);
	total++;
	if (OK != status)
	{
		LOG_ERROR("TestStackPush - 1");
	}
	else
	{
		passed++;
	}
	StackDestroy(stack);
	index++;

	status = 0;
	stack = StackCreate(1, 0);
	StackPush(stack, ITEM_DEFAULT);
	status = StackPush(stack, 10);
	total++;
	if (OVERFLOW_ERROR != status)
	{
		LOG_ERROR("TestStackPush - 2");
	}
	else
	{
		passed++;
	}
	StackDestroy(stack);
	index++;
}

void TestStackPop(void)
{
	int status = 0;
	int item = 0;
	stack_t* stack = StackCreate(4, 4);
	StackPush(stack, ITEM_DEFAULT);
	status = StackPop(stack, &item);
	total++;
	if ((OK != status) || (ITEM_DEFAULT != item))
	{
		LOG_ERROR("TestStackPop - 1");
	}
	else
	{
		passed++;
	}
	StackDestroy(stack);
	index++;
}

void TestStackTop(void)
{
	int status = 0;
	int item = 0;
	stack_t* stack = StackCreate(4, 4);
	StackPush(stack, ITEM_DEFAULT);
	status = StackTop(stack, &item);
	total++;
	if ((OK != status) || (ITEM_DEFAULT != item))
	{
		LOG_ERROR("TestStackTop - 1");
	}
	else
	{
		passed++;
	}
	StackDestroy(stack);
	index++;
}

void TestStackIsEmpty(void)
{
	int status = 0;
	stack_t* stack = StackCreate(4, 4);
	status = StackIsEmpty(stack);
	total++;
	if (FALSE == status)
	{
		LOG_ERROR("TestStackIsEmpty - 1");
	}
	else
	{
		passed++;
	}
	StackDestroy(stack);
	index++;

	status = 0;
	total++;
	stack = StackCreate(4, 4);
	StackPush(stack, ITEM_DEFAULT);
	status = StackIsEmpty(stack);
	if (TRUE == status)
	{
		LOG_ERROR("TestStackIsEmpty - 2");
	}
	else
	{
		passed++;
	}
	StackDestroy(stack);
	index++;
}

void StackPrint(stack_t* _stack)
{
	VectorPrint(_stack->m_vector);
}

/* Error handling */
void PrintErrors(char *test)
{
    short i = 1;
    printf("%s Unit Test\n", test);   
    printf("Passed %d out of %d tests.\n============================\n", passed, total);

    while (i < index)
    {
        if ('\0' != *errors[i])
        {
            printf("#%d:%s.\n", i, errors[i]);  
        }
        ++i;
    }
}