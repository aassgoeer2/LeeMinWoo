#include "Block.h"



Block::Block()
{
	m_iType = NORMAL;
	m_bHidden = true;
}

void Block::Trigger()
{
	m_bHidden = false;

}


Block::~Block()
{
}
