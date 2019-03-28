/*
	Title:			sorts.c
	Description:	Various simple sorting functions
	Author:			Shalev Goldfarb
	Last updated:	28.03.19
*/
#include <stdio.h> 	/* NULL */
#include "sorts.h"

int CheckParams(int arr[], int size)
{
	int status = OK;

	if (size < 2)
	{
		status = SIZE_ERROR;
	}
	else if (arr == NULL)
	{
		status = ARR_ERROR;
	}

	return status;
}

void SwapInt(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int BubbleSort(int arr[], int size)
{
	int i, check, status = 1;

	if ((check = CheckParams(arr, size)) != OK)
	{
		return check;
	}

	while ((status != 0) && (size > 0))
	{
		status = 0;

		for (i = 0; i < size - 1; i++)
		{
			if ((*(arr + i)) > (*(arr + i + 1)))
			{
				SwapInt(arr+i, arr+i+1);
				status++;
			}
		}
		size--;
	}

	return OK;
}

int OddEvenSort(int arr[], int size)
{
	int check, i = 0, counter = 0;

	if ((check = CheckParams(arr, size)) != OK)
	{
		return check;
	}

	while (((*(arr+i)) % 2) == 0)
	{
		counter++;
		i++;
	}

	i++;

	for (; i < size; i++)
	{
		if (((*(arr+i)) % 2) == 0)
		{
			SwapInt(arr+i, arr+counter);
			counter++;
		}
	}

	return OK;
}

int OneZeroSort(int arr[], int size)
{
	int check;

	if ((check = CheckParams(arr, size)) != OK)
	{
		return check;
	}	

	OddEvenSort(arr, size);

	return OK;
}