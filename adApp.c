/*
	Title:			adApp.c
	Description:	Meetings
	Author:			Shalev Goldfarb
	Last updated:	02.04.19
*/

#include <stdio.h>

#include "ad.h"
#include "meeting.h"

#define MAX_SUBJECT_LEN 30

int main(void)
{
	int index, option = 0;
	char subject[MAX_SUBJECT_LEN];
	float start = 0, end = 0;
	Uint size = 0;

	meeting_t *meeting = NULL;
	meeting_t *appointment = NULL;
	meeting_t *rendevous = NULL;
	meeting_t *sit_down = NULL;
	calendar_t *calendar = ADCreate(4);;

	while (9 != option)
	{
		printf("Please choose an option:\n\t1) Add meeting to calendar\n\t2) ADCreate\n\t5) ADDestroy\n\t6) ADInsert\n\t7) ADFind\n\t8) ADPrint\n\t9) Exit\n");
		scanf("%d", &option);
		getchar();

		switch (option)
		{
			case (1):
			{
				printf("Enter meeting subject: ");
				gets(subject);
				printf("Begins at (h.n): ");
				scanf("%f", &start);
				printf("Ends at (h.n): ");
				scanf("%f", &end);
				ADInsert(calendar, MeetingCreate(start, end, subject));
				break;
			}
			case (2):
			{

				break;
			}
			case (3):
			{
				printf("Enter start time of meeting to remove: ");
				/* problem: what happens when you destroy a meeting without removing it? no good */
				scanf("%f", &start);
				ADRemove(calendar, start);
				break;
			}
			case (4):
			{
				break;
			}
			case (5):
			{
				break;
			}
			case (6):
			{
				break;
			}
			case (7):
			{
				break;
			}
			case (8):
			{
				break;
			}
			case (9):
			{
				break;
			}
		}
	}

	appointment = MeetingCreate(9, 10, "Pencil sharpening");
	rendevous = MeetingCreate(13.5, 15, "Flower knitting");
	sit_down = MeetingCreate(10, 11, "The mousse discussion");
	MeetingPrint(meeting);
	MeetingPrint(appointment);
	MeetingPrint(rendevous);
	MeetingPrint(sit_down);
	puts("");
	ADInsert(calendar, rendevous);
	ADInsert(calendar, sit_down);
	ADInsert(calendar, appointment);
/*	ADRemove(calendar, 14.5);
*/	ADPrint(calendar);
	MeetingDestroy(meeting);
	MeetingDestroy(appointment);
	MeetingDestroy(rendevous);
	MeetingDestroy(sit_down);
	ADDestroy(calendar);

	return OK;

	/* TO DO:
			main loop
			ADDestroy() to destroy meetings (?)
			documentation
			input checks on all functions
			test on different inputs
			shrink array as well
	*/
}