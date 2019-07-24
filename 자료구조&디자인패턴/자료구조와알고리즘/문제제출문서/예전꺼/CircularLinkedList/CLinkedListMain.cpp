#include <stdio.h>
#include <conio.h>
#include "CLinkedList.h"


int main(void)
{
	// 원형 연결 리스트의 생성 및 초기화 ///////
	List list;
	Data member;
	int data, i, nodeNum;
	ListInit(&list);

	// 사원 정보 4명 등록
	SetMember(&member, "KimGamma", 1234);
	LInsert(&list, member);
	SetMember(&member, "What", 3478);
	LInsert(&list, member);
	SetMember(&member, "The", 5683);
	LInsert(&list, member);
	SetMember(&member, "Himan", 3346);
	LInsert(&list, member);


	// 사원 정보 출력
	printf("등록된 사원\n");
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

	//당직근무
	int AfterDay;
	scanf_s("%d", &AfterDay);

	SetMember(&member, "KimGamma", 1234);//오늘근무자

	member = NightWalk(&list, member, AfterDay);
	printf("%d일 후 근무자\n", AfterDay);
	ShowMemberInfo(member);

	_getch();
	return 0;
}