#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include "DLinkedList.h"

int WhoisBig(LData d1, LData d2)
{
	if (d1.xpos < d2.xpos)
		return 0;
	else if (d1.xpos == d2.xpos)
	{
		if (d1.ypos < d2.ypos)
			return 0;
	}
	return 1;
}

int main(void)
{
	srand(time(NULL));
	// List�� ���� �� �ʱ�ȭ //////////////////////////
	List list;
	LData data;
	int x, y;
	ListInit(&list);
	SetSortRule(&list, WhoisBig);

	// 10���� ������ ���� /////////////////////////////
	for (int i = 1; i <= 10; i++)
	{
		x = rand() % 100 + 1;
		y = rand() % 100 + 1;
		SetPointPos(&data, x, y);
		if (i == 1)
			FInsert(&list, data);
		else
			SInsert(&list, data);
	}

	// ����� �������� ��ü ��� ////////////////////////
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &data))    // ù ��° ������ ��ȸ
	{
		ShowPointPos(data);

		while (LNext(&list, &data))    // �� ��° ������ ������ ��ȸ
			ShowPointPos(data);
	}
	printf("\n\n");

	printf("������ ������\n");
	// x,y�� �ϳ��� 10�̳� 10�ǹ���� �������ִ°� ��� ���� //////////////////////////
	if (LFirst(&list, &data))
	{
		if (data.xpos % 10 == 0 || data.ypos % 10 == 0)
		{
			data = LRemove(&list);
			ShowPointPos(data);
		}

		while (LNext(&list, &data))
		{
			if (data.xpos % 10 == 0 || data.ypos % 10 == 0)
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