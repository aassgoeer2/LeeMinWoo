#include <stdio.h>
#include <conio.h>
#include "DLinkedList.h"

int main(void)
{
	// List�� ���� �� �ʱ�ȭ /////////////////////////////
	List list;
	LData data;
	ListInit(&list);

	// 5���� ������ ���� /////////////////////////////
	for (int i = 1; i <= 5; i++)
	{
		SetPointPos(&data, i, i + 1);
		LInsert(&list, data);
	}

	// ����� �������� ��ü ��� /////////////////////////
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &data))    // ù ��° ������ ��ȸ
	{
		ShowPointPos(data);

		while (LNext(&list, &data))    // �� ��° ������ ������ ��ȸ
			ShowPointPos(data);
	}
	printf("\n\n");

	printf("������ ������\n");
	// x,y�� �ϳ��� 2�� �������ִ°� ��� ���� //////////////////////////
	if (LFirst(&list, &data))
	{
		if (data.xpos == 2 || data.ypos == 2)
		{
			data = LRemove(&list);
			ShowPointPos(data);
		}

		while (LNext(&list, &data))
		{
			if (data.xpos == 2 || data.ypos == 2)
			{
				data = LRemove(&list);
				ShowPointPos(data);
			}
		}
	}
	printf("\n\n");

	// ���� �� �����ִ� ������ ��ü ��� ////////////////////////
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		ShowPointPos(data);

		while (LNext(&list, &data))
			ShowPointPos(data);
	}
	printf("\n\n");

	getch();
	return 0;
}