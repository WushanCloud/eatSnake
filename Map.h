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
	// 生成地图
	Map(int length = 10, int width = 10);

	// 随机生成点位
	void PutPoint(int& o_length, int& o_width);

	// 设置食物点
	void SetFood(int i_length = -1, int i_width = -1);

	/*
	* 初始化蛇，让蛇有一个起点
	*/
	void initSnake();

	/*
	* 玩家移动蛇
	*/
	void PlayerMoveSnake(char diretc);

	// 设置蛇
	void SetSnake(char diretc);

	/*
	* 判断蛇的位置应该发生什么事
	* 1.当前点没有食物没有障碍，正常通行
	* 2.当前点有食物，蛇身加1
	* 3.当前点有障碍，蛇死亡，游戏结束
	*	3.1障碍点结束
	*	3.2边界结束
	*/
	bool decSnake();

	// 打印地图
	bool PrintMap();

	~Map();

private:
	int m_length;
	int m_width;

	std::vector<std::vector<char>> m_map;
	int m_maxPoint;
	int m_nowPoint;
	int m_levPoint;

	Snake m_map_snake;		// 地图上的蛇
	Snake m_player_snake;	// 玩家控制的蛇

};

