#include "Member.h"
#include <stdio.h>

void ShowMemberInfo(Member member)
{
	printf("[ %s : %d]\n", member.name, member.Number);
}

void SetMember(Member *member, char *name, int Number)
{
	for (int i = 0; i < NAMELEN; i++)
	{
		member->name[i] = name[i];
	}
	member->Number = Number;
}

int MemberComp(Member m1, Member m2)
{
	if (m1.Number != m2.Number)
		return 0;
	else
	{
		for (int i = 0; i < NAMELEN; i++)
		{
			if (m1.name[i] != m2.name[i])
				return 0;
		}
	}
	return 1;
}
