#include "Game.h"



Game::Game()
{
	m_iCursorX = WIDTH;
	m_iCursorY = HEIGHT / 2;
	srand(time(NULL));
}

void Game::GameOver()
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
	getch();
	exit(1);
}

void Game::Block_Trigger(int x, int y)
{
	Map[y][x].Trigger();
	if (Map[y][x].GetType() == BOOM)
		GameOver();
	else if (Map[y][x].GetType() == NORMAL)
	{
		if (Map[y][x].GetCloseBoom() == 0)
			m_Draw.TextDraw(" ", x * 2, y);
		else if (Map[y][x].GetCloseBoom() >= 0)
			m_Draw.TextDraw(to_string(Map[y][x].GetCloseBoom()), x * 2, y);
	}

	if (Map[y][x].GetCloseBoom() >= 1)
		return;

	if (x < WIDTH - 1 && Map[y][x + 1].GetHidden() == true)
		Block_Trigger(x + 1, y);
	if (x > 0 && Map[y][x - 1].GetHidden() == true)
		Block_Trigger(x - 1, y);
	if (y < HEIGHT - 1 && Map[y + 1][x].GetHidden() == true)
		Block_Trigger(x, y + 1);
	if (y > 0 && Map[y - 1][x].GetHidden() == true)
		Block_Trigger(x, y - 1);
	return;
}

int Game::FindBoom(int x, int y)
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

void Game::Init()
{
	int RandX;
	int RandY;

	for (int i = 1; i <= 30; i++)
	{
		RandX = rand() % WIDTH;
		RandY = rand() % HEIGHT;
		Map[RandY][RandX].SetTypeBoom();
	}

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x <= WIDTH; x++)
		{
			if (x ==  WIDTH)
				cout << "¦¢";
			else
				cout << UNKNOWNBLOCK;
			Map[y][x].SetCloseBoomNumber(FindBoom(x, y));
		}
		cout << endl;
	}

	m_Draw.gotoxy(0, HEIGHT);
	for (int i = 0; i < WIDTH; i++)
	{
		cout << "¦¡";
	}
	cout << "¦¥" << endl;
	cout << "Trigger : Space , Move : ¡è,¡é,¡ç,¡æ" << endl;
	Play();

}

void Game::Play()
{
	char ch;
	m_Draw.TextDraw(CURSOR, m_iCursorX, m_iCursorY);

	while (TRUE)
	{
		if (kbhit())
		{
			GetBlockState(m_iCursorX, m_iCursorY);
			ch = getch();
			if (ch == LEFT || ch == RIGHT || ch == UP || ch == DOWN)
			{
				Move(ch);
				m_Draw.TextDraw(CURSOR, m_iCursorX, m_iCursorY);
			}
			else if (ch == SPACE)
				Block_Trigger(m_iCursorX / 2, m_iCursorY);
			else
				continue;
		}
	}
}

void Game::Move(char ch)
{
	if (ch == LEFT && m_iCursorX >= 2)
		m_iCursorX -= 2;
	else if (ch == RIGHT && m_iCursorX < WIDTH * 2 - 2)
		m_iCursorX += 2;
	else if (ch == UP && m_iCursorY >= 1)
		m_iCursorY -= 1;
	else if (ch == DOWN && m_iCursorY < HEIGHT - 1)
		m_iCursorY += 1;
	else
		return;
}

void Game::GetBlockState(int CursorX, int CursorY)
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

Game::~Game()
{
}
