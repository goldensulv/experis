/*
	Title:			hw2.c
	Description:	Various functions
	Author:			Shalev Goldfarb
	Last updated:	28.03.19
*/

#include "hw3.h"

int StrLen(char *_str)
{
	int len = 0;
	while ('\0' != *_str)
	{
		_str++;
		len++;
	}

	return len;
}

void SwapChrs(char *_c, char *_z)
{
	char temp = *_c;
	*_c = *_z;
	*_z = temp;
}

char *ReverseStr(char *_str)
{
	char c;
	char *head;
	char *tail;

	head = _str;
	tail = _str + StrLen(_str);

	for (; head != tail; tail--, head++)
	{
		SwapChrs(head, tail);
	}

	return _str;
}