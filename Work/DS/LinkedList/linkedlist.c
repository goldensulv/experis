/*
	Title:			linkedlist.c
	Description:	Linked List ADT
	Author:			Shalev Goldfarb
	Last updated:	10.04.19
*/
#include "linkedlist.h"

struct person
{
	int m_id;
	char m_name[128];
	int m_age;
	person_t* m_next;
};

person_t* ListNodeCreate(int _id, char* _name, int _age)
{
	person_t* person = NULL;
	if (NULL == _name)
	{
		return NULL;
	}

	person = (person_t*)malloc(sizeof(person_t));
	if (NULL == person)
	{
		return NULL;
	}

	person->m_id = _id;
	strcpy(person->m_name, _name);
	person->m_age = _age;
}

void ListPrint(person_t* _head)
{
	return;
}