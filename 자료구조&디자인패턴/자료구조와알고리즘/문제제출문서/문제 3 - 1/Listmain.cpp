#include "ArrayList.h"
#include <stdio.h>

void main()

{
	LData Sum = 0;
	LData data = 0;
	List ArrList;
	ListInit(&ArrList);

	for (LData i = 1; i <= 100; i++)
		LInsert(&ArrList, i);

	LFirst(&ArrList, &data);
	Sum += data;
	while (LNext(&ArrList, &data))
		Sum += data;

	printf("%d\n", Sum);

	int Count = 0;
	LFirst(&ArrList, &data);
	while (LNext(&ArrList, &data))
	{
		Count = 0;
		for (int i = 1; i <= data; i++)
		{
			if (data % i == 0)
				Count++;
		}
		if (Count > 2)
			LRemove(&ArrList);
	}

	LFirst(&ArrList, &data);
	printf("%d ", data);
	while (LNext(&ArrList, &data))
		printf("%d ", data);
}
