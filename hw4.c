/*
	Title:			hw4.c
	Description:	Various functions
	Author:			Shalev Goldfarb
	Last updated:	02.04.19
*/

#include "hw4.h"

/* Functions */

int SortAlphabetic(person_t *_people, int _num_of_people)
{
	int status = TRUE;

	if (NULL == _people)
	{
		return PTR_ERROR;
	}
	if (_num_of_people < 1)
	{
		return SIZE_ERROR;
	}

	while ((FALSE != status) && (_num_of_people > 0))
	{
		status = FALSE;
		status = BubbleUp(_people, _num_of_people);
		_num_of_people--;
	}

	return OK;
}

int BubbleUp(person_t *_people, int _size)
{
	int comparison, status, i = FALSE;

	if (NULL == _people)
	{
		return PTR_ERROR;
	}

	for (; i < _size - 1; i++)
	{
		comparison = StrCmp(_people[i].name, _people[i + 1].name);
		if (comparison > 0)
		{
			SwapPeople(_people+i, _people+i+1);
			status = TRUE;
		}
	}

	return status;	
}

int SwapPeople(person_t *_a, person_t *_b)
{
	person_t temp = {0};
	
	if ((NULL == _a) || (NULL == _b))
	{
		return PTR_ERROR;
	}

	temp = *_a;
	*_a = *_b;
	*_b = temp;

	return OK;
}

int StrCmp(const char *_s, const char *_t)
{
    while ((*_s == *_t) && ('\0' != *_s));
    _s++;
    _t++;

    return (*_s - *_t);
}