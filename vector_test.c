/*
	Title:			vector_test.c
	Description:	Dynamic Vector ADT - test file
	Author:			Shalev Goldfarb
	Last updated:	04.04.19
*/

#include <stdio.h>
#include <string.h>
#include "vector.h"

#define LOG_ERROR(s)    (strcpy(errors[index], s))

void VectorPrint(vector_t* _vector);
void PrintErrors(char* test);

char errors[10][30] = {0};
unsigned short total = 0;
unsigned short passed = 0;
unsigned short index = 1;

int main(void)
{
	int item, itemsNum;
	vector_t* vector = VectorCreate(4, 4);
	VectorAdd(vector, 16);
	VectorAdd(vector, 53);
	VectorDelete(vector, &item);
	printf("%d\n", item);
	VectorAdd(vector, 4);
	VectorAdd(vector, 81);
	VectorAdd(vector, 934);
	VectorAdd(vector, 9);
	VectorAdd(vector, 33);
	VectorPrint(vector);
	VectorItemsNum(vector, &itemsNum);
	printf("%d\n", itemsNum);
	VectorGet(vector, 3, &item);
	printf("%d\n", item);	
	item = 77;
	VectorSet(vector, 3, item);
	VectorPrint(vector);
	VectorDestroy(vector);

	return 0;
}

void VectorPrint(vector_t* _vector)
{
	int index = 0;
	while (index < (_vector->m_nItems))
	{
		printf("At index %d, there lies the number %d\n", index + 1, _vector->m_items[index]);
		index++;
	}
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