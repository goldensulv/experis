/*
	Title:			queue.c
	Description:	Queue ADT
	Author:			Shalev Goldfarb
	Last updated:	10.04.19
*/
#include "queue.h"

struct queue
{
	int* m_items;
	size_t m_size;
	size_t m_nItems;
	size_t m_head;
	size_t m_tail;
};

queue_t* QueueCreate(size_t _size)
{
	queue_t* queue = NULL;

	if (_size < 2)
	{
		return NULL;
	}

	queue = (queue_t*)malloc(sizeof(queue_t));
	if (NULL == queue)
	{
		return queue;
	}

	queue->m_items = (int*)calloc(_size, sizeof(int));
	if (NULL == queue->m_items)
	{
		free(queue);
		return NULL;
	}

	queue->m_size = _size;
	queue->m_nItems = 0;
	queue->m_head = 0;
	queue->m_tail = 0;

	return queue;
}

void QueueDestroy(queue_t* _queue)
{
	if (NULL == _queue)
	{
		return;
	}

	free(_queue->m_items);
	free(_queue);

	return;
}