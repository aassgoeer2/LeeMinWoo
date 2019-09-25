#include <stdio.h>
#include <conio.h>
#include <Windows.h>

#define col GetStdHandle(STD_OUTPUT_HANDLE)
#define BLACK SetConsoleTextAttribute( col,0x0000 );
#define DARK_BLUE SetConsoleTextAttribute( col,0x0001 );
#define GREEN SetConsoleTextAttribute( col,0x0002 );
#define BLUE_GREEN SetConsoleTextAttribute( col,0x0003 );
#define BLOOD SetConsoleTextAttribute( col,0x0004 );
#define PUPPLE SetConsoleTextAttribute( col,0x0005 );
#define GOLD SetConsoleTextAttribute( col,0x0006 );	
#define ORIGINAL SetConsoleTextAttribute( col,0x0007 );
#define GRAY SetConsoleTextAttribute( col,0x0008 );
#define BLUE SetConsoleTextAttribute( col,0x0009 );
#define HIGH_GREEN SetConsoleTextAttribute( col,0x000a );
#define SKY_BLUE SetConsoleTextAttribute( col,0x000b );
#define RED SetConsoleTextAttribute( col,0x000c );
#define PLUM SetConsoleTextAttribute( col,0x000d );
#define YELLOW SetConsoleTextAttribute( col,0x000e );

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

int map[HEIGHT][WIDTH] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26, 1, 24, 1 },
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 14, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 11, 1 },
	{ 1, 0, 1, 0, 1, 25, 1, 15, 0, 0, 0, 0, 0, 23, 1, 0, 0, 1, 1, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 21, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 0, 16, 1, 13, 0, 0, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 32, 1, 0, 0, 0, 1, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 31, 3 },
	{ 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 33, 1, 0, 0, 0, 1, 1, 0, 1 },
	{ 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 10, 0, 1, 1 },
	{ 1, 0, 1, 0, 0, 30, 0, 1, 0, 1, 0, 0, 0, 0, 0, 29, 1, 0, 0, 1 },
	{ 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 0, 34, 0, 1, 39, 0, 0, 0, 1, 0, 1, 0, 0, 1 },
	{ 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1 },
	{ 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 37, 0, 19, 1 },
	{ 1, 0, 1, 0, 0, 1, 0, 35, 0, 1, 20, 0, 0, 38, 0, 0, 1, 0, 1, 1 },
	{ 1, 27, 1, 0, 17, 1, 0, 36, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 28, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, };

int character[2];
int Entry_Potal[POTAL_MAX][2];
int Exit_Potal[POTAL_MAX][2];
int Moveable_Wall[MOVEALBLEMAX][2];
int Goal[2];
int a = 0;

int Find_Entry(int x, int y)
{
	for (int i = 0; i < POTAL_MAX; i++)
	{
		if (Entry_Potal[i][X] == x && Entry_Potal[i][Y] == y)
			return i;

	}
	return -1;
}

int Find_Exit(int x, int y)
{
	for (int i = 0; i < POTAL_MAX; i++)
	{
		if (Exit_Potal[i][X] == x && Exit_Potal[i][Y] == y)
			return i;

	}
	return -1;
}

int Find_Move(int x, int y)
{
	for (int i = 0; i < MOVEALBLEMAX; i++)
	{
		if (Moveable_Wall[i][X] == x && Moveable_Wall[i][Y] == y)
			return i;

	}
	return -1;
}

int Find_Goal(int x, int y)
{
	if (Goal[X] == x && Goal[Y] == y)
		return 1;
}

void Init()
{
	int width = (WIDTH * 2) + 1;
	int height = HEIGHT + 3;
	char buf[1024];
	sprintf(buf, "mode con: lines=%d cols=%d", height, width);
	system(buf);

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == CHARACTER)
			{
				character[Y] = y;
				character[X] = x;
			}
			else if (map[y][x] >= ENTRY_POTAL && map[y][x] < ENTRY_POTAL + POTAL_MAX)
			{
				Entry_Potal[map[y][x] - ENTRY_POTAL][Y] = y;
				Entry_Potal[map[y][x] - ENTRY_POTAL][X] = x;
			}
			else if (map[y][x] >= EXIT_POTAL && map[y][x] < EXIT_POTAL + POTAL_MAX)
			{
				Exit_Potal[map[y][x] - EXIT_POTAL][Y] = y;
				Exit_Potal[map[y][x] - EXIT_POTAL][X] = x;
			}
			else if (map[y][x] >= MOVEABLEWALL && map[y][x] < MOVEABLEWALL + MOVEALBLEMAX)
			{
				Moveable_Wall[map[y][x] - MOVEABLEWALL][Y] = y;
				Moveable_Wall[map[y][x] - MOVEABLEWALL][X] = x;
			}
			else if (map[y][x] == GOAL)
			{
				Goal[X] = x;
				Goal[Y] = y;
			}
		}
	}
}

