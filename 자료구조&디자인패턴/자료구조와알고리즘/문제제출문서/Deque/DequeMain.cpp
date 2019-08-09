#pragma once
#include <stdio.h>
#include "Queue.h"
#include <conio.h>

int main(void)
{
	// Deque의 생성 및 초기화 ///////
	Queue Queue;
	QueueInit(&Queue);

	//Queue 형식으로 데이터넣기//
	for (int i = 1; i <= 6; i++)
	{
		Enqueue(&Queue, i);
	}

	// Queue  형식으로 데이터꺼내기//
	while (!QueIsEmpty(&Queue))
	{
		printf("%d\n", Dequeue(&Queue));
	}

	_getch();
	return 0;
}