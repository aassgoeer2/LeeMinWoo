#pragma once
#define NAMELEN 20

typedef struct member_
{
	char name[NAMELEN];
	int Number;
}Member;

void ShowMemberInfo(Member m);
void SetMember(Member *member, char *name, int Number);
int MemberComp(Member m1, Member m2);
