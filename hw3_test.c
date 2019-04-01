/*
	Title:			hw3_test.c
	Description:	Various functions
	Author:			Shalev Goldfarb
	Last updated:	01.04.19
*/

#include <stdio.h>

#include "hw3.h"

#define MAX_STR_SIZE 255

int main(void)
{
	char str[MAX_STR_SIZE];
	char chars[MAX_STR_SIZE];
	int num;
	int status;
	int option;

	puts("Choose a function to use:\n\t1. ReverseStr\n\t2. SqueezeStr\n\t3. Dec2Bin\n\t4. Exit");
	scanf("%d", &option);
	getchar();
	printf("You chose option %d.\n", option);

	switch (option)
	{
		case 1:
		{
			puts("Please enter a string to reverse:");
			gets(str);
			printf("The string to reverse is: %s\n", str);
			status = ReverseStr(str);
			if (!status)
			{
				printf("The reversed string is: %s\n", str);	
			}
			break;
		}
		case 2:
		{
			puts("Please enter a string to squeeze:");
			gets(str);
			puts("Please enter characters to squeeze out:");
			gets(chars);
			printf("The string to squeeze is %s and the character to squeeze out is %s\n", str, chars);
			status = SqueezeStr(str, chars);
			if (!status)
			{
				printf("The sequeezed string is: %s\n", str);	
			}
			break;
		}
		case 3:
		{
			puts("Please enter a non-negative number to display its binary representation:");
			scanf("%d", &num);
			status = Dec2Bin(str, num);
			if (!status)
			{
				printf("The number you entered is %d, and in binary it's %s.\n", num, str);
			}
			break;
		}
		case 4:
		{
			break;
		}
		default:
		{
			break;
		}
	}

	return OK;
}