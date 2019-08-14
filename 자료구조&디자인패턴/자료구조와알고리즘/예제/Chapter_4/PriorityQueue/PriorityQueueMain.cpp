#include <stdio.h>
#include <string>
#include <conio.h>
#include "PriorityQueue.h"

int DataPriorityComp(char * ch1, char * ch2)
{

	return strlen(ch2) - strlen(ch1);
}

int main(void)
{
	PQueue pq;
	HData str;
	char str1[] = "What";
	char str2[] = "The";
	char str3[] = "Hello";
	char str4[] = "Hi";
	PQueueInit(&pq, DataPriorityComp);

	str = str1;
	PEnqueue(&pq, str);
	str = str2;
	PEnqueue(&pq, str);
	str = str3;
	PEnqueue(&pq, str);
	str = str4;
	PEnqueue(&pq, str);


	while (!PQIsEmpty(&pq))
		printf("%s \n", PDequeue(&pq));


	_getch();
	return 0;
}
