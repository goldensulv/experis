/*
	Title:			vector.c
	Description:	Dynamic Vector ADT
	Author:			Shalev Goldfarb
	Last updated:	04.04.19
*/

#include <stdlib.h>
#include "vector.h"

vector_t* VectorCreate(size_t _initialSize, size_t _extentionBlockSize)
{
	vector_t* vector = (vector_t*)malloc(sizeof(vector_t));
	if (NULL == vector)
	{
		return vector;
	}

	vector->m_items = (int*)calloc(_initialSize, sizeof(int));
	if (NULL == vector->m_items)
	{
		free(vector);
		vector = NULL;
		return vector;
	}

	vector->m_originalSize = _initialSize;
	vector->m_size = _initialSize;
	vector->m_nItems = 0;
	vector->m_blockSize = _extentionBlockSize;

	return vector;
}

void VectorDestroy(vector_t* _vector)
{
	if (NULL == _vector)
	{
		return;
	}

	free(_vector->m_items);
	free(_vector);
}

static ADTErr VectorRealloc(vector_t* _vector)
{
	int* temp;

	if ((NULL == _vector) || (NULL == _vector->m_items))
	{
		return ALLOCATION_ERROR;
	}

	temp = (int*)realloc(_vector->m_items, _vector->m_size + _vector->m_blockSize);
	if (NULL == temp)
	{
		return REALLOCATION_ERROR;
	}

	_vector->m_items = temp;

	return OK;
}

ADTErr VectorAdd(vector_t* _vector, int _item)
{
	int status = OK;
	if (NULL == _vector)
	{
		return ALLOCATION_ERROR;
	}

	if (_vector->m_nItems == _vector->m_size)
	{
		status = VectorRealloc(_vector);
	}

	if (OK == status)
	{
		_vector->m_items[_vector->m_nItems] = _item;
		(_vector->m_nItems)++;		
	}
	else
	{
		return REALLOCATION_ERROR;
	}

	return status;

}

ADTErr VectorDelete(vector_t* _vector, int* _item)
{
	if (_vector->m_nItems > 0)
	{
		*_item = _vector->m_items[_vector->m_nItems];
		_vector->m_items[_vector->m_nItems] = 0;
		(_vector->m_nItems)--;
	}

	return OK;
}