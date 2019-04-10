#include <stdio.h>		/* printf() */
#include <string.h> 	/* strlen() */
#include "stack.h"

#define TRUE 1
#define FALSE 0

int Fibonacci(int _num);
int IsPalindrom(char* _str, int _start, int _end);
int FindMaxInArr(int* _arr, int _start, int _end);
void HanoiTowers(int _numOfRings, stack_t* _from, stack_t* _to, stack_t* _via);

int main(void)
{
	int i;
	stack_t* from;
	stack_t* to;
	stack_t* via;
	char palindrom_str[] = "sabgbas";
	int arr[] = {5, 14, 3, 86, 53, 11, 2, 87};
	int len = strlen(palindrom_str);

	/* Fibonacci */
	printf("%d\n", Fibonacci(36));
	
	/* IsPalindrom */
	(IsPalindrom(palindrom_str, 0, len - 1)) ? (puts("Its a palindrom")) : (puts("Not a palindrom"));

	/* FindMaxInArr */
	len = sizeof(arr)/sizeof(arr[0]);
	printf("Max num: %d\n", FindMaxInArr(arr, 0, len - 1));

	/* HanoiTowers */
	from = StackCreate(32,1);
	to = StackCreate(32,1);
	via = StackCreate(32,1);
	i = 1;
	while (i < 26)
	{
		StackPush(from, 26 - i);
		i++;
	}
	HanoiTowers(25, from, to, via);
	StackPrint(to);

	StackDestroy(from);
	StackDestroy(to);
	StackDestroy(via);

	return 0;
}

int Fibonacci(int _num)
{
	if (_num <= 2)
	{
		return 1;
	}
	else
	{
		return Fibonacci(_num - 1) + Fibonacci(_num - 2);
	}
}

int IsPalindrom(char* _str, int _start, int _end)
{
	if ((_end - _start) <= 1 )
	{
		return TRUE;
	}
	if (_str[_start] != _str[_end])
	{
		return FALSE;
	}
	else
	{
		return IsPalindrom(_str, _start + 1, _end - 1);
	}
}

int FindMaxInArr(int* _arr, int _start, int _end)
{
	if ((_end - _start) == 1)
	{
		if (_arr[_start] >= _arr[_end])
		{
			return _arr[_start];
		}
		else
		{
			return _arr[_end];
		}
	}
	else if (_arr[_start] >= _arr[_end])
	{
		_end--;
	}
	else
	{
		_start++;
	}

	return FindMaxInArr(_arr, _start, _end);
}

void HanoiTowers(int _numOfRings, stack_t* _from, stack_t* _to, stack_t* _via)
{
	static int ring = 0;
	if (1 == _numOfRings)
	{
		StackPop(_from, &ring);
		StackPush(_to, ring);
	}
	else
	{
		HanoiTowers(_numOfRings - 1,  _from, _via, _to);
		HanoiTowers(1, _from, _to, _via);
		HanoiTowers(_numOfRings - 1, _via, _to, _from);
	}
} 