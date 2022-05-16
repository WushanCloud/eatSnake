#pragma once

#include <utility>
#include <vector>
#include <list>

class Snake
{
public:
	/*
	* 设置蛇头
	*/ 
	void SetHead(int, int);

	/*
	* 获取蛇头
	*/
	void PutHead(int&, int&);

	/*
	* 设置蛇尾
	*/ 
	void SetEnd(int, int);

	/*
	* 获取蛇尾
	*/
	void PutEnd(int&, int&);

	/*
	* 去除蛇尾
	*/
	void DelEnd();

	/*
	* 获取蛇长
	*/
	int GetLength();

private:
	std::pair<int, int> m_head; // 头
	std::pair<int, int> m_end; // 尾

	std::list<std::pair<int, int>> m_snake;
};

