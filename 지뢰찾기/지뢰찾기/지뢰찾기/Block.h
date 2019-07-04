#pragma once
#include "MapDraw.h"

#define UNKNOWNBLOCK "¢Ì"
#define CURSOR "¡à"
#define BOOMSHAPE "¢Í"

#define NORMAL 1
#define BOOM 2

class Block
{
private:
	int m_iX;
	int m_iY;
	int m_iType;
	int m_iCloseBoomNumber;
	bool m_bHidden;
public:
	inline void SetTypeBoom()
	{
		m_iType = BOOM;
	}
	inline int GetType()
	{
		return m_iType;
	}
	inline bool GetHidden()
	{
		return m_bHidden;
	}
	inline void SetCloseBoomNumber(int Number)
	{
		m_iCloseBoomNumber = Number;
	}
	inline int GetCloseBoom()
	{
		return m_iCloseBoomNumber;
	}
	void Trigger();
	Block();
	~Block();
};

