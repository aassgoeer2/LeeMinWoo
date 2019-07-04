#pragma once
#include "Block.h"
#include "MapDraw.h"

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

class Game
{
private:
	Block Map[HEIGHT][WIDTH];
	MapDraw m_Draw;
	int m_iCursorX;
	int m_iCursorY;
public:
	int FindBoom(int x, int y);
	void GameOver();
	void Block_Trigger(int x, int y);
	void Init();
	void Play();
	void Move(char ch);
	void GetBlockState(int CursorX, int CursorY);
	Game();
	~Game();
};

