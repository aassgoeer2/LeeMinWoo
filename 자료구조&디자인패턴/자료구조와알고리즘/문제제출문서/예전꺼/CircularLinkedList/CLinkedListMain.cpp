#include <stdio.h>
#include <conio.h>
#include "CLinkedList.h"


int main(void)
{
	// ���� ���� ����Ʈ�� ���� �� �ʱ�ȭ ///////
	List list;
	Data member;
	int data, i, nodeNum;
	ListInit(&list);

	// ��� ���� 4�� ���
	SetMember(&member, "KimGamma", 1234);
	LInsert(&list, member);
	SetMember(&member, "What", 3478);
	LInsert(&list, member);
	SetMember(&member, "The", 5683);
	LInsert(&list, member);
	SetMember(&member, "Himan", 3346);
	LInsert(&list, member);


	// ��� ���� ���
	printf("��ϵ� ���\n");
	if (LFirst(&list, &member))
	{
		ShowMemberInfo(member);
		for (int i = 1; i <= 3; i++)
		{
			LNext(&list, &member);
			ShowMemberInfo(member);
		}
	}
	printf("\n\n");

	//�����ٹ�
	int AfterDay;
	scanf_s("%d", &AfterDay);

	SetMember(&member, "KimGamma", 1234);//���ñٹ���

	member = NightWalk(&list, member, AfterDay);
	printf("%d�� �� �ٹ���\n", AfterDay);
	ShowMemberInfo(member);

	_getch();
	return 0;
}