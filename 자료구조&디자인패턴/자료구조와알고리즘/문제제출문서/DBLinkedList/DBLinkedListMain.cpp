#include <stdio.h>
#include "DBLinkedList.h"

int main(void)
{
	// ����� ���� ����Ʈ�� ���� �� �ʱ�ȭ  ///////
	List list;
	Data data;
	ListInit(&list);

	// 8���� ������ ����  ///////
	LInsert(&list, 1);  LInsert(&list, 2);
	LInsert(&list, 3);  LInsert(&list, 4);
	LInsert(&list, 5);  LInsert(&list, 6);
	LInsert(&list, 7);  LInsert(&list, 8);
	LInsert(&list, 9);  LInsert(&list, 10);

	// ����� �������� ��ȸ  ///////
	LFirst(&list, &data);
	printf("%d\n", data);
	while (data != -1)
	{
		LNext(&list, &data);
		if (data != -1)
			printf("%d\n", data);
	}
	printf("\n\n");

	LRemove(&list);//������ ������ �ϳ� ����
	LRemove(&list);//������ ������ �ϳ� ����
	LRemove(&list);//������ ������ �ϳ� ����
	LRemove(&list);//������ ������ �ϳ� ����
	LRemove(&list);//������ ������ �ϳ� ����

	// ����� ������ ��ȸ
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