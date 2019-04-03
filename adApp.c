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
	int option = 0;
	meeting_t *meeting = NULL;
	meeting_t *appointment = NULL;
	meeting_t *rendevous = NULL;
	meeting_t *sit_down = NULL;
	calendar_t *calendar = NULL;
	printf("Please choose an option:\n\t1) MeetingCreate\n\t2) MeetingDestroy\n\t3) MeetingPrint\n\t4) ADCreate\n\t5) ADDestroy\n\t6) ADInsert\n\t7) ADFind\n\t8) ADPrint\n\t9) Exit");
	while (1)
	{
		scanf("%d", &option);
		switch (option)
		{
			case (1):
			{
				continue;
			}
			case (2):
			{
				continue;
			}
			case (3):
			{
				continue;
			}
			case (4):
			{
				continue;
			}
			case (5):
			{
				continue;
			}
			case (6):
			{
				continue;
			}
			case (7):
			{
				continue;
			}
			case (8):
			{
				continue;
			}
			case (9):
			{
				break;
			}
		}
		break;
	}

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