/*
	Title:			stack_uses.c
	Description:	Various function utilizing the stack ds
	Author:			Shalev Goldfarb
	Last updated:	07.04.19
*/
#include <stdio.h> 	/* printf()	*/
#include <stdlib.h>	/* malloc()	*/
#include <string.h> /* strlen() */
#include "stack.h"

char* InfixToPostfix(char* _str);
int IsParenthesesOK(char* _str);

int main(void)
{
	char source[] = "{[({})]}";
	char infix[] = "(4+6)*3";
	char* result = NULL;
	printf("%s\n", source);
	(IsParenthesesOK(source)) ? (puts("Nice")) : (puts("Bad sequence"));
	printf("%s\n", infix);
	result = InfixToPostfix(infix);
	printf("%s\n", result);

	free(result);

	return OK;
}

char* InfixToPostfix(char* _str)
{
	int size = 0;
	int status = 0;
	int stackTop = 0;
	int nextChar = 0;
	char* pntr_str = NULL;
	char* result = NULL;
	char* pntr_result = NULL;
	stack_t* stack = NULL;

	pntr_str = _str;
	size = strlen(pntr_str);
	result = (char*)calloc(size, sizeof(char));
	pntr_result = result;
	stack = StackCreate(size, 1);

	while (EOS != *pntr_str)
	{
		if ( ((*pntr_str >= '0') && (*pntr_str <= '9')) || ((*pntr_str >= 'A') && (*pntr_str <= 'Z'))
												|| ((*pntr_str >= 'a') && (*pntr_str <= 'z')) )
		{
			*pntr_result = *pntr_str;
			pntr_result++;
		}
		else if ((*pntr_str >= '*') && (*pntr_str <= '/'))
		{
			while (0 == status)
			{
				StackTop(stack, &stackTop);
				if ((stackTop >= '*') && (stackTop <= '/'))
				{
					if (((*pntr_str == '*') || (*pntr_str == '/')) && ((stackTop == '+') || (stackTop == '-')))
					{
						StackPush(stack, *pntr_str);
						status = 1;
					}
				}
				else if ((stackTop == '(') || (StackIsEmpty(stack)))
				{
					StackPush(stack, *pntr_str);
					status = 1;					
				}
				else
				{
					StackPop(stack, (int*)pntr_result);
					pntr_result++;
				}

			}
			status = 0;
		}
		else if (*pntr_str == '(')
		{
			StackPush(stack, *pntr_str);
		}
		else if (*pntr_str == ')')
		{
			while (0 == status)
			{
				if (StackIsEmpty(stack))
				{
					status = 1;
				}
				else
				{
					StackPop(stack, &nextChar);
					if (nextChar == '(')
					{
						status = 1;
					}
					else
					{
						*pntr_result = nextChar;
						pntr_result++;
					}
				}
			}
			status = 0;
		}
		
		pntr_str++;
	}

	while (!StackIsEmpty(stack))
	{
		StackPop(stack, (int*)pntr_result);
		pntr_result++;
	}
	StackDestroy(stack);

	*pntr_result = EOS;

	return result;
}

int IsParenthesesOK(char* _str)
{
	stack_t* stack = NULL;
	int status = TRUE;
	int item = 0;
	char* pntr_str = _str;

	stack = StackCreate(strlen(_str), 0);

	while (EOS != *pntr_str)
	{
		if (*pntr_str == '{' || *pntr_str == '[' || *pntr_str == '(')
		{
			StackPush(stack, *pntr_str);
		}
		else if (*pntr_str == '}' || *pntr_str == ']' || *pntr_str == ')')
		{
			if (StackIsEmpty(stack))
			{
				status = FALSE;
				break;
			}
			else
			{
				StackPop(stack, &item);
				if ((item == '{' && *pntr_str == '}') ||
					(item == '[' && *pntr_str == ']') ||
					(item == '(' && *pntr_str == ')'))
				{
					pntr_str++;
					continue;
				}
				else
				{
					status = FALSE;
					break;
				}
			}
		}
		else
		{
			continue;
		}
		pntr_str++;
	}

	if (!StackIsEmpty(stack))
	{
		status = FALSE;
	}

	StackDestroy(stack);

	return status;
}