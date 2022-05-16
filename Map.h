#pragma once

#include <vector>
#include <iostream>
#include <cmath>
#include <ctime>

#include "Snake.h"

#define MAP_POINT	' '
#define MAP_FOOD	'*'
#define SNAKE_HEAD	'@'
#define SNAKE_BODY	'o'

class Map
{
public:
	// ���ɵ�ͼ
	Map(int length = 10, int width = 10);

	// ������ɵ�λ
	void PutPoint(int& o_length, int& o_width);

	// ����ʳ���
	void SetFood(int i_length = -1, int i_width = -1);

	/*
	* ��ʼ���ߣ�������һ�����
	*/
	void initSnake();

	/*
	* ����ƶ���
	*/
	void PlayerMoveSnake(char diretc);

	// ������
	void SetSnake(char diretc);

	/*
	* �ж��ߵ�λ��Ӧ�÷���ʲô��
	* 1.��ǰ��û��ʳ��û���ϰ�������ͨ��
	* 2.��ǰ����ʳ������1
	* 3.��ǰ�����ϰ�������������Ϸ����
	*	3.1�ϰ������
	*	3.2�߽����
	*/
	bool decSnake();

	// ��ӡ��ͼ
	bool PrintMap();

	~Map();

private:
	int m_length;
	int m_width;

	std::vector<std::vector<char>> m_map;
	int m_maxPoint;
	int m_nowPoint;
	int m_levPoint;

	Snake m_map_snake;		// ��ͼ�ϵ���
	Snake m_player_snake;	// ��ҿ��Ƶ���

};

