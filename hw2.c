/*
	Title:			hw2.c
	Description:	Various functions
	Author:			Shalev Goldfarb
	Last updated:	28.03.19
*/

#include <stdio.h>

int main(void)
{
	int num = 22;

	(IsAscending(num) == 1) ? (printf("Ascending\n")) : (printf("Not Ascending\n"));
	(IsPalindrome(num) == 1) ? (printf("Palindrome\n")) : (printf("Not Palindrome\n"));
	(IsPrime(num) == 1) ? (printf("Prime\n")) : (printf("Not Prime\n"));
	printf("Bigger closest prime to %d is %d.\n", num, BiggerClosestPrime(num));

	return  0;
}

int IsAscending(int num)
{
	int status = 1;
	int digit = num % 10;
	num /= 10;
	while ((num != 0) && (status == 1))
	{
		if ((num % 10) > (digit))
		{
			status = 0;
		}
		else
		{
			digit = num % 10;
			num /= 10;
		}
	}

	return status;
}

int IsPalindrome(int num)
{
	int temp, status, new_num;
	temp = num;
	status = 1;
	new_num = 0;

	while (temp != 0)
	{
		new_num *= 10;
		new_num += (temp % 10);
		temp /= 10;
	}

	if (num != new_num)
	{
		status = 0;
	}

	return status;
}

int IsPrime(int num)
{
	int i, status = 1;
	int divider = num / 2;

	for (i = 2; i <= divider; i++)
	{
		if ((num % i) == 0)
		{
			status = 0;
			break;
		}
	}

	return status;
}

int BiggerClosestPrime(int num)
{
	int status = 0;
	while ((status == 0) && (num >= 0))
	{
		num++;
		if (IsPrime(num))
		{
			status = 1;
		}
	}
	if (num > 0)
	{
		return num;
	}
}