/*
	Title:			vector_test.c
	Description:	Dynamic Vector ADT - test file
	Author:			Shalev Goldfarb
	Last updated:	06.04.19
*/

#include <stdio.h>
#include <string.h>
#include "vector.h"

#define LOG_ERROR(s)    (strcpy(errors[index], s))

#define ITEM_DEFAULT 5

void TestVectorCreate(void);
void TestVectorAdd(void);
void TestVectorDelete(void);
void TestVectorGet(void);
void TestVectorSet(void);
void TestVectorItemsNum(void);
void PrintErrors(char* _moduleName);

char errors[20][30] = {0};
unsigned short total = 0;
unsigned short passed = 0;
unsigned short index = 1;

int main(void)
{
	TestVectorCreate();
	TestVectorAdd();
	TestVectorDelete();
	TestVectorGet();
	TestVectorSet();
	TestVectorItemsNum();
	PrintErrors("Vector");

	return 0;
}

void TestVectorCreate(void)
{
	vector_t* vector = VectorCreate(4, 4);
	total++;
	if (NULL == vector)
	{
		LOG_ERROR("TestVectorCreate - 1");
	}
	else
	{
		passed++;
	}
	VectorDestroy(vector);
	vector = NULL;
	index++;

	total++;
	vector = VectorCreate(99999999999, 3);
	if (NULL != vector)
	{
		LOG_ERROR("TestVectorCreate - 2");
	}
	else
	{
		passed++;
	}
	VectorDestroy(vector);	
	index++;
}

void TestVectorAdd(void)
{
	int status = 0;
	vector_t* vector = VectorCreate(4, 4);
	status = VectorAdd(vector, ITEM_DEFAULT);
	total++;
	if (OK != status)
	{
		LOG_ERROR("TestVectorAdd - 1");
	}
	else
	{
		passed++;
	}
	VectorDestroy(vector);
	vector = NULL;
	index++;

	vector = VectorCreate(1, 0);
	VectorAdd(vector, ITEM_DEFAULT);
	status = VectorAdd(vector, ITEM_DEFAULT);
	total++;
	if (OVERFLOW_ERROR != status)
	{
		LOG_ERROR("TestVectorAdd - 2");
	}
	else
	{
		passed++;
	}
	VectorDestroy(vector);
	vector = NULL;
	index++;

	total++;
	status = 0;
	vector = VectorCreate(0, 999999999999);
	status = VectorAdd(vector, ITEM_DEFAULT);
	if (REALLOCATION_ERROR != status)
	{
		LOG_ERROR("TestVectorAdd - 3");
	}
	else
	{
		passed++;
	}
	VectorDestroy(vector);	
	vector = NULL;
	index++;

	total++;
	status = VectorAdd(vector, ITEM_DEFAULT);
	if (POINTER_ERROR != status)
	{
		LOG_ERROR("TestVectorAdd - 4");
	}
	else
	{
		passed++;
	}
	index++;
}

void TestVectorDelete(void)
{
	int status = 0;
	int item = 0;
	vector_t* vector = VectorCreate(4, 4);
	VectorAdd(vector, ITEM_DEFAULT);
	status = VectorDelete(vector, &item);
	total++;
	if ((OK != status) || (ITEM_DEFAULT != item))
	{
		LOG_ERROR("TestVectorDelete - 1");
	}
	else
	{
		passed++;
	}
	VectorDestroy(vector);
	vector = NULL;
	index++;

	total++;
	status = VectorDelete(vector, &item);
	if (POINTER_ERROR != status)
	{
		LOG_ERROR("TestVectorDelete - 2");
	}
	else
	{
		passed++;
	}
	index++;

	total++;
	vector = VectorCreate(4, 4);
	status = VectorDelete(vector, &item);
	if (UNDERFLOW_ERROR != status)
	{
		LOG_ERROR("TestVectorDelete - 3");
	}
	else
	{
		passed++;
	}
	index++;
}

void TestVectorGet(void)
{
	int status = 0;
	int item = 0;
	vector_t* vector = VectorCreate(4, 4);
	VectorAdd(vector, ITEM_DEFAULT);
	status = VectorGet(vector, 1, &item);
	total++;
	if ((OK != status) || (ITEM_DEFAULT != item))
	{
		LOG_ERROR("TestVectorGet - 1");
	}
	else
	{
		passed++;
	}
	VectorDestroy(vector);
	vector = NULL;
	index++;

	total++;
	status = 0;
	item = 0;
	vector = VectorCreate(4, 4);
	status = VectorGet(vector, 1, &item);
	if ((INDEX_ERROR != status) || (0 != item))
	{
		LOG_ERROR("TestVectorGet - 2");
	}
	else
	{
		passed++;
	}
	VectorDestroy(vector);
	vector = NULL;
	index++;	

	total++;
	status = 0;
	item = 0;
	status = VectorGet(vector, 1, NULL);
	if (POINTER_ERROR != status)
	{
		LOG_ERROR("TestVectorGet - 3");
	}
	else
	{
		passed++;
	}
	VectorDestroy(vector);
	vector = NULL;
	index++;	
}

void TestVectorSet(void)
{
	int status = 0;
	int item = 10;
	vector_t* vector = VectorCreate(4, 4);
	VectorAdd(vector, ITEM_DEFAULT);
	status = VectorSet(vector, 1, item);
	VectorGet(vector, 1, &item);
	total++;
	if ((OK != status) || (10 != item))
	{
		LOG_ERROR("TestVectorSet - 1");
	}
	else
	{
		passed++;
	}
	VectorDestroy(vector);
	vector = NULL;
	index++;

	total++;
	status = 0;
	item = 0;
	vector = VectorCreate(4, 4);
	VectorAdd(vector, ITEM_DEFAULT);
	status = VectorSet(vector, 2, item);
	if (INDEX_ERROR != status)
	{
		LOG_ERROR("TestVectorSet - 2");
	}
	else
	{
		passed++;
	}
	VectorDestroy(vector);
	vector = NULL;
	index++;	

	total++;
	status = 0;
	item = 0;
	status = VectorSet(vector, 1, ITEM_DEFAULT);
	if (POINTER_ERROR != status)
	{
		LOG_ERROR("TestVectorSet - 3");
	}
	else
	{
		passed++;
	}
	VectorDestroy(vector);
	vector = NULL;
	index++;
}

void TestVectorItemsNum(void)
{
	int status = 0;
	int numOfItems = 0;
	vector_t* vector = VectorCreate(4, 4);
	VectorAdd(vector, ITEM_DEFAULT);
	VectorAdd(vector, ITEM_DEFAULT);
	VectorAdd(vector, ITEM_DEFAULT);
	status = VectorItemsNum(vector, &numOfItems);
	total++;
	if ((OK != status) || (3 != numOfItems))
	{
		LOG_ERROR("TestVectorItemsNum - 1");
	}
	else
	{
		passed++;
	}
	VectorDestroy(vector);
	vector = NULL;
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