void MapDraw()

{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == WALL)
			{

				printf("▩");

			}
			else if (map[y][x] == CHARACTER)
			{
				RED
					printf("♤");
				ORIGINAL
			}
			else if (map[y][x] == GOAL)
			{
				printf("☞");
			}
			else if (Find_Move(x, y) != -1)
			{
				GREEN
					printf("□");
				ORIGINAL
			}
			else if (Find_Entry(x, y) != -1)
			{
				BLUE
					printf("◎");
				ORIGINAL
			}
			else if (Find_Exit(x, y) != -1)
			{
				YELLOW
					printf("●");
				ORIGINAL
			}
			else if (map[y][x] == NULL)
				printf("  ");
		}
		printf("\n");
	}
	BLUE printf("입구포탈 : ◎\t");
	YELLOW printf("출구 포탈 : ● \n");
	GREEN printf("밀어지는 벽 : □\t");
	ORIGINAL

}

void MoveCheck()
{
	int index = Find_Entry(character[X], character[Y]);
	if (index != -1)
	{
		character[X] = Exit_Potal[index][X];
		character[Y] = Exit_Potal[index][Y];
	}

}

void Move()
{
	char ch;
	ch = getch();
	system("cls");
	map[character[Y]][character[X]] = NULL;
	switch (ch)
	{
	case LEFT:
		if (map[character[Y]][character[X] - 1] != WALL && map[character[Y]][character[X] - 1] < MOVEABLEWALL)
			character[X]--;
		else if (map[character[Y]][character[X] - 1] >= MOVEABLEWALL && map[character[Y]][character[X] - 2] != WALL)
		{
			for (int i = 0; i < MOVEALBLEMAX; i++)
			{
				if (MOVEABLEWALL + i == map[character[Y]][character[X] - 1])
				{
					map[character[Y]][character[X] - 1] = NULL;
					map[character[Y]][character[X] - 2] = MOVEABLEWALL + i;
					Moveable_Wall[i][X]--;
					character[X]--;
					a++;
				}

			}
		}
		break;

	case RIGHT:
		if (map[character[Y]][character[X] + 1] != WALL && map[character[Y]][character[X] + 1] < MOVEABLEWALL)
			character[X]++;
		else if (map[character[Y]][character[X] + 1] >= MOVEABLEWALL && map[character[Y]][character[X] + 2] != WALL)
		{
			for (int i = 0; i < MOVEALBLEMAX; i++)
			{
				if (MOVEABLEWALL + i == map[character[Y]][character[X] + 1])
				{
					map[character[Y]][character[X] + 1] = NULL;
					map[character[Y]][character[X] + 2] = MOVEABLEWALL + i;
					Moveable_Wall[i][X]++;
					character[X]++;
					a++;
				}

			}
		}
		break;
	case UP:
		if (map[character[Y] - 1][character[X]] != WALL && map[character[Y] - 1][character[X]] < MOVEABLEWALL)
			character[Y]--;
		else if (map[character[Y] - 1][character[X]] >= MOVEABLEWALL && map[character[Y] - 2][character[X]] != WALL)
		{
			for (int i = 0; i < MOVEALBLEMAX; i++)
			{
				if (MOVEABLEWALL + i == map[character[Y] - 1][character[X]])
				{
					map[character[Y] - 1][character[X]] = NULL;
					map[character[Y] - 2][character[X]] = MOVEABLEWALL + i;
					Moveable_Wall[i][Y]--;
					character[Y]--;
					a++;
				}

			}
		}
		break;
	case DOWN:
		if (map[character[Y] + 1][character[X]] != WALL && map[character[Y] + 1][character[X]] < MOVEABLEWALL)
			character[Y]++;
		else if (map[character[Y] + 1][character[X]] >= MOVEABLEWALL && map[character[Y] + 2][character[X]] != WALL)
		{
			for (int i = 0; i < MOVEALBLEMAX; i++)
			{
				if (MOVEABLEWALL + i == map[character[Y] + 1][character[X]])
				{
					map[character[Y] + 1][character[X]] = NULL;
					map[character[Y] + 2][character[X]] = MOVEABLEWALL + i;
					Moveable_Wall[i][Y]++;
					character[Y]++;
					a++;
				}

			}
		}
		break;
	}

	MoveCheck();
	map[character[Y]][character[X]] = CHARACTER;

}

void main()

{
	Init();

	while (1)
	{
		if (Find_Goal(character[X], character[Y]) == 1)
			return;
		MapDraw();
		Move();

	}
}
