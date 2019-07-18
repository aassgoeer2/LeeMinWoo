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
	// List의 생성 및 초기화 //////////////////////////
	List list;
	LData data;
	int x, y;
	ListInit(&list);
	SetSortRule(&list, WhoisBig);

	// 10개의 데이터 저장 /////////////////////////////
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

	// 저장된 데이터의 전체 출력 ////////////////////////
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &data))    // 첫 번째 데이터 조회
	{
		ShowPointPos(data);

		while (LNext(&list, &data))    // 두 번째 이후의 데이터 조회
			ShowPointPos(data);
	}
	printf("\n\n");

	printf("삭제된 데이터\n");
	// x,y중 하나라도 10이나 10의배수를 가지고있는것 모두 삭제 //////////////////////////
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

	// 삭제 후 남아있는 데이터 전체 출력 ////////////////////////
	printf("현재 데이터의 수: %d \n", LCount(&list));

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