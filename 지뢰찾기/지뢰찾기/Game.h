#pragma once
#include "BlockManager.h"
#include "MapDraw.h"

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

class Game
{
private:
	BlockManager m_BlockManager;
	MapDraw m_Draw;
	int m_iCursorX;
	int m_iCursorY;
public:
	void GameOver();
	void Init();
	void Play();
	void Move(char ch);
	Game();
	~Game();
};

