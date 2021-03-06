/*
	Title:			sorts_test.c
	Description:	Various simple sorting functions
	Author:			Shalev Goldfarb
	Last updated:	28.03.19
*/
#include <stdio.h> 	/* printf */
#include "sorts.h"

#define ARR_SIZE 10

void PrintArray(int arr[], int size);

int main(void)
{
	int arr[ARR_SIZE] = {6,1,2,8,4,1,2,3,9,3};
	int arr2[ARR_SIZE] = {1,1,1,0,1,0,1,1,0,0};
	PrintArray(&arr[0], ARR_SIZE);
	OddEvenSort(arr, ARR_SIZE);
	PrintArray(arr, ARR_SIZE);
	BubbleSort(arr, ARR_SIZE);
	PrintArray(arr, ARR_SIZE);
	PrintArray(arr2, ARR_SIZE);
	OneZeroSort(arr2, ARR_SIZE);
	PrintArray(arr2, ARR_SIZE);

	return 0;
}

void PrintArray(int arr[], int size)
{
	int i;
	putchar('[');
	for (i = 0; i < size; i++)
	{
		printf("%d,", *(arr+i));
	}
	printf("\b]\n");
}