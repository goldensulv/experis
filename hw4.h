/*
	Title:			hw4.h
	Description:	Various functions
	Author:			Shalev Goldfarb
	Last updated:	02.04.19
*/

#include <stdio.h>

#define EOS '\0'
#define FALSE 0
#define TRUE 1
#define PTR_ERROR 1
#define SIZE_ERROR 2
#define OK 0

typedef struct person
{
	char name[20];
	int age;
	int id;
} person_t;

/*
	Description: Sorts an array of type person_t alphabetically.
	Input: A pointer to an array of person_t and the number of entries.
	Output: Same array, sorted according to person_t.name.
	Errors\Return values:	PTR_ERROR if _people is NULL. SIZE_ERROR if _num_of_people is < 1.
							OK if reached the end of the function.
*/
int SortAlphabetic(person_t *_people, int _num_of_people);

/*
	Description: Swaps the information between two person_t(s).
	Input: Two pointers to person_t.
	Output: The information is swapped between the variables.
	Errors\Return values:	PTR_ERROR if one (or both) of the pointers is NULL, 
							OK if reached the end of the function.
*/
int SwapPeople(person_t *_a, person_t *_b);

/*
	Description:	Uses SwapPeople and StrCmp to move the person_t with the 'largest' name to its 
					place in _people, alphabetically.
	Input: 	A pointer to an array of person_t, and the number of entries to be sized.
	Output:	Same array, sorted between _people[_size-1] and the last entry in the array.
	Errors\Return values:	PTR_ERROR if _people is NULL. TRUE if a sorting occured, FALSE otherwise.
*/
int BubbleUp(person_t *_people, int _size);

/*
	Description: Compares two strings.
	Input: 
*/
int StrCmp(const char *_s, const char *_t);