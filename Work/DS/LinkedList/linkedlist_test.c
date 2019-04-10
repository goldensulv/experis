/*
	Title:			linkedlist_test.c
	Description:	Linked List ADT - test file
	Author:			Shalev Goldfarb
	Last updated:	10.04.19
*/
#include <stdio.h>
#include "linkedlist.h"

#define LOG_ERROR(s)    (strcpy(errors[index], s))

void ListInsertHeadTest(void);
void PersonNodeCreateTest(void);
void PrintErrors(char* _moduleName);

char errors[20][30] = {0};
unsigned short total = 0;
unsigned short passed = 0;
unsigned short index = 1;

int main(void)
{
    PersonNodeCreateTest();
    ListInsertHeadTest();
	PrintErrors("Linked list");

	return 0;
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

void ListInsertHeadTest(void)
{
    person_t* joe = NULL;
    person_t* jane = NULL;
    person_t* james = NULL;
    person_t* list = NULL;
    joe = PersonNodeCreate(1234, "Joe Miseras", 54);
    jane = PersonNodeCreate(1061, "Janee Miseras", 46);
    james = PersonNodeCreate(1179, "James Miseras", 25);

    list = joe;
    list = ListInsertByKey(list, 1061, jane);
    list = ListInsertByKey(list, 1179, james);
/*    list = ListRemoveHead(list, NULL);
  */  ListPrint(list);
    ListDestroy(list);

    return;
}

void PersonNodeCreateTest(void)
{
    person_t* joe = PersonNodeCreate(1234, "Joe Miseras", 54);
    ListPrint(joe);
    PersonNodeDestroy(joe);

	return;
}