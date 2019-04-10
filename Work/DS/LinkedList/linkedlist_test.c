/*
	Title:			linkedlist_test.c
	Description:	Linked List ADT - test file
	Author:			Shalev Goldfarb
	Last updated:	10.04.19
*/
#include <stdio.h>
#include "linkedlist.h"

#define LOG_ERROR(s)    (strcpy(errors[index], s))

void ListNodeCreate(void);
void PrintErrors(char* _moduleName);

char errors[20][30] = {0};
unsigned short total = 0;
unsigned short passed = 0;
unsigned short index = 1;

int main(void)
{
	PrintErrors("Linked list");

	return OK;
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

void ListNodeCreate(void)
{
	return;
}