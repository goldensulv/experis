/*
	Title:			ad.h
	Description:	Appointment diary
	Author:			Shalev Goldfarb
	Last updated:	02.04.19
*/
#ifndef __AD_H__
#define __AD_H__

#include <stdlib.h>
#include "meeting.h"

#define Uint unsigned int

typedef struct calendar
{
	Uint m_capacity;
	Uint m_numOfMeetings;
	meeting_t** m_entries;
} calendar_t;

enum status
{
	OK,
	PARAM_ERROR,
	ALLOC_ERROR,
	OVERLAP_ERROR
};

/*
	Description: Allocates memory for a diary with initial capacity of _size meetings.
	Input: Initial meeting capacity of the diary.
	Errors\Return: 	Returns NULL on allocation failure and produces an error to stderr.
					Returns a pointer to a diary with _size capacity.
*/
extern calendar_t* ADCreate(Uint _size);

/*
	Description: Frees the memory previously allocated by ADCreate().
*/
extern void ADDestroy(calendar_t* _diary);

/*
	Description: Locates a meeting in _diary which starts at time _startTime.
	Input: calendar_t and _startTime.
	Errors\Return: Returns NULL if _diary is NULL or _startTime invalid (_startTime > 24 || _startTime < 0).
*/
extern meeting_t* ADFind(calendar_t* _diary, float _startTime, Uint* _index);

/*
	Description: Inserts an appointment to the diary.
	Input: Pointer to calendar_t and pointer to meeting_t.
	Errors\Return: enum status return.
*/
extern enum status ADInsert(calendar_t* _diary, meeting_t* _meeting);

/*
	Description: Removes a meeting which starts at _start_time from _diary.
	Input: Pointer to calendar_t, and _start_time;
	Errors\Return: enum status return.
*/
extern enum status ADRemove(calendar_t* _diary, float _start_time);

/*
	Description: Prints the entire appointment diary.
	Input: Pointer to calendar_t.
*/
extern void ADPrint(calendar_t* _diary);

#endif /* __AD_H__ */
