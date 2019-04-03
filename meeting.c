/*
	Title:			meeting.c
	Description:	Meetings
	Author:			Shalev Goldfarb
	Last updated:	03.04.19
*/

#include "meeting.h"

meeting_t *MeetingCreate(float _start, float _end, const char _subject[])
{
	meeting_t* meeting = NULL;

	if ((_start >= _end) || (_start < TIME_MIN) || (_start > TIME_MAX) 
		|| (_end < TIME_MIN) || (_end > TIME_MAX))
	{
		return NULL;
	}

	meeting = (meeting_t*)malloc(sizeof(meeting_t));
	if (NULL == meeting)
	{
		return meeting;
	}

	meeting->m_start = _start;
	meeting->m_end = _end;
	strcpy(meeting->m_subject, _subject);

	return meeting;
}

void MeetingDestroy(meeting_t *_meeting)
{
	free(_meeting);
}

void MeetingPrint(meeting_t *_meeting)
{
	if (NULL == _meeting)
	{
		return;
	}

	printf("%s - will start at %2.1f and end at %2.1f.\n", 
				_meeting->m_subject, _meeting->m_start, _meeting->m_end);
}
