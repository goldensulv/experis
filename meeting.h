/*
	Title:			meeting.h
	Description:	Meetings
	Author:			Shalev Goldfarb
	Last updated:	02.04.19
*/

#ifndef __MEETING_H__
#define __MEETING_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct meeting
{
	float m_start;
	float m_end;
	char m_subject[20];
} meeting_t;

/*
	Description: Allocates memory and creates a variable of type meeting_t with the given paramaters.
	Input:	Two floating point numbers for the _start and _end times of the meeting,
			and a char* with the meeting's _subject.
	Output:	Dynamically allocated meeting_t with the given paramaters.
	Errors\Return:	If _start >= _end returns NULL. Returns NULL on allocation error.
			 On success returns a pointer to meeting_t.
*/
extern meeting_t *MeetingCreate(float _start, float _end, const char _subject[]);

/*
	Description: Frees the memory previously allocated by MeetingCreate().
*/
extern void MeetingDestroy(meeting_t *_meeting);

/*
	Description: S
*/
extern void MeetingPrint(meeting_t *_meeting);

/*
	Description: S
	Input:
	Output:
	Errors\Return:

int MeetingSet(meeting_t *meeting, float _start, float _end, char _subject[]);
*/

/*
	Description: Gets the paramaters from meeting into the given pointers.
	Input:	A meeting_t, pointers for the start (_start) and finish (_ends) times, and 
			a char * with the meeting's _subject.
	Output:	Should extract the data from meeting
	Errors\Return:

int MeetingGet(meeting_t *meeting, float *_start, float *_end, char _subject[]);
*/
#endif /* __MEETING_H__ */
