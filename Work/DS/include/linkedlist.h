/*
	Title:			linkedlist.h
	Description:	Linked List ADT - header
	Author:			Shalev Goldfarb
	Last updated:	10.04.19
*/

typedef struct person person_t;

/*
	Description: Inserts node _new to the list at position head.
	Errors\Return: NULL if(_head == NULL) or (_new == NULL), returns pointer to new head on success.
*/
person_t* ListInsertHead(person_t* _head, person_t* _new);

/*
	Description: Removes the node pointed to by _head, and putting it into _removed.
	Errors\Return: NULL if (_head == NULL) or (_removed == NULL), returns pointer to new head on success.
*/
person_t* ListRemoveHead(person_t* _head, person_t** _removed);

/*
	Description: Inserts the node _new with key _key into the linked list, using _key as the index.
	Errors\Return: NULL if (_head == NULL) or (_new == NULL), returns pointer to new head on success.
*/
person_t* ListInsertByKey(person_t* _head, int _key, person_t* _new);

/*
	Description: Inserts the node _new with key _key into the linked list, using _key as the index. Recursive.
	Errors\Return: NULL if (_head == NULL) or (_new == NULL), returns pointer to new head on success.
*/
person_t* ListInsertByKeyRec(person_t* _head, int _key, person_t* _new);

/*
	Description: Remove the node with key _key from the linked list, and puts a pointer to it at _removed.
	Errors\Return: NULL if (_head == NULL) or if _key does not match any node in the list. Returns pointer to new head on success.
*/
person_t* ListRemoveByKey(person_t* _head, int _key, person_t** _removed);

/*
	Description: Remove the node with key _key from the linked list, and puts a pointer to it at _removed. Recursive.
	Errors\Return: NULL if (_head == NULL) or if _key does not match any node in the list. Returns pointer to new head on success.
*/
person_t* ListRemoveByKeyRec(person_t* _head, int _key, person_t** _removed);

/*
	Description: Creates a node of type person_t*.
	Errors\Return: NULL if (_name == NULL), returns a pointer to the new node on success.
*/
person_t* PersonNodeCreate(int _id, char* _name, int _age);


void PersonNodeDestroy(person_t* _person);

void ListDestroy(person_t* _head);

/*
	Description: Prints the linked list to stdout starting at the node pointed to by _head.
*/
void ListPrint(person_t* _head);