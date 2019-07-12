#include "NameCard.h"

NameCard * MakeNameCard(char * name, char * phone)
{

	NameCard *Card = new NameCard;
	for (int i = 0; i < 30; i++)
	{
		Card->name[i] = name[i];
		Card->phone[i] = phone[i];
	}

	return Card;
}

void ShowNameCardInfo(NameCard * pcard)
{
	printf("이름 : %s\n", pcard->name);
	printf("폰번호 : %s\n", pcard->phone);
}

int NameCompare(NameCard * pcard, char * name)
{
	for (int i = 0; i < PHONE_LEN; i++)
	{
		if (pcard->name[i] != name[i])
			return 0;
	}
	return 1;
}

void ChangePhoneNum(NameCard * pcard, char * phone)
{
	for (int i = 0; i < 30; i++)
	{
		pcard->phone[i] = phone[i];
	}
}
