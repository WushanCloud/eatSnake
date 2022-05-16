#pragma once

#include <utility>
#include <vector>
#include <list>

class Snake
{
public:
	/*
	* ������ͷ
	*/ 
	void SetHead(int, int);

	/*
	* ��ȡ��ͷ
	*/
	void PutHead(int&, int&);

	/*
	* ������β
	*/ 
	void SetEnd(int, int);

	/*
	* ��ȡ��β
	*/
	void PutEnd(int&, int&);

	/*
	* ȥ����β
	*/
	void DelEnd();

	/*
	* ��ȡ�߳�
	*/
	int GetLength();

private:
	std::pair<int, int> m_head; // ͷ
	std::pair<int, int> m_end; // β

	std::list<std::pair<int, int>> m_snake;
};

