#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->numOfData = 0;
}

void LInsert(List * plist, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->tail;

	if (plist->head->next == NULL)
	{
		plist->head->next = newNode;
		newNode->prev = plist->head;
	}
	else
	{
		newNode->prev = plist->tail->prev;
		plist->tail->prev->next = newNode;
	}
	plist->tail->prev = newNode;
	(plist->numOfData)++;
}

void LFirst(List * plist, Data * pdata)
{
	if (plist->head->next == NULL)
	{
		*pdata = -1;
		return;
	}

	plist->cur = plist->head->next;
	*pdata = plist->cur->data;

	return;
}

void LNext(List * plist, Data * pdata)
{
	if (plist->cur->next == plist->tail || plist->cur->next == NULL)
	{
		*pdata = -1;
		return;
	}

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return;
}

Data LRemove(List* plist)
{
	Node * tmp;
	Data data;
	tmp = plist->cur;
	data = tmp->data;

	if (tmp->next != plist->tail)
		tmp->prev->next = tmp->next;
	else
		tmp->prev->next = plist->tail;

	if (tmp->prev != plist->head)
		tmp->next->prev = tmp->prev;

	plist->cur = plist->cur->prev;

	free(tmp);

	(plist->numOfData)--;
	return data;
}

int LCount(List * plist)
{
	return plist->numOfData;
}