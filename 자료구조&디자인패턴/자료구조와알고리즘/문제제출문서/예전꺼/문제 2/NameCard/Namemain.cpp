#include "NameCard.h"

void main()
{
	char Name[30];
	char Phone[30];
	NameCard *ArrayList[3];
	int NumofData = 0;

	for (int i = 0; i < 3; i++)
	{
		printf("%d��° ��� �̸� : ", i + 1);
		scanf("%s", Name);
		printf("%d��° ��� ����ȣ : ", i + 1);
		scanf("%s", Phone);
		ArrayList[i] = MakeNameCard(Name, Phone);
		NumofData++;
	}

	printf("Ž���� �̸� : ");
	scanf("%s", Name);

	for (int i = 0; i < 3; i++)
	{
		if (NameCompare(ArrayList[i], Name) == 1)
			ShowNameCardInfo(ArrayList[i]);
	}

	printf("����ȣ �ٲܻ�� �̸� : ");
	scanf("%s", Name);
	printf("�ٲ�����ȣ : ");
	scanf("%s", Phone);

	for (int i = 0; i < 3; i++)
	{
		if (NameCompare(ArrayList[i], Name) == 1)
			ChangePhoneNum(ArrayList[i], Phone);
	}

	printf("������ �̸� : ");
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