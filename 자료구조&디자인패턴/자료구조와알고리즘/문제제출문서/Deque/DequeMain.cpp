#pragma once
#include <stdio.h>
#include "Queue.h"
#include <conio.h>

int main(void)
{
	// Deque�� ���� �� �ʱ�ȭ ///////
	Queue Queue;
	QueueInit(&Queue);

	//Queue �������� �����ͳֱ�//
	for (int i = 1; i <= 6; i++)
	{
		Enqueue(&Queue, i);
	}

	// Queue  �������� �����Ͳ�����//
	while (!QueIsEmpty(&Queue))
	{
		printf("%d\n", Dequeue(&Queue));
	}

	_getch();
	return 0;
}