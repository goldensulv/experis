/*
	Title:			vector.h
	Description:	Dynamic Vector ADT - header
	Author:			Shalev Goldfarb
	Last updated:	04.04.19
*/

#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef enum 
{
	OK,
	GENERAL_ERROR,
	INITIALIZATION_ERROR,
	ALLOCATION_ERROR,
	REALLOCATION_ERROR,
	UNDERFLOW_ERROR,
	OVERFLOW_ERROR,
	INDEX_ERROR
} ADTErr;

typedef struct vector
{
	size_t m_originalSize;
	size_t m_size;
	size_t m_nItems;
	size_t m_blockSize;
	int* m_items;
} vector_t;

extern vector_t* VectorCreate(size_t _initialSize, size_t _extentionBlockSize);

extern void VectorDestroy(vector_t* _vector);

extern ADTErr VectorAdd(vector_t *_vector, int _item);

extern ADTErr VectorDelete(vector_t *_vector, int* _item);

extern ADTErr VectorGet(vector_t* _vector, size_t _index, int* _item);

extern ADTErr VectorSet(vector_t* _vector, size_t _index, int _item);

extern ADTErr VectorItemsNum(vector_t* _vector, int* _numOfItems);

#endif /* __VECTOR_H__ */