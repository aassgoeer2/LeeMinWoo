#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "CLinkedList.h"

int main(void)
{
	// 원형 연결 리스트의 생성 및 초기화 ///////
	List list;
	List Stack;
	int data, i, nodeNum;
	ListInit(&list);
	ListInit(&Stack);

	// 리스트에 5개의 데이터를 저장 /////// 
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);

	//방금넣은데이터를 맨앞으로저장하게 //
	LFirst(&list, &data);
	LInsert(&Stack, data);
	for (i = 0; i < LCount(&list) - 1; i++)
	{
		if (LNext(&list, &data))
			LInsertFront(&Stack, data);
	}

	// 전체 데이터 1회 출력 ///////
	if (LFirst(&Stack, &data))
	{
		printf("%d\n", data);

		for (i = 0; i<LCount(&Stack) - 1; i++)
		{
			if (LNext(&Stack, &data))
				printf("%d\n", data);
		}
	}

	_getch();
	return 0;
}