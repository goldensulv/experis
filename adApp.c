/*
	Title:			adApp.c
	Description:	Meetings
	Author:			Shalev Goldfarb
	Last updated:	03.04.19
*/

#include <stdio.h>

#include "ad.h"
#include "meeting.h"

#define MAX_SUBJECT_LEN 30

enum options
{
	ADD = 1,
	REMOVE,
	FIND,
	PRINT,
	DELETE,
	EXIT
};

int main(void)
{
	int option = 0;
	Uint index;
	char subject[MAX_SUBJECT_LEN];
	float start = 0, end = 0;
	Uint size = 0;

	meeting_t *meeting = NULL;
	calendar_t *calendar = NULL;

	while (EXIT != option)
	{
		if (NULL == calendar)
		{
			printf("Enter the initial capacity for the calendar: ");
			scanf("%u", &size);
			calendar = ADCreate(size);
		}

		printf("Please choose an option:\n\t1) Add meeting to calendar\n\t2) Remove meeting from calendar\n\t3) Find meeting\n\t4) Print calendar\n\t5) Delete calendar\n\t6) Exit\n");
		scanf("%d", &option);
		getchar();

		switch (option)
		{
			case (ADD):
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
			case (REMOVE):
			{
				printf("Enter start time of meeting to remove: ");
				/* problem: what happens when you destroy a meeting without removing it? no good */
				scanf("%f", &start);
				ADRemove(calendar, start);
				break;
			}
			case (FIND):
			{
				printf("Enter start time of meeting to find: ");
				scanf("%f", &start);				
				MeetingPrint(ADFind(calendar, start, &index));
				break;
			}
			case (PRINT):
			{
				ADPrint(calendar);
				break;
			}
			case (DELETE):
			{
				ADDestroy(calendar);
				calendar = NULL;
				break;
			}
			case (EXIT):
			{
				ADDestroy(calendar);
				calendar = NULL;				
				break;
			}
			default:
			{
				puts("Invalid option");
				break;
			}
		}
	}
/*
	appointment = MeetingCreate(9, 10, "Pencil sharpening");
	rendevous = MeetingCreate(13.5, 15, "Flower knitting");
	sit_down = MeetingCreate(10, 11, "The mousse discussion");
*/
	return OK;

	/* TO DO:
			documentation
			input checks on all functions
			test on different inputs
			shrink array as well
	*/
}