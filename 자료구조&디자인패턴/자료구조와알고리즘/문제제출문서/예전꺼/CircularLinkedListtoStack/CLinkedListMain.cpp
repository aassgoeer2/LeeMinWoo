#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "CLinkedList.h"

int main(void)
{
	// ���� ���� ����Ʈ�� ���� �� �ʱ�ȭ ///////
	List list;
	List Stack;
	int data, i, nodeNum;
	ListInit(&list);
	ListInit(&Stack);

	// ����Ʈ�� 5���� �����͸� ���� /////// 
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);

	//��ݳ��������͸� �Ǿ����������ϰ� //
	LFirst(&list, &data);
	LInsert(&Stack, data);
	for (i = 0; i < LCount(&list) - 1; i++)
	{
		if (LNext(&list, &data))
			LInsertFront(&Stack, data);
	}

	// ��ü ������ 1ȸ ��� ///////
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