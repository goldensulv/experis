/*
	Title:			vector_test.c
	Description:	Dynamic Vector ADT - black-box testing
	Author:			Shalev Goldfarb
	Last updated:	04.04.19
*/

#include <stdio.h>
#include "vector.h"

void VectorPrint(vector_t* _vector);

int main(void)
{
	vector_t* vector = VectorCreate(4, 4);
	VectorAdd(vector, 16);
	VectorAdd(vector, 53);
	VectorPrint(vector);
	VectorDestroy(vector);

	return 0;
}

void VectorPrint(vector_t* _vector)
{
	int index = 0;
	while (index < _vector->m_nItems)
	{
		printf("At index %d, there lies the number %d\n", index, _vector->m_items[index]);
		index++;
	}
}