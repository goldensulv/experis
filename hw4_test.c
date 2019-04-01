/*
	Title:			hw4_test.c
	Description:	Various functions
	Author:			Shalev Goldfarb
	Last updated:	01.04.19
*/

#include <stdio.h>
#include <stdlib.h>

#define OK 0

typedef struct person
{
	char name[16];
	int age;
	int id;
} person_t;

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
		gets(people[person_index].name);
		printf("Name: %s\n", people[person_index].name);

		printf("Please enter the age for person #%d:\n", person_index + 1);
		scanf("%d", &(people[person_index].age));
		printf("Age: %d.\n", people[person_index].age);

		printf("Please enter the ID number for person #%d:\n", person_index + 1);
		scanf("%d", &(people[person_index].id));
		printf("ID number: %d.\n", people[person_index].id);
		
		getchar();
	}

	printf("%s, %s, %s.\n", people[0].name, people[1].name, people[2].name);

	free(people);

	return OK;
}