/*
	Title:			hw3.c
	Description:	Various functions
	Author:			Shalev Goldfarb
	Last updated:	01.04.19
*/
#include <stdio.h>
#include <string.h>
#include "hw3.h"

int StrLen(char *_str)
{
	int len = 0;
	while (EOS != *_str)
	{
		_str++;
		len++;
	}

	return len;
}

/*
char *StrCpy(char *_src, char *_dest)
{
	char *head = _dest;

	while (EOS != *_src)
	{
		*_dest = *_src;
		_dest++;
		_src++;
	}
	*_dest = EOS;
	
	return head;
}
*/

void SwapChrs(char *_c, char *_z)
{
	char temp = *_c;
	*_c = *_z;
	*_z = temp;
}

int ReverseStr(char *_str)
{
	char *head;
	char *tail;

	if (NULL == _str)
	{
		return STR_ERROR;
	}

	head = _str;
	tail = _str + StrLen(_str) - 1;

	for (; head <= tail; tail--, head++)
	{
		SwapChrs(head, tail);
	}

	return OK;
}

int SqueezeStr(char *_str, const char *_chars)
{
	char *write_ptr = _str;
	char *read_ptr = _str;

	if (NULL == _str)
	{
		return STR_ERROR;
	}
	if (NULL == _chars)
	{
		return CHR_ERROR;
	}

	while (EOS != *read_ptr)
	{
		if (NULL == strchr(_chars, *read_ptr))
		{
			*write_ptr = *read_ptr;
			write_ptr++;
		}
		read_ptr++;
	}
	*write_ptr = EOS;

	return OK;
}

int Dec2Bin(char *_str, int _num)
{
	char *head = _str;

	if (NULL == _str)
	{
		return STR_ERROR;
	}
	if (_num < 0)
	{
		return NUM_ERROR;
	}

	while (1 != _num)
	{
		if (0 == (_num % 2))
		{
			*_str = '0';
		}
		else
		{
			*_str = '1';
		}
		_str++;
		_num /= 2;
	}
	*_str = '1';
	_str++;
	*_str = EOS;
	ReverseStr(head);

	return OK;
}