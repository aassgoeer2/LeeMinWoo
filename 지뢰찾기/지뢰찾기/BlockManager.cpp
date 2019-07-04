#include "BlockManager.h"



BlockManager::BlockManager()
{
	srand(time(NULL));
}

void BlockManager::AllBlockShow()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (Map[y][x].GetType() == BOOM)
				m_Draw.TextDraw(BOOMSHAPE, x * 2, y);
			else if (Map[y][x].GetType() == NORMAL)
			{
				if (Map[y][x].GetCloseBoom() == 0)
					m_Draw.TextDraw(" ", x * 2, y);
				else if (Map[y][x].GetCloseBoom() >= 0)
					m_Draw.TextDraw(to_string(Map[y][x].GetCloseBoom()), x * 2, y);
			}
		}
	}
}

bool BlockManager::Block_Trigger(int x, int y)
{
	Map[y][x].Trigger();
	if (Map[y][x].GetType() == BOOM)
		return 1;
	else if (Map[y][x].GetType() == NORMAL)
	{
		if (Map[y][x].GetCloseBoom() == 0)
			m_Draw.TextDraw(" ", x * 2, y);
		else if (Map[y][x].GetCloseBoom() >= 0)
			m_Draw.TextDraw(to_string(Map[y][x].GetCloseBoom()), x * 2, y);
	}

	if (Map[y][x].GetCloseBoom() >= 1)
		return false;

	if (x < WIDTH - 1 && Map[y][x + 1].GetHidden() == true)
		Block_Trigger(x + 1, y);
	if (x > 0 && Map[y][x - 1].GetHidden() == true)
		Block_Trigger(x - 1, y);
	if (y < HEIGHT - 1 && Map[y + 1][x].GetHidden() == true)
		Block_Trigger(x, y + 1);
	if (y > 0 && Map[y - 1][x].GetHidden() == true)
		Block_Trigger(x, y - 1);
	return false;
}

void BlockManager::SetBoom()
{
	int RandX;
	int RandY;

	for (int i = 1; i <= 30; i++)
	{
		RandX = rand() % WIDTH;
		RandY = rand() % HEIGHT;
		Map[RandY][RandX].SetTypeBoom();
	}
}

void BlockManager::SetBoomNumber()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			Map[y][x].SetCloseBoomNumber(FindBoom(x, y));
		}
	}
}

int BlockManager::FindBoom(int x, int y)
{
	int Count = 0;
	if (x < WIDTH - 1)
	{
		if (y - 1 >= 0)
			if (Map[y - 1][x + 1].GetType() == BOOM)
				Count++;
		if (Map[y][x + 1].GetType() == BOOM)
			Count++;
		if (y + 1 <= HEIGHT - 1)
			if (Map[y + 1][x + 1].GetType() == BOOM)
				Count++;
	}
	if (x > 0)
	{
		if (y - 1 >= 0)
			if (Map[y - 1][x - 1].GetType() == BOOM)
				Count++;
		if (Map[y][x - 1].GetType() == BOOM)
			Count++;
		if (y + 1 <= HEIGHT - 1)
			if (Map[y + 1][x - 1].GetType() == BOOM)
				Count++;
	}
	if (y - 1 >= 0)
		if (Map[y - 1][x].GetType() == BOOM)
			Count++;
	if (y + 1 <= HEIGHT - 1)
		if (Map[y + 1][x].GetType() == BOOM)
			Count++;
	if (Map[y][x].GetType() == BOOM)
		Count++;

	return Count;
}

void BlockManager::GetBlockState(int CursorX, int CursorY)
{
	if (Map[CursorY][CursorX / 2].GetHidden() == true)
		m_Draw.TextDraw(UNKNOWNBLOCK, CursorX, CursorY);
	else if (Map[CursorY][CursorX / 2].GetHidden() == false)
	{
		if (Map[CursorY][CursorX / 2].GetType() == BOOM)
			m_Draw.TextDraw(BOOMSHAPE, CursorX, CursorY);
		else if (Map[CursorY][CursorX / 2].GetType() == NORMAL)
		{
			if (Map[CursorY][CursorX / 2].GetCloseBoom() == 0)
				m_Draw.TextDraw(" ", CursorX, CursorY);
			else if (Map[CursorY][CursorX / 2].GetCloseBoom() >= 1)
				m_Draw.TextDraw(to_string(Map[CursorY][CursorX / 2].GetCloseBoom()), CursorX, CursorY);
		}
	}
}

BlockManager::~BlockManager()
{
}
