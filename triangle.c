#include <stdio.h>

void Triangle1(int size, char chr)
{
	int j = 0;
	int i = 1;

	while (size > 0)
	{
		j = i;
		while (j > 0)
		{
			printf("%c", chr);
			j--;
		}
		printf("\n");
		size--;
		i++;
	}
}

void Triangle2(int size, char chr)
{
	int j = 0;
	int i = size;

	while (size > 0)
	{
		j = i;
		while (j > 0)
		{
			printf("%c", chr);
			j--;
		}
		printf("\n");
		size--;
		i--;
	}
}

void Triangle3(int size, char chr)
{
	Triangle1(size, chr);
	Triangle2(size-1, chr);
}

void Triangle4(int size, char chr)
{
	int spaces = 0;
	int i = 1;
	int j = 0;

	while (size > 0)
	{
		spaces = size - 1;
		while (spaces > 0)
		{
			printf(" ");
			spaces--;
		}
		j = i;
		while (j > 0)
		{
			printf("%c ", chr);
			j--;
		}
		printf("\n");
		size--;
		i++;
	}
}

void Triangle5(int size, char chr)
{
	int spaces = 0;
	int i = 1;
	int j = 0;

	while (size > 0)
	{
		spaces = i - 1;
		while (spaces > 0)
		{
			printf(" ");
			spaces--;
		}
		
		j = size;
		while (j > 0)
		{
			printf("%c ", chr);
			j--;
		}
		printf("\n");
		size--;
		i++;
	}	
}

void Triangle6(int size, char chr)
{
	int spaces = 0;
	int i = 1;
	int j = 0;

	Triangle4(size, chr);
	size--;

	while (size > 0)
	{
		spaces = i;
		while (spaces > 0)
		{
			printf(" ");
			spaces--;
		}
		j = size;
		while (j > 0)
		{
			printf("%c ", chr);
			j--;
		}
		printf("\n");
		size--;
		i++;
	}
}