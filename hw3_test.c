/*
	Title:			hw2.c
	Description:	Various functions
	Author:			Shalev Goldfarb
	Last updated:	28.03.19
*/

#include <stdio.h>

#include "hw3.h"

#define MAX_STR_SIZE 255

int main(void)
{
	char str[MAX_STR_SIZE];
	char c[1];
	int num;
	int option;

	puts("Choose a function to use:\n\t1. ReverseStr\n\t2. SqueezeStr\n\t3. Dec2Bin\n\t4. Exit");
	scanf("%d", &option);
	printf("You chose option %d.\n", option);

	switch (option)
	{
		case 1:
		{
			puts("Please enter a string to reverse:");
			sprintf(str, "%s");
			printf("The string to reverse is: %s\n", str);
			printf("The reversed string is: %s\n", ReverseStr(str));
			break;
		}
		case 2:
		{
			puts("Please enter a string to squeeze:");
			scanf("%s", str);
			puts("Please enter a character to squeeze out:");
			scanf("%s", c);
			printf("The string to squeeze is %s and the character to squeeze out is %s\n", str, c);
			break;
		}
	}

	return OK;
}