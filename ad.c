/*
	Title:			ad.c
	Description:	Appointments diary
	Author:			Shalev Goldfarb
	Last updated:	02.04.19
*/

#include "ad.h"
#include "meeting.h"

calendar_t *ADCreate(Uint _size)
{
	calendar_t *diary = (calendar_t*)malloc(sizeof(calendar_t));
	if (NULL == diary)
	{
		return diary;
	}	

	diary->m_entries = (meeting_t**)calloc(_size, sizeof(meeting_t*));
	if (NULL == diary->m_entries)
	{
		free(diary);
		return NULL;
	}

	diary->m_capacity = _size;
	diary->m_numOfMeetings = 0;

	return diary;
}

void ADDestroy(calendar_t *_diary)
{
	free(_diary->m_entries);
	free(_diary);
}

meeting_t* ADFind(calendar_t *_diary, float _start_time)
{
	Uint index;
	Uint last_index;

	if (NULL == _diary)
	{
		return NULL;
	}

	if ((_start_time > 24) || (_start_time < 0))
	{
		return NULL;
	}

	index = 0;
	last_index = _diary->m_numOfMeetings;

	while (index < last_index)
	{
		if ((*(_diary->m_entries + index))->m_start == _start_time)
		{	
			return *(_diary->m_entries + index);
		}
		++index;
	}

	return NULL;
}

enum status ADRealloc(calendar_t *_diary)
{
	void *temp = NULL;

	temp = realloc(_diary->m_entries, _diary->m_numOfMeetings * 2);
	if (NULL == temp)
	{
		return ALLOC_ERROR;
	}

	_diary->m_entries = temp;

	return OK;
}

enum status ADInsert(calendar_t *_diary, meeting_t* _meeting)
{
	void *temp = NULL;

	if ((NULL == _diary) || (NULL == _meeting))
	{
		return PARAM_ERROR;
	}

	if (_diary->m_capacity <= _diary->m_numOfMeetings)
	{
		ADRealloc(_diary);
	}

	*(_diary->m_entries + _diary->m_numOfMeetings) = _meeting;
	_diary->m_numOfMeetings++;

	return OK;
}

enum status ADRemove(calendar_t *_diary, float _start_time)
{
	meeting_t *meeting = ADFind(_diary, _start_time);
	if (NULL != meeting)
	{
		meeting->m_start = 0;
		meeting->m_end = 0;
		meeting->m_subject[0] = '\0';
	}

	(_diary->m_numOfMeetings)--;
}

void ADPrint(calendar_t *_diary)
{
	Uint appointments = 0;
	if (NULL == _diary)
	{
		return;
	}

	while (appointments < _diary->m_numOfMeetings)
	{
		MeetingPrint(*(_diary->m_entries + appointments));
		appointments++;
	}
}

void ADSwapMeetings(meeting_t *meeting1, meeting_t *meeting2)
{
	
}