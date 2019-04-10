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
void PrintErrors(char* _moduleName);

char errors[20][30] = {0};
unsigned short total = 0;
unsigned short passed = 0;
unsigned short index = 1;

int main(void)
{
	TestQueueCreate();
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