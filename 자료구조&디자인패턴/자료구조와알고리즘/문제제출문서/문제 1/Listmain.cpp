#include "ArrayList.h"
#include <stdio.h>

void main()

{
	LData Sum = 0;
	LData data = 0;
	List ArrList;
	ListInit(&ArrList);

	for (LData i = 1; i <= 9; i++)
		LInsert(&ArrList, i);

	LFirst(&ArrList, &data);
	Sum += data;
	while (LNext(&ArrList, &data))
		Sum += data;

	printf("%d\n", Sum);

	LFirst(&ArrList, &data);
	while (LNext(&ArrList, &data))
	{
		if (data % 2 == 0 || data % 3 == 0)
			LRemove(&ArrList);
	}

	LFirst(&ArrList, &data);
	printf("%d ", data);
	while (LNext(&ArrList, &data))
		printf("%d ", data);
}
