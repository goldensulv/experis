/*
	Title:			queue.h
	Description:	Queue ADT - header
	Author:			Shalev Goldfarb
	Last updated:	10.04.19
*/
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdlib.h>
#include "ADTErr.h"

typedef struct queue queue_t;

/*
	Description: Creates a queue.
	Errors\Return: Returns NULL for allocation error, and if _size < 2.
*/
queue_t* QueueCreate(size_t _size);

/*
	Description: Frees memory previously allocated by QueueCreate().
*/
void QueueDestroy(queue_t* _queue);

/*
	Description: Inserts _item to the tail of _queue.
	Errors\Return: POINTER_ERROR, OVERFLOW_ERROR, OK.
*/
ADTErr QueueInsert(queue_t* _queue, int _item);

/*
	Description: Removes item from the head of _queue, and saves it to *_item.
	Errors\Return: POINTER_ERROR, UNDERFLOW_ERROR, OK.
*/
ADTErr QueueRemove(queue_t* _queue, int* _item);

/*
	Description: Checks if _queue has any elements in it.
	Errors\Return: POINTER_ERROR, TRUE, FALSE.
*/
int QueueIsEmpty(queue_t* _queue);

/*
	Description: Prints _queue.
*/
void QueuePrint(queue_t* _queue);

#endif /* __QUEUE_H__ */