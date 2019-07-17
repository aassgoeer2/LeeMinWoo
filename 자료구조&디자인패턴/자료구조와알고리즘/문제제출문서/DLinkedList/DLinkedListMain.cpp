#include <stdio.h>
#include <conio.h>
#include "DLinkedList.h"

int main(void)
{
	// List의 생성 및 초기화 /////////////////////////////
	List list;
	LData data;
	ListInit(&list);

	// 5개의 데이터 저장 /////////////////////////////
	for (int i = 1; i <= 5; i++)
	{
		SetPointPos(&data, i, i + 1);
		LInsert(&list, data);
	}

	// 저장된 데이터의 전체 출력 /////////////////////////
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &data))    // 첫 번째 데이터 조회
	{
		ShowPointPos(data);

		while (LNext(&list, &data))    // 두 번째 이후의 데이터 조회
			ShowPointPos(data);
	}
	printf("\n\n");

	printf("삭제된 데이터\n");
	// x,y중 하나라도 2를 가지고있는것 모두 삭제 //////////////////////////
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