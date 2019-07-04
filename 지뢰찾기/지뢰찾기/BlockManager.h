#pragma once
#include "Block.h"
#include "MapDraw.h"

class BlockManager
{
private:
	MapDraw m_Draw;
	Block Map[HEIGHT][WIDTH];
public:
	void AllBlockShow();
	int FindBoom(int x, int y);
	bool Block_Trigger(int x, int y);
	void GetBlockState(int CursorX, int CursorY);
	void SetBoom();
	void SetBoomNumber();
	BlockManager();
	~BlockManager();
};

