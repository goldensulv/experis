/*
	Title:			vector.h
	Description:	Dynamic Vector ADT - header
	Author:			Shalev Goldfarb
	Last updated:	06.04.19
*/

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "ADTErr.h"

#define EOS '\0'

typedef struct vector
{
	size_t m_magicNumber;
	size_t m_originalSize;
	size_t m_size;
	size_t m_nItems;
	size_t m_blockSize;
	int* m_items;
} vector_t;

/*
	Description: Creates a vector with initial size of _initialSize, and blockSize of _extentionBlockSize.
	Errors\Return: NULL on failure, pointer to vector_t on success.
*/
extern vector_t* VectorCreate(size_t _initialSize, size_t _extentionBlockSize);

/*
	Description: Destroy and free memory previously allocated by VectorCreate().
*/
extern void VectorDestroy(vector_t* _vector);

/*
	Description: Adds an item to the top of vector _vector.
	Output: vector->m_nItems is incremented.
	Errors\Return: POINTER_ERROR, OVERFLOW_ERROR, REALLOCATION_ERROR, OK.
*/
extern ADTErr VectorAdd(vector_t* _vector, int _item);

/*
	Description: Removes an item from the top of vector _vector.
	Input: Pointer to vector_t, and a pointer to int to hold the deleted item's data.
	Output: vector->m_nItems is decremented, and the previously top item's
			data is placed in _item.
	Errors\Return: POINTER_ERROR, UNDERFLOW_ERROR, OK.
*/
extern ADTErr VectorDelete(vector_t* _vector, int* _item);

/*
	Description: Retrieves the data at _index in _vector into *_item.
	Input: A pointer to vector_t, an index (starting at 1), and a pointer to int.
	Errors\Return: POINTER_ERROR, INDEX_ERROR, OK.
*/
extern ADTErr VectorGet(const vector_t* _vector, size_t _index, int* _item);

/*
	Description: Sets the data at _index in _vector from _item.
	Input: A pointer to vector_t, an index (starting at 1), and an integer.
	Errors\Return: POINTER_ERROR, INDEX_ERROR, OK.
*/
extern ADTErr VectorSet(vector_t* _vector, size_t _index, int _item);

/*
	Description: Gets the number of items in the vector _vector.
	Input: Pointer to vector_t, and a pointer to int to hold vector->m_nItems.
	Output: _vector->m_nItems is copied to _numOfItems.
	Errors\Return: POINTER_ERROR, INDEX_ERROR, OK.
*/
extern ADTErr VectorItemsNum(const vector_t* _vector, int* _numOfItems);

extern void VectorPrint(const vector_t* _vector);

#endif /* __VECTOR_H__ */