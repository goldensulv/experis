#include <stdio.h>		/* printf() */
#include <string.h> 	/* strlen() */
#include "stack.h"

#define TRUE 1
#define FALSE 0

int Fibonacci(int _num);
int IsPalindrom(char* _str, int _start, int _end);
int FindMaxInArr(int* _arr, int _start, int _end);
void Hanoi(stack_t* _from, stack_t* _to, stack_t* _via);

int main(void)
{
	stack_t* from = NULL, to = NULL, via = NULL;
	char str[] = "sabgbas";
	int arr[] = {5, 14, 3, 86, 53, 11, 2, 87};
	int len = strlen(str);
	printf("%d\n", Fibonacci(6));
	(IsPalindrom(str, 0, len - 1)) ? (puts("Its a palindrom")) : (puts("Not a palindrom"));
	len = sizeof(arr)/sizeof(arr[0]);
	printf("Max num: %d\n", FindMaxInArr(arr, 0, len - 1));
	from = StackCreate(10,1);
	to = StackCreate(10,1);
	via = StackCreate(10,1);

	return 0;
}

int Fibonacci(int _num)
{
	if (_num > 2)
	{
		return Fibonacci(_num - 1) + Fibonacci(_num - 2);
	}
	else
	{
		return 1;
	}
}

int IsPalindrom(char* _str, int _start, int _end)
{
	if ((_end - _start) <= 1 )
	{
		return TRUE;
	}
	if (_str[_start] == _str[_end])
	{
		return IsPalindrom(_str, _start + 1, _end - 1);
	}
	else
	{
		return FALSE;
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
	if (_arr[_start] >= _arr[_end])
	{
		_end--;
	}
	else
	{
		_start++;
	}

	return FindMaxInArr(_arr, _start, _end);
}

void Hanoi(stack_t* _from, stack_t* _to, stack_t* _via)
{
	if ((0 == _from) && (0 == _via))
	{
		printf("%d , %d , %d\n", _from, _to, _via);
	}

}