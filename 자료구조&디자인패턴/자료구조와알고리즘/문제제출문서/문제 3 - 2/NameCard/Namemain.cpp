#include "NameCard.h"
#define TRUE 1
#define MAXNAMECARD 100

void main()
{
	int Select;
	int Index = 0;
	char Name[NAME_LEN];
	char Phone[PHONE_LEN];
	NameCard *ArrayList[MAXNAMECARD];
	int NumofData = 0;
	int NumofDataInit;

	while (TRUE)
	{
		if (NumofData == 100)
		{
			printf("�ִ� ���� �����\n");
			break;
		}
		printf("����  : 1 , �׸����� : 2\n");
		scanf("%d", &Select);
		if (Select == 2)
		{ 
			if (NumofData == 0)
				return;
			break;
		}
		printf("%d��° ��� �̸� : ", Index + 1);
		scanf("%s", Name);
		printf("%d��° ��� ����ȣ : ", Index + 1);
		scanf("%s", Phone);
		ArrayList[Index] = MakeNameCard(Name, Phone);
		Index++;
		NumofData++;
	}

	NumofDataInit = NumofData;

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


	for (int i = 0; i < NumofDataInit; i++)
		delete  ArrayList[i];
	return;
}