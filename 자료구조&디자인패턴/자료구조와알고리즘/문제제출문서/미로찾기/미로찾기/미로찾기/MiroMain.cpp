#include "Miro.h"

#define MOVEABLEWALL 30
#define MOVEALBLEMAX 10
#define GOAL 3
#define WALL 1
#define NULL 0
#define Y 1
#define X 0
#define CHARACTER 2
#define POTAL_MAX 10
#define ENTRY_POTAL 10
#define EXIT_POTAL 20
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define WIDTH 20
#define HEIGHT 20

vector <int> map = { 
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26, 1, 24, 1,
1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
1, 0, 1, 14, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 11, 1,
1, 0, 1, 0, 1, 25, 1, 15, 0, 0, 0, 0, 0, 23, 1, 0, 0, 1, 1, 1,
1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 21, 1,
1, 0, 1, 0, 1, 0, 1, 0, 0, 16, 1, 13, 0, 0, 0, 0, 0, 1, 0, 1,
1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 32, 1, 0, 0, 0, 1, 1, 0, 1,
1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 31, 3,
1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 33, 1, 0, 0, 0, 1, 1, 0, 1,
1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 10, 0, 1, 1,
1, 0, 1, 0, 0, 30, 0, 1, 0, 1, 0, 0, 0, 0, 0, 29, 1, 0, 0, 1,
1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1,
1, 0, 1, 0, 1, 0, 0, 34, 0, 1, 39, 0, 0, 0, 1, 0, 1, 0, 0, 1,
1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1,
1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 37, 0, 19, 1,
1, 0, 1, 0, 0, 1, 0, 35, 0, 1, 20, 0, 0, 38, 0, 0, 1, 0, 1, 1,
1, 27, 1, 0, 17, 1, 0, 36, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 28, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };


void Init()
{
	int width = (WIDTH * 2) + 1;
	int height = HEIGHT + 3;
	char buf[1024];
	sprintf(buf, "mode con: lines=%d cols=%d", height, width);
	system(buf);

	int LineCount = 0;
	for (vector<int>::iterator iter = map.begin(); iter != map.end(); iter++)
	{
		if (*iter == WALL)
			printf("▩");
		else if (*iter == CHARACTER)
			printf("♤");
		else if (*iter >= ENTRY_POTAL && *iter < ENTRY_POTAL + POTAL_MAX)
			printf("◎");
		else if (*iter >= EXIT_POTAL && *iter < EXIT_POTAL + POTAL_MAX)
			printf("●");
		else if (*iter == NULL)
			printf("  ");
		else if (*iter == GOAL)
			printf("☞");
		else if (*iter >= MOVEABLEWALL && *iter < MOVEABLEWALL + MOVEALBLEMAX)
			printf("□");

		LineCount++;
		if (LineCount >= WIDTH)
		{
			printf("\n");
			LineCount = 0;
		}
	}

	BLUE printf("입구포탈 : ◎\t");
	YELLOW printf("출구 포탈 : ● \n");
	GREEN printf("밀어지는 벽 : □\t");
	ORIGINAL

	getch();

}


void main()

{
	Init();

}
