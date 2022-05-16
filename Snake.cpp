#include "Snake.h"

void Snake::SetHead(int i_length, int i_width)
{
	m_head.first = i_length;
	m_head.second = i_width;

	m_snake.push_front(m_head);
}

void Snake::PutHead(int& o_length, int& o_width)
{
	o_length = m_head.first;
	o_width = m_head.second;
}

void Snake::SetEnd(int i_length, int i_width)
{
	m_end.first = i_length;
	m_end.second = i_width;

	m_snake.push_back(m_end);
}

void Snake::PutEnd(int& o_length, int& o_width)
{
	o_length = m_end.first;
	o_width = m_end.second;
}

void Snake::DelEnd()
{
	if (m_snake.size() == 1) {
		return;
	}
	m_snake.pop_back();
	m_end = m_snake.back();
}

int Snake::GetLength()
{
	return m_snake.size();
}
