#pragma once
#include "Queue.h"

void QueueInit(Queue * que)
{
	que->head = NULL;
	que->tail = NULL;
}

int QueIsEmpty(Queue * que)
{
	if (que->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue * que, Data data)
{
	DQAddLast(que, data);
}


Data Dequeue(Queue * que)
{
	return DQRemoveFirst(que);
}


Data QPeek(Queue * que)
{
	return que->head->data;
}