/*
	Title:			hw2.c
	Description:	Various functions
	Author:			Shalev Goldfarb
	Last updated:	28.03.19
*/

#define OK 0

/*
	Description: Reverses a string.
	Input: A string. String must have a terminating null byte.
	Output: The input string reversed.
	Errors:	STR_ERROR returned if string is empty.
*/
char *ReverseStr(char *_str);

/*
	Description: Removes all instances of character _c from the string _str.
	Input: A string with a terminating null byte, and a character.
	Output: The input string with all instances of _c removed.
	Errors: STR_ERROR if string is empty. CHR_ERROR if char is an empty character.
*/
char *SqueezeStr(char *_str, char _c);

/*
	Description: Returns the binary representation of the integer _num.
	Input: A non-negative integer, and a non-null string.
	Output: A string of the binary representation of _num.
	Errors: A negative number will produce a NUM_ERROR. 
*/	
char *Dec2Bin(char *_str, int _num);