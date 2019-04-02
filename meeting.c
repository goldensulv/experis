/*
	Title:			meeting.c
	Description:	Meetings
	Author:			Shalev Goldfarb
	Last updated:	02.04.19
*/

#include "meeting.h"

typedef struct meeting
{
	float start;
	float end;
	char subject[20];
} meeting_t;

meeting_t *MeetingCreate(float _start, float _end, const char _subject[])
{
	meeting_t *meeting = NULL;

	if (_start >= _end)
	{
		fprintf(stderr, "Wrong time!");
	}

	meeting = malloc(sizeof(meeting_t));

	meeting->start = _start;
	meeting->end = _end;
	strcpy(meeting->subject, _subject);

	return meeting;
}

void MeetingDestroy(meeting_t *_meeting)
{
	free(_meeting);
	_meeting = NULL;
}

void MeetingPrint(meeting_t *_meeting)
{
	printf("%s - will start at %2.1f and end at %2.1f.\n", 
				_meeting->subject, _meeting->start, _meeting->end);
}