#include <stdio.h>
#include "Deque.h"
#include <conio.h>

int main(void)
{
	// Deque�� ���� �� �ʱ�ȭ ///////
	Deque Queue;
	DequeInit(&Queue);

	//Queue �������� �����ͳֱ�//
	for (int i = 1; i <= 6; i++)
	{
		DQAddLast(&Queue, i);
	}

	// Queue  �������� �����Ͳ�����//
	while (!DQIsEmpty(&Queue))
	{
		printf("%d\n", DQRemoveFirst(&Queue));
	}

	_getch();
	return 0;
}