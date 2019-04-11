/*
	Title:			linkedlist_test.c
	Description:	Linked List ADT - test file
	Author:			Shalev Goldfarb
	Last updated:	11.04.19
*/
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

#define LOG_ERROR(s)    (strcpy(errors[index], s))

void PersonNodeCreateTest(void);
void ListInsertHeadTest(void);
void ListRemoveHeadTest(void);
void ListInsertByKeyTest(void);
void ListRemoveByKeyTest(void);
void PrintErrors(char* _moduleName);

char errors[20][30] = {0};
unsigned short total = 0;
unsigned short passed = 0;
unsigned short index = 1;

int main(void)
{
    PersonNodeCreateTest();
    ListInsertHeadTest();
    ListRemoveHeadTest();
    ListInsertByKeyTest();
	PrintErrors("Linked list");

	return 0;
}

void ListInsertHeadTest(void)
{
    person_t* joe = NULL;
    person_t* jane = NULL;
    person_t* james = NULL;
    person_t* list = NULL;
    joe = PersonNodeCreate(1234, "Joe Miseras", 54);
    jane = PersonNodeCreate(1061, "Jane Miseras", 46);
    james = PersonNodeCreate(1179, "James Miseras", 25);
    total++;

    list = ListInsertHead(list, joe);
    if (list != joe)
    {
    	LOG_ERROR("ListInsertHeadTest - 1");
    }
    else
    {
    	passed++;
    }
    index++;

    total++;
    list = ListInsertHead(list, jane);
    if (list != jane)
    {
    	LOG_ERROR("ListInsertHeadTest - 2");
    }
    else
    {
    	passed++;
    }
    index++;
    list = ListInsertHead(list, james);
    ListPrint(list);
    puts("");
    list = ListRemoveHead(list, NULL);
    list = ListRemoveHead(list, NULL);
    ListPrint(list);
    puts("");
    list = ListInsertByKey(list, 1061, jane);
    list = ListInsertByKey(list, 1179, james);
    list = ListRemoveByKey(list, 1234, NULL);
    ListPrint(list);
    ListDestroy(list);

    return;
}

void ListRemoveHeadTest(void)
{
	person_t* list = NULL;
	person_t* removed = NULL;
	person_t* joe = PersonNodeCreate(1234, "Joe Miseras", 54);
	total++;

	list = ListInsertHead(list, joe);
	list = ListRemoveHead(list, &removed);
	if (NULL != list)
	{
		LOG_ERROR("ListRemoveHeadTest - 1");
	}
	else
	{
		passed++;
	}
	index++;

	total++;
	if (removed != joe)
	{
		LOG_ERROR("ListRemoveHeadTest - 2");
	}
	else
	{
		passed++;
	}
	index++;
	PersonNodeDestroy(joe);

	return;
}

void ListInsertByKeyTest(void)
{

	return;
}

void PersonNodeCreateTest(void)
{
    person_t* joe = PersonNodeCreate(1234, "Joe Miseras", 54);
    ListPrint(joe);
    PersonNodeDestroy(joe);

	return;
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

    return;
}
