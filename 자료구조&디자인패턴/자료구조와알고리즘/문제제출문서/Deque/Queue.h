#pragma once
#include "Deque.h"
#include <stdlib.h>
#include <stdio.h>

typedef DLDeque Queue;

void QueueInit(Queue * que);
int QueIsEmpty(Queue * que);
int DQIsEmpty(Deque * pdeq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);