/*
	Title:			ad.h
	Description:	Appointment diary
	Author:			Shalev Goldfarb
	Last updated:	02.04.19
*/
#ifndef __AD_H__
#define __AD_H__

#include <stdlib.h>

#define Uint unsigned int

typedef struct calendar calendar_t;

/*
	Description: Allocates memory for a diary with initial capacity of _size meetings.
	Input: Initial meeting capacity of the diary.
	Errors\Return: 	Returns NULL on allocation failure and produces an error to stderr.
					Returns a pointer to a diary with _size capacity.
*/
calendar_t *ADCreate(Uint _size);

/*
	Description: Frees the memory previously allocated by ADCreate(), using free().
*/
void ADDestroy(calendar_t *_diary);

#endif /* __AD_H__ */