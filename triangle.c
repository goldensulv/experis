/*
	Title:			triangle.c
	Description:	Draw different triangles using ascii characters
	Author:			Shalev Goldfarb
	Last updated:	28.03.19
*/

#include <stdio.h>
#include "triangle.h"

int CheckParams(int size, char chr)
{
	if ((size < MIN_SIZE) || (size > MAX_SIZE))
	{
		return SIZE_ERROR;
	}

	if ((chr < '!') || (chr > '~'))
	{
		return CHAR_ERROR;
	}

	return OK;
}

void PrintLine(int size, char chr)
{
	for (; size > 0; size--)
	{
		putchar(chr);
	}
}

void PrintLineWithSpaces(int size, char chr)
{
	for (; size > 0; size--)
	{
		putchar(chr);
		putchar(' ');
	}
}

int Triangle1(int size, char chr)
{
	int i,check;

	if ((check = CheckParams(size, chr)) != OK)
	{
		return check;
	}

	for (i = 1; i <= size; i++)
	{
		PrintLine(i, chr);
		putchar('\n');
	}

	return OK;
}

int Triangle2(int size, char chr)
{
	int check;

	if ((check = CheckParams(size, chr)) != OK)
	{
		return check;
	}

	while (size > 0)
	{
		PrintLine(size, chr);
		putchar('\n');
		size--;
	}
}

int Triangle3(int size, char chr)
{
	int check;

	if ((check = CheckParams(size, chr)) != OK)
	{
		return check;
	}

	Triangle1(size, chr);
	Triangle2(size-1, chr);
}

int Triangle4(int size, char chr)
{
	int check, i = 1;

	if ((check = CheckParams(size, chr)) != OK)
	{
		return check;
	}

	while (size > 0)
	{
		PrintLine(size-1, ' ');
		PrintLineWithSpaces(i, chr);
		putchar('\n');
		size--;
		i++;
	}
}

int Triangle5(int size, char chr)
{
	int check, i = 1;

	if ((check = CheckParams(size, chr)) != OK)
	{
		return check;
	}

	while (size > 0)
	{
		PrintLine(i-1, ' ');
		PrintLineWithSpaces(size, chr);
		putchar('\n');
		size--;
		i++;
	}	
}

int Triangle6(int size, char chr)
{
	int check, i = 1;

	if ((check = CheckParams(size, chr)) != OK)
	{
		return check;
	}

	Triangle4(size, chr);
	size--;

	while (size > 0)
	{
		PrintLine(i, ' ');
		PrintLineWithSpaces(size, chr);
		putchar('\n');
		size--;
		i++;
	}
}