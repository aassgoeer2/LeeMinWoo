#include "NameCard.h"

void main()
{
	char Name[30];
	char Phone[30];
	NameCard *ArrayList[3];
	int NumofData = 0;

	for (int i = 0; i < 3; i++)
	{
		printf("%d번째 사람 이름 : ", i + 1);
		scanf("%s", Name);
		printf("%d번째 사람 폰번호 : ", i + 1);
		scanf("%s", Phone);
		ArrayList[i] = MakeNameCard(Name, Phone);
		NumofData++;
	}

	printf("탐색할 이름 : ");
	scanf("%s", Name);

	for (int i = 0; i < 3; i++)
	{
		if (NameCompare(ArrayList[i], Name) == 1)
			ShowNameCardInfo(ArrayList[i]);
	}

	printf("폰번호 바꿀사람 이름 : ");
	scanf("%s", Name);
	printf("바꿀폰번호 : ");
	scanf("%s", Phone);

	for (int i = 0; i < 3; i++)
	{
		if (NameCompare(ArrayList[i], Name) == 1)
			ChangePhoneNum(ArrayList[i], Phone);
	}

	printf("삭제할 이름 : ");
	scanf("%s", Name);

	for (int i = 0; i < NumofData; i++)
	{
		if (NameCompare(ArrayList[i], Name) == 1)
		{
			NumofData--;
			if (i == NumofData)
				break;
			for (int j = i; j < NumofData; j++)
				ArrayList[j] = ArrayList[j + 1];
		}
	}

	for (int i = 0; i < NumofData; i++)
	{
		printf("%s : ", ArrayList[i]->name);
		printf("%s\n", ArrayList[i]->phone);
	}


	for (int i = 0; i < NumofData; i++)
		delete  ArrayList[i];
	return;
}