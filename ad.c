/*
	Title:			ad.c
	Description:	Appointments diary
	Author:			Shalev Goldfarb
	Last updated:	02.04.19
*/

#include "ad.h"
#include "meeting.h"

calendar_t* ADCreate(Uint _size)
{
	calendar_t* diary = (calendar_t*)malloc(sizeof(calendar_t));
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

void ADDestroy(calendar_t* _diary)
{
	free(_diary->m_entries);
	free(_diary);
}

meeting_t* ADFind(calendar_t* _diary, float _start_time, Uint* _index)
{
	Uint index;
	Uint last_index;

	if (NULL == _diary)
	{
		return NULL;
	}

	if ((_start_time > TIME_MAX) || (_start_time < TIME_MIN))
	{
		return NULL;
	}

	index = 0;
	last_index = _diary->m_numOfMeetings;

	while (index < last_index)
	{
		if ((*(_diary->m_entries + index))->m_start == _start_time)
		{	
			*_index = index;
			return (*(_diary->m_entries + index));
		}
		++index;
	}

	return NULL;
}

static enum status ADRealloc(calendar_t* _diary)
{
	void* temp = NULL;

	temp = realloc(_diary->m_entries, _diary->m_capacity * 2);
	if (NULL == temp)
	{
		return ALLOC_ERROR;
	}

	_diary->m_entries = temp;
	_diary->m_capacity = _diary->m_capacity * 2;

	return OK;
}

static enum status ADPushLeft(calendar_t* _diary, int _index)
{
	while (_index < ((_diary->m_numOfMeetings) - 1))
	{
		_diary->m_entries[_index] = _diary->m_entries[_index + 1];
		_index++;
	}

	return OK;
}

/*
	Description: Pushes the meetings in the diary from position index up by one position.
*/
static enum status ADPushRight(calendar_t* _diary, int _index)
{
	int now_moving = (_diary->m_numOfMeetings) - 1;
	while (now_moving >= _index)
	{
		_diary->m_entries[now_moving + 1] = _diary->m_entries[now_moving];
		now_moving--;
	}

	return OK;
}

enum status ADInsert(calendar_t* _diary, meeting_t* _meeting)
{
	Uint index = 0;

	if ((NULL == _diary) || (NULL == _meeting))
	{
		return PARAM_ERROR;
	}

	if (_diary->m_capacity <= (_diary->m_numOfMeetings))
	{
		ADRealloc(_diary);
	}

	if (0 == _diary->m_numOfMeetings)
	{
		_diary->m_entries[0] = _meeting;
		(_diary->m_numOfMeetings)++;
	}
	else
	{
		while (index < (_diary->m_numOfMeetings))
		{
			if (_meeting->m_start < (_diary->m_entries[index]->m_start))
			{
				if (_meeting->m_end <= (_diary->m_entries[index]->m_start))
				{
					ADPushRight(_diary, index);
					_diary->m_entries[index] = _meeting;
					(_diary->m_numOfMeetings)++;
					break;
				}
				else
				{
					return OVERLAP_ERROR;
				}
			}
			else
			{
				if (_meeting->m_start < (_diary->m_entries[index]->m_end))
				{
					return OVERLAP_ERROR;
				}
			}
			index++;	
		}
	}

	if (index == (_diary->m_numOfMeetings))
	{
		_diary->m_entries[index] = _meeting;
		(_diary->m_numOfMeetings)++;		
	}

	return OK;
}

/*
void ADSwapMeetings(meeting_t *_meeting1, meeting_t *_meeting2)
{
	meeting_t temp = *_meeting1;
	*_meeting1 = *_meeting2;
	*_meeting2 = temp;
}
*/

enum status ADRemove(calendar_t *_diary, float _start_time)
{
	Uint index = 0;

	meeting_t *meeting = ADFind(_diary, _start_time, &index);
	if (NULL != meeting)
	{
		meeting->m_start = 0;
		meeting->m_end = 0;
		meeting->m_subject[0] = '\0';
		MeetingDestroy(meeting);
	}

	ADPushLeft(_diary, index);
	(_diary->m_numOfMeetings)--;

	return OK;
}

void ADPrint(calendar_t *_diary)
{
	Uint appointments = 0;
	if (NULL == _diary)
	{
		return;
	}

	while (appointments < (_diary->m_numOfMeetings))
	{
		MeetingPrint(*(_diary->m_entries + appointments));
		appointments++;
	}
}

