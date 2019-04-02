/*
	Title:			ad.c
	Description:	Appointments diary
	Author:			Shalev Goldfarb
	Last updated:	02.04.19
*/

#include "ad.h"
#include "meeting.h"

typedef struct calendar
{
	meeting_t *entry;
} calendar_t;

calendar_t *ADCreate(Uint _size)
{
	calendar_t *diary = calloc(_size, sizeof(calendar_t));

	if (NULL == diary)
	{
		fprintf(stderr, "calloc error\n");
	}

	return diary;
}

void ADDestroy(calendar_t *_diary)
{
	free(_diary);
	_diary = NULL;
}