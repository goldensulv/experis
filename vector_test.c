/*
	Title:			vector_test.c
	Description:	Dynamic Vector ADT - test file
	Author:			Shalev Goldfarb
	Last updated:	04.04.19
*/

#include <stdio.h>
#include "vector.h"

void VectorPrint(vector_t* _vector);

int main(void)
{
	int item;
	vector_t* vector = VectorCreate(4, 4);
	VectorAdd(vector, 16);
	VectorAdd(vector, 53);
	VectorDelete(vector, &item);
	VectorAdd(vector, 4);
	VectorAdd(vector, 81);
	VectorAdd(vector, 934);
	VectorAdd(vector, 9);
	VectorAdd(vector, 33);
	VectorPrint(vector);
	VectorDestroy(vector);

	return 0;
}

void VectorPrint(vector_t* _vector)
{
	int index = 0;
	while (index < _vector->m_nItems)
	{
		printf("At index %d, there lies the number %d\n", index + 1, _vector->m_items[index]);
		index++;
	}
}