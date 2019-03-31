/*
	Title:			sorts.c
	Description:	Various simple sorting functions
	Author:			Shalev Goldfarb
	Last updated:	28.03.19
*/
#include <stdio.h> 	/* NULL */
#include "sorts.h"

int CheckParams(int _arr[], int _size)
{
	int status = OK;

	if (_size < 2)
	{
		status = SIZE_ERROR;
	}
	else if (_arr == NULL)
	{
		status = ARR_ERROR;
	}

	return status;
}

int IsOnesAndZeros(int _arr[], int _size)
{
	int i = 0;

	while (i < _size)
	{
		if (((*(_arr+i)) != 0) && ((*(_arr+i)) != 1))
		{
			return ARR_ERROR;
		}

		i++;
	}

	return OK;
}

int CheckParamsBinary(int _arr[], int _size)
{
	int status = OK;

	if (_size < 2)
	{
		status = SIZE_ERROR;
	}
	else if ((NULL == _arr) || (IsOnesAndZeros(_arr, _size)))
	{
		status = ARR_ERROR;
	}

	return status;
}

void SwapInt(int *_x, int *_y)
{
	int temp = *_x;
	*_x = *_y;
	*_y = temp;
}

int BubbleUp(int _arr[], int _size)
{
	int i, status = FALSE;

	for (i = 0; i < _size - 1; i++)
	{
		if ((*(_arr + i)) > (*(_arr + i + 1)))
		{
			SwapInt(_arr+i, _arr+i+1);
			status = TRUE;
		}
	}

	return status;	
}

int BubbleSort(int _arr[], int _size)
{
	int i, check, status = TRUE;

	if ((check = CheckParams(_arr, _size)) != OK)
	{
		return check;
	}

	while ((FALSE != status) && (_size > 0))
	{
		status = FALSE;
		status = BubbleUp(_arr, _size);
		_size--;
	}

	return OK;
}

int OddEvenSort(int _arr[], int _size)
{
	int check, odd = 0, even = 0;

	if ((check = CheckParams(_arr, _size)) != OK)
	{
		return check;
	}

	while (((*(_arr+odd)) % 2) == 0)
	{
		odd++;
	}

	even = odd;
	odd++;

	for (; odd < _size; odd++)
	{
		if (((*(_arr+odd)) % 2) == 0)
		{
			SwapInt(_arr+odd, _arr+even);
			even++;
		}
	}

	return OK;
}

int OneZeroSort(int _arr[], int _size)
{
	int check;
	int *head;
	int *tail;

	head = _arr;
	tail = _arr+_size-1;

	if ((check = CheckParamsBinary(_arr, _size)) != OK)
	{
		return check;
	}	

	while (head != tail)
	{
		if (*head == 0)
		{
			head++;
		}
		else if (*tail == 0)
		{
			SwapInt(head, tail);
		}
		else
		{
			tail--;
		}
	}

	return OK;
}