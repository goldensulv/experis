/*
	Title:			hw4_test.c
	Description:	Various functions
	Author:			Shalev Goldfarb
	Last updated:	02.04.19
*/

#include <stdio.h>
#include <stdlib.h>
#include "hw4.h"

#define PERSON people[person_index]

/* main */
int main(void)
{
	person_t *people = NULL;
	int num_of_people;
	int person_index;

	puts("Enter the number of people:");
	scanf("%d", &num_of_people);
	getchar();
	printf("Number of people is: %d.\n", num_of_people);

	people = malloc(sizeof(person_t) * num_of_people);

	for (person_index = 0; person_index < num_of_people; person_index++)
	{
		printf("Please enter the name for person #%d:\n", person_index + 1);
		gets(PERSON.name);
		printf("Name: %s.\n", PERSON.name);

		printf("Please enter the age for person #%d:\n", person_index + 1);
		scanf("%d", &(PERSON.age));
		printf("Age: %d.\n", PERSON.age);

		printf("Please enter the ID number for person #%d:\n", person_index + 1);
		scanf("%d", &(PERSON.id));
		printf("ID number: %d.\n", PERSON.id);

		getchar();
	}

	SortAlphabetic(people, num_of_people);

	person_index = 0;
	while (person_index < num_of_people)
	{
		printf("Person #%d)\t%s,\tage %2d,\tID - %d.\n", person_index + 1, PERSON.name,	PERSON.age, PERSON.id);
		person_index++;
	}

	free(people);

	return OK;
}