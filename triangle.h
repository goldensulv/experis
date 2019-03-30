/*
	Title:			triangle.h
	Description:	Draw different triangles using ascii characters
	Author:			Shalev Goldfarb
	Last updated:	28.03.19
*/

#define MAX_SIZE 40
#define MIN_SIZE 2
#define SIZE_ERROR 1
#define CHAR_ERROR 2
#define OK 0

/*
	Description:	These functions produce triangles of various types.
	Input:			Size of the triangle and the character to use.		
	Output:			A triangle of size 'size' using char 'chr'
	Errors:			Numbers not within 2-40 will produce a size error.
					Non-printable characters will produce a char error.
*/
int Triangle1(int size, char chr);

int Triangle2(int size, char chr);

int Triangle3(int size, char chr);

int Triangle4(int size, char chr);

int Triangle5(int size, char chr);

int Triangle6(int size, char chr);