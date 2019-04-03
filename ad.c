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
	Uint free_space;
	Uint num_of_meetings;
	meeting_t *entries;
} calendar_t;

calendar_t *ADCreate(Uint _size)
{
	calendar_t *diary = malloc(sizeof(calendar_t));
	diary->free_space = _size;
	diary->num_of_meetings = 0;
	diary->entries = calloc(_size, sizeof(diary->entries));

	if ((NULL == diary) || (NULL == diary->entries))
	{
		fprintf(stderr, "calloc error\n");
	}

	return diary;
}

void ADDestroy(calendar_t *_diary)
{
	free(_diary->entries);
	free(_diary);
	_diary = NULL;
}

int ADInsert(calendar_t *_diary, meeting_t *_meeting)
{
	void *temp = NULL;

	if ((NULL == _diary) || (NULL == _meeting))
	{
		return PARAM_ERROR;
	}

	if (0 == _diary->free_space)
	{
		temp = realloc(_diary->entries, _diary->num_of_meetings * 2);
		if (NULL == temp)
		{
			fprintf(stderr, "realloc failure\n");
			return ALLOC_ERROR;
		}
		else
		{
			_diary->entries = temp;
		}
	}

}