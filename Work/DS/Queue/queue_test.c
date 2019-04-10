/*
	Title:			queue_test.c
	Description:	Queue ADT - test file
	Author:			Shalev Goldfarb
	Last updated:	10.04.19
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

#define LOG_ERROR(s)    (strcpy(errors[index], s))
#define ITEM_DEFAULT 5
#define SIZE_DEFAULT 4

void TestQueueCreate(void);
void TestQueueInsert(void);
void TestQueueRemove(void);
void TestQueueIsEmpty(void);
void TestQueuePrint(void);
void PrintErrors(char* _moduleName);

char errors[20][30] = {0};
unsigned short total = 0;
unsigned short passed = 0;
unsigned short index = 1;

int main(void)
{
	TestQueueCreate();
	TestQueueInsert();
	TestQueueRemove();
	TestQueueIsEmpty();
	TestQueuePrint();
	PrintErrors("Queue");

	return OK;
}

void TestQueueCreate(void)
{
	queue_t* queue = QueueCreate(SIZE_DEFAULT);
	total++;
	if (NULL == queue)
	{
		LOG_ERROR("TestQueueCreate - 1");
	}
	else
	{
		passed++;
	}
	QueueDestroy(queue);
	index++;

	total++;
	queue = QueueCreate(1);
	if (NULL != queue)
	{
		LOG_ERROR("TestQueueCreate - 2");
	}
	else
	{
		passed++;
	}
	index++;
}

void TestQueueInsert(void)
{
	int status = OK;
	queue_t* queue = QueueCreate(SIZE_DEFAULT);
	total++;
	status = QueueInsert(queue, ITEM_DEFAULT);
	if (OK != status)
	{
		LOG_ERROR("TestQueueInsert - 1");
	}
	else
	{
		passed++;
	}
	QueueDestroy(queue);
	index++;

	total++;
	queue = QueueCreate(2);
	QueueInsert(queue, ITEM_DEFAULT);
	QueueInsert(queue, ITEM_DEFAULT);
	status = QueueInsert(queue, ITEM_DEFAULT);
	if (OVERFLOW_ERROR != status)
	{
		LOG_ERROR("TestQueueInsert - 2");
	}
	else
	{
		passed++;
	}
	QueueDestroy(queue);
	index++;
}

void TestQueueRemove(void)
{
	int status = OK;
	int item = 0;
	queue_t* queue = QueueCreate(SIZE_DEFAULT);
	total++;
	QueueInsert(queue, ITEM_DEFAULT);
	status = QueueRemove(queue, &item);
	if ((OK != status) || (ITEM_DEFAULT != item))
	{
		LOG_ERROR("TestQueueRemove - 1");
	}
	else
	{
		passed++;
	}
	QueueDestroy(queue);
	index++;

	total++;
	queue = QueueCreate(SIZE_DEFAULT);
	status = QueueRemove(queue, &item);
	if (UNDERFLOW_ERROR != status)
	{
		LOG_ERROR("TestQueueRemove - 2");
	}
	else
	{
		passed++;
	}
	QueueDestroy(queue);
	index++;
}

void TestQueueIsEmpty(void)
{
	queue_t* queue = QueueCreate(SIZE_DEFAULT);
	total++;
	if (!QueueIsEmpty(queue))
	{
		LOG_ERROR("TestQueueIsEmpty - 1");
	}
	else
	{
		passed++;
	}
	QueueDestroy(queue);
	index++;

	total++;
	queue = QueueCreate(SIZE_DEFAULT);
	QueueInsert(queue, ITEM_DEFAULT);
	if (QueueIsEmpty(queue))
	{
		LOG_ERROR("TestQueueIsEmpty - 2");
	}
	else
	{
		passed++;
	}
	QueueDestroy(queue);
	index++;
}

void TestQueuePrint(void)
{
	queue_t* queue = QueueCreate(SIZE_DEFAULT);
	QueueInsert(queue, ITEM_DEFAULT);
	QueueInsert(queue, ITEM_DEFAULT);
	QueueInsert(queue, ITEM_DEFAULT);
	QueuePrint(queue);
	QueueDestroy(queue);
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