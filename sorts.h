/*
	Title:			sorts.h
	Description:	Various simple sorting functions
	Author:			Shalev Goldfarb
	Last updated:	28.03.19
*/
#define SIZE_ERROR 1
#define ARR_ERROR 2
#define OK 0

/*
	Description: Sorts an array in an ascending order.
	Input: Array and its size.
	Output: Same array, sorted.
	Errors:	Must have a size greater than 1, and has to bee an array of integers.
*/
int BubbleSort(int arr[], int size);
/*
	Description: Sorts an array by putting all even numbers in the beggining.
	Input: An array and its size.
	Output: Same array, sorted by even and then odds.
	Errors: Size has to be bigger than 1, and can only handle integers.
*/
int OddEvenSort(int arr[], int size);
/*
	Description: Sorts an array of 1s and 0s by moving all zeros to the start.
	Input: An array of ones and zeros and its size.
	Output: Same array, sorted by zeros and then ones.
	Errors: Size bigger than 1, and can only handle an array of only ones and zeros.
*/
int OneZeroSort(int arr[], int size);