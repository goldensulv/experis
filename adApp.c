/*
	Title:			adApp.c
	Description:	Meetings
	Author:			Shalev Goldfarb
	Last updated:	02.04.19
*/

#include <stdio.h>

#include "meeting.h"

int main(void)
{
	meeting_t *meeting = MeetingCreate(14.5, 16.5, "Doctor's appointment");
	
	MeetingDestroy(meeting);

	return OK;
}