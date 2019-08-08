#include <stdio.h>
#include "Deque.h"
#include <conio.h>

int main(void)
{
	// Deque의 생성 및 초기화 ///////
	Deque Queue;
	DequeInit(&Queue);

	//Queue 형식으로 데이터넣기//
	for (int i = 1; i <= 6; i++)
	{
		DQAddLast(&Queue, i);
	}

	// Queue  형식으로 데이터꺼내기//
	while (!DQIsEmpty(&Queue))
	{
		printf("%d\n", DQRemoveFirst(&Queue));
	}

	_getch();
	return 0;
}