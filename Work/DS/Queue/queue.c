/*
	Title:			queue.c
	Description:	Queue ADT
	Author:			Shalev Goldfarb
	Last updated:	10.04.19
*/
#include <stdio.h>
#include "queue.h"

#define MAGIC_NUMBER 0xbeefbeef

struct queue
{
	int* m_items;
	size_t m_size;
	size_t m_nItems;
	size_t m_head;
	size_t m_tail;
	size_t m_magicNumber;
};

queue_t* QueueCreate(const size_t _size)
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

	queue->m_magicNumber = MAGIC_NUMBER;
	queue->m_size = _size;
	queue->m_nItems = 0;
	queue->m_head = 0;
	queue->m_tail = 0;

	return queue;
}

void QueueDestroy(queue_t* _queue)
{
	if ((NULL == _queue) || (_queue->m_magicNumber != MAGIC_NUMBER))
	{
		return;
	}
	_queue->m_magicNumber = 0xdeadbeef;
	free(_queue->m_items);
	free(_queue);

	return;
}

ADTErr QueueInsert(queue_t* _queue, const int _item)
{
	if ((NULL == _queue) || (_queue->m_magicNumber != MAGIC_NUMBER))
	{
		return POINTER_ERROR;
	}

	if (_queue->m_nItems == _queue->m_size)
	{
		return OVERFLOW_ERROR;
	}

	_queue->m_items[_queue->m_tail] = _item;
	_queue->m_nItems++;
	if (_queue->m_tail == (_queue->m_size - 1))
	{
		_queue->m_tail = 0;
	}
	else
	{
		_queue->m_tail++;
	}

	return OK;
}

ADTErr QueueRemove(queue_t* _queue, int* _item)
{
	if ((NULL == _queue) || (NULL == _item) || (_queue->m_magicNumber != MAGIC_NUMBER))
	{
		return POINTER_ERROR;
	}

	if (0 == _queue->m_nItems)
	{
		return UNDERFLOW_ERROR;
	}

	*_item = _queue->m_items[_queue->m_head];
	_queue->m_nItems--;
	if (_queue->m_head == (_queue->m_size - 1))
	{
		_queue->m_head = 0;
	}
	else
	{
		_queue->m_head++;
	}

	return OK;
}

int QueueIsEmpty(const queue_t* _queue)
{
	if ((NULL == _queue) || (_queue->m_magicNumber != MAGIC_NUMBER))
	{
		return 0;
	}
	return (0 == _queue->m_nItems);
}

void QueuePrint(const queue_t* _queue)
{
	int i = 0;
	int head;

	if (NULL == _queue)
	{
		return;
	}
	head = _queue->m_head;
	while ((i < _queue->m_nItems) && (head != _queue->m_tail))
	{
		printf("Item #%d - %d\n", i+1, _queue->m_items[head]);
		if (_queue->m_head == (_queue->m_size - 1))
		{
			head = 0;
		}
		else
		{
			head++;
		}
		i++;
	}

	return;
}