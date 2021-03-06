/*
	Title:			vector.c
	Description:	Dynamic Vector ADT
	Author:			Shalev Goldfarb
	Last updated:	06.04.19
*/
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

#define MAGIC_NUMBER 0xbeefbeef

struct vector
{
	size_t m_magicNumber;
	size_t m_originalSize;
	size_t m_size;
	size_t m_nItems;
	size_t m_blockSize;
	int* m_items;
};

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

	vector->m_magicNumber = MAGIC_NUMBER;
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
	_vector->m_magicNumber = 0xdeadbeef;
	free(_vector->m_items);
	free(_vector);
}

static ADTErr VectorRealloc(vector_t* _vector, int _upOrDown)
{
	int* temp;

	if ((NULL == _vector) || (NULL == _vector->m_items))
	{
		return ALLOCATION_ERROR;
	}

	if (0 == _vector->m_blockSize)
	{
		return OVERFLOW_ERROR;
	}

	temp = (int*)realloc(_vector->m_items, _vector->m_size + (_vector->m_blockSize * _upOrDown));
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
	if ((NULL == _vector) || (MAGIC_NUMBER != _vector->m_magicNumber))
	{
		return POINTER_ERROR;
	}

	if (_vector->m_nItems == _vector->m_size)
	{
		status = VectorRealloc(_vector, +1);
	}

	if (OK == status)
	{
		_vector->m_items[_vector->m_nItems] = _item;
		(_vector->m_nItems)++;		
	}
	else
	{
		return status;
	}

	return status;

}

ADTErr VectorDelete(vector_t* _vector, int* _item)
{
	int status = OK;
	if ((NULL == _vector) || (MAGIC_NUMBER != _vector->m_magicNumber) || (NULL == _item))
	{
		status = POINTER_ERROR;
	}
	else if (0 == _vector->m_nItems)
	{
		status = UNDERFLOW_ERROR;
	}
	else if ((_vector->m_nItems <= (_vector->m_size / 4)) && 
			(((int)_vector->m_nItems - (int)_vector->m_blockSize) >= (int)_vector->m_originalSize))
	{
		status = VectorRealloc(_vector, -1);
	}
	if (OK == status)
	{
		*_item = _vector->m_items[_vector->m_nItems - 1];
		_vector->m_items[_vector->m_nItems - 1] = 0;
		(_vector->m_nItems)--;
	}

	return status;
}

ADTErr VectorItemsNum(const vector_t* _vector, int* _numOfItems)
{
	if ((NULL == _vector) || (MAGIC_NUMBER != _vector->m_magicNumber) || (NULL == _numOfItems))
	{
		return POINTER_ERROR;
	}

	*_numOfItems = _vector->m_nItems;

	return OK;	
}

ADTErr VectorGet(const vector_t* _vector, size_t _index, int* _item)
{
	if ((NULL == _vector) || (MAGIC_NUMBER != _vector->m_magicNumber) || (NULL == _item)) 
	{
		return POINTER_ERROR;
	}
	if (_index < 1)
	{
		return UNDERFLOW_ERROR;
	}
	if (_index > _vector->m_nItems)
	{
		return INDEX_ERROR;
	}
	*_item = _vector->m_items[_index - 1];

	return OK;
}

ADTErr VectorSet(vector_t* _vector, size_t _index, int _item)
{
	if ((NULL == _vector) || (MAGIC_NUMBER != _vector->m_magicNumber))
	{
		return POINTER_ERROR;
	}
	if ((_index < 1) || (_index > _vector->m_nItems))
	{
		return INDEX_ERROR;
	}

	_vector->m_items[_index - 1] = _item;

	return OK;
}

void VectorPrint(const vector_t* _vector)
{
	size_t index = 0;
	if (NULL == _vector)
	{
		return;
	}
	while (index < (_vector->m_nItems))
	{
		printf("At index %lu, there lies the number %d\n", index + 1, _vector->m_items[index]);
		index++;
	}
}