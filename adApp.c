/*
	Title:			adApp.c
	Description:	Meetings
	Author:			Shalev Goldfarb
	Last updated:	02.04.19
*/

#include <stdio.h>

#include "ad.h"
#include "meeting.h"

int main(void)
{
	meeting_t *meeting = NULL;
	meeting_t *appointment = NULL;
	meeting_t *rendevous = NULL;
	meeting_t *sit_down = NULL;
	calendar_t *calendar = NULL;
	meeting = MeetingCreate(14.5, 16.5, "Doctor's appointment");
	appointment = MeetingCreate(9, 10, "Pencil sharpening");
	rendevous = MeetingCreate(13.5, 15, "Flower knitting");
	sit_down = MeetingCreate(10, 11, "The mousse discussion");
	MeetingPrint(meeting);
	MeetingPrint(appointment);
	MeetingPrint(rendevous);
	MeetingPrint(sit_down);
	calendar = ADCreate(4);
	ADInsert(calendar, meeting);
	ADInsert(calendar, appointment);
	ADInsert(calendar, rendevous);
	ADInsert(calendar, sit_down);
	ADRemove(calendar, 14.5);
	ADPrint(calendar);
	MeetingDestroy(meeting);
	MeetingDestroy(appointment);
	MeetingDestroy(rendevous);
	MeetingDestroy(sit_down);
	ADDestroy(calendar);

	return OK;
}