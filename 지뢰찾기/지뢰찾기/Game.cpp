#include "Game.h"



Game::Game()
{
	m_iCursorX = WIDTH;
	m_iCursorY = HEIGHT / 2;
}

void Game::GameOver()
{
	m_BlockManager.AllBlockShow();
	getch();
	exit(1);
}

void Game::Init()
{
	m_BlockManager.SetBoom();

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x <= WIDTH; x++)
		{
			if (x ==  WIDTH)
				cout << "¦¢";
			else
				cout << UNKNOWNBLOCK;
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

	m_BlockManager.SetBoomNumber();
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
			m_BlockManager.GetBlockState(m_iCursorX, m_iCursorY);
			ch = getch();
			if (ch == LEFT || ch == RIGHT || ch == UP || ch == DOWN)
			{
				Move(ch);
				m_Draw.TextDraw(CURSOR, m_iCursorX, m_iCursorY);
			}
			else if (ch == SPACE)
				if (m_BlockManager.Block_Trigger(m_iCursorX / 2, m_iCursorY) == 1)
					GameOver();
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

Game::~Game()
{
}
