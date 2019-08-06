#include <stdio.h>
#include "DBLinkedList.h"

int main(void)
{
	// 양방향 연결 리스트의 생성 및 초기화  ///////
	List list;
	Data data;
	ListInit(&list);

	// 8개의 데이터 저장  ///////
	LInsert(&list, 1);  LInsert(&list, 2);
	LInsert(&list, 3);  LInsert(&list, 4);
	LInsert(&list, 5);  LInsert(&list, 6);
	LInsert(&list, 7);  LInsert(&list, 8);
	LInsert(&list, 9);  LInsert(&list, 10);

	// 저장된 데이터의 조회  ///////
	LFirst(&list, &data);
	printf("%d\n", data);
	while (data != -1)
	{
		LNext(&list, &data);
		if (data != -1)
			printf("%d\n", data);
	}
	printf("\n\n");

	LRemove(&list);//마지막 데이터 하나 삭제
	LRemove(&list);//마지막 데이터 하나 삭제
	LRemove(&list);//마지막 데이터 하나 삭제
	LRemove(&list);//마지막 데이터 하나 삭제
	LRemove(&list);//마지막 데이터 하나 삭제

	// 저장된 데이터 조회
	LFirst(&list, &data);
	printf("%d\n", data);
	while (data != -1)
	{
		LNext(&list, &data);
		if (data != -1)
			printf("%d\n", data);
	}

	return 0;
}