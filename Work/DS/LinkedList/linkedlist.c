/*
	Title:			linkedlist.c
	Description:	Linked List ADT
	Author:			Shalev Goldfarb
	Last updated:	11.04.19
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

struct person
{
	int m_id;
	char m_name[128];
	int m_age;
	person_t* m_next;
};

person_t* ListInsertHead(person_t* _head, person_t* _new)
{
	if (NULL == _new)
	{
		return NULL;
	}

	_new->m_next = _head;
	_head = _new;

	return _head;
}

person_t* ListRemoveHead(person_t* _head, person_t** _removed)
{
	if (NULL == _head)
	{
		return _head;
	}
	if (NULL != _removed)
	{
		*_removed = _head;
	}
	_head = _head->m_next;

	return _head;
}

person_t* ListInsertByKey(person_t* _head, int _key, person_t* _new)
{
	person_t* currentNode = _head;
	if ((NULL == _head) || (NULL == _new))
	{
		return _head;
	}

	if (_head->m_id >= _key)
	{
		_new->m_next = _head;
		_head = _new;
	}
	else
	{
		while ((NULL != currentNode->m_next) && (currentNode->m_next->m_id < _key))
		{
			currentNode = currentNode->m_next;
		}
		if (currentNode->m_next->m_id >= _key)
		{
			_new->m_next = currentNode->m_next;
			currentNode->m_next = _new;
		}
	}

	return _head;
}

person_t* ListRemoveByKey(person_t* _head, int _key, person_t** _removed)
{
	person_t* currentNode = _head;
	if (NULL == _head)
	{
		return _head;
	}
	if (_head->m_id == _key)
	{
		if (NULL != _removed)
		{
			*_removed = _head;
		}

		_head = _head->m_next;
	}
	else
	{
		while ((NULL != currentNode->m_next) && (currentNode->m_next->m_id != _key))
		{
			currentNode = currentNode->m_next;
		}
		if (_key == currentNode->m_next->m_id)
		{
			if (NULL != _removed)
			{
				*_removed = currentNode->m_next;
			}
			currentNode->m_next = currentNode->m_next->m_next;			
		}
	}

	return _head;		
}

person_t* PersonNodeCreate(int _id, char* _name, int _age)
{
	person_t* person = NULL;

	person = (person_t*)malloc(sizeof(person_t));
	if (NULL == person)
	{
		return NULL;
	}

	person->m_id = _id;
	if (NULL != _name)
	{
		strcpy(person->m_name, _name);		
	}
	else
	{
		strcpy(person->m_name, "Jon Doe");
	}
	person->m_age = _age;
	person->m_next = NULL;

	return person;
}

void PersonNodeDestroy(person_t* _person)
{
	if (NULL == _person)
	{
		return;
	}
	free(_person);

	return;	
}

void ListDestroy(person_t* _head)
{
	person_t* temp = NULL;
	if (NULL == _head)
	{
		return;
	}
	while (NULL != _head->m_next)
	{
		_head = ListRemoveHead(_head, &temp);
		PersonNodeDestroy(temp);
	}
	_head = ListRemoveHead(_head, &temp);
	PersonNodeDestroy(temp);	

	return;	
}

void PersonPrint(person_t* _person)
{
	printf("This is %s, ID-%d. Age: %d.\n", _person->m_name, _person->m_id, _person->m_age);
	return;
}

void ListPrint(person_t* _head)
{
	if (NULL == _head)
	{
		return;
	}
	while (NULL != _head->m_next)
	{
		PersonPrint(_head);
		_head = _head->m_next;
	}
	PersonPrint(_head);

	return;
}