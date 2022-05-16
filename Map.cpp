#include "Map.h"

Map::Map(int length, int width) : m_length(length), m_width(width)
{
	m_map.resize(m_length);
	for (size_t i = 0; i < m_length; i++)
	{
		m_map[i].resize(m_width, MAP_POINT);
	}

	m_maxPoint = m_length * m_width;
	m_levPoint = m_maxPoint;
	m_nowPoint = 0;
}

void Map::PutPoint(int& o_length, int& o_width)
{
	if (m_levPoint <= 0) {
		// 结束游戏
		return;
	}
	srand((unsigned)time(NULL)); //初始化随机数
put_point:
	o_length = rand() % m_length;
	o_width = rand() % m_width;

	// 判断当前生成点有没有冲突
	if (m_map[o_length][o_width] != MAP_POINT) {
		goto put_point;
	}
}



void Map::SetFood(int i_length, int i_width)
{
	if (i_length == -1 || i_width == -1) {
		PutPoint(i_length, i_width);
	}
	m_map[i_length][i_width] = MAP_FOOD;
}

void Map::initSnake()
{
	int o_length = 0;
	int o_width = 0;
	PutPoint(o_length, o_width);

	m_map_snake.SetHead(o_length, o_width);

	m_player_snake.SetHead(o_length, o_width);

	m_map[o_length][o_width] = SNAKE_HEAD;
}

void Map::PlayerMoveSnake(char diretc)
{
	int s_head_l = 0;
	int s_head_w = 0;
	m_player_snake.PutHead(s_head_l, s_head_w);

	switch (diretc)
	{
	case 'w':
		s_head_l--;
		break;
	case 'a':
		s_head_w--;
		break;
	case 's':
		s_head_l++;
		break;
	case 'd':
		s_head_w++;
		break;
	default:
		break;
	}
	m_player_snake.SetHead(s_head_l, s_head_w);
	// 玩家蛇尾消失
	m_player_snake.DelEnd();
}

void Map::SetSnake(char diretc)
{
	
}

bool Map::decSnake()
{
	// 判断当前蛇位置，拿到玩家走的蛇
	int s_head_l = 0;
	int s_head_w = 0;
	m_player_snake.PutHead(s_head_l, s_head_w);

	// 拿到地图的蛇
	int s_head_l_2 = 0;
	int s_head_w_2 = 0;
	m_map_snake.PutHead(s_head_l_2, s_head_w_2);

	// 当前到达地图边界
	if (s_head_l >= m_length || s_head_w >= m_width)
	{
		return false;
	}
	// 地图判断当前无障碍通行
	else if (m_map[s_head_l][s_head_w] == MAP_POINT) 
	{
		// 地图点变为蛇头
		m_map[s_head_l][s_head_w] = SNAKE_HEAD;
		if (m_player_snake.GetLength() != 1) {
			// 原蛇头变为蛇身
			m_map[s_head_l_2][s_head_w_2] = SNAKE_BODY;
		}
		else {
			// 原蛇头变为地图
			m_map[s_head_l_2][s_head_w_2] = MAP_POINT;
		}
		
		// 更新地图蛇头
		m_map_snake.SetHead(s_head_l, s_head_w);


		// 地图蛇尾消失

		// 先拿到地图蛇尾
		int s_end_l = 0;
		int s_end_w = 0;
		m_map_snake.PutEnd(s_end_l, s_end_w);
		// 地图标识蛇尾消失
		m_map[s_end_l][s_end_w] = MAP_POINT;
		// 地图蛇尾消失
		m_map_snake.DelEnd();

		return true;
	}
	// 地图判断当前有食物
	else if (m_map[s_head_l][s_head_w] == MAP_FOOD)
	{
		// 地图点变为蛇头
		m_map[s_head_l][s_head_w] = SNAKE_HEAD;
		// 原蛇头变为蛇身
		m_map[s_head_l_2][s_head_w_2] = SNAKE_BODY;
		// 更新地图蛇头
		m_map_snake.SetHead(s_head_l, s_head_w);
		// 地图蛇尾不消失，更新食物
		// 玩家蛇长度+1
		int s_end_l = 0;
		int s_end_w = 0;
		m_map_snake.PutEnd(s_end_l, s_end_w);
		m_player_snake.SetEnd(s_end_l, s_end_w);
		SetFood();
		return true;
	}
	// 结束
	else
	{
		return false;
	}
}

bool Map::PrintMap()
{
	std::cout << " ";
	for (size_t i = 0; i < m_width; i++)
	{
		std::cout << "--";
	}
	std::cout << std::endl;
	for (size_t i = 0; i < m_length; i++)
	{
		std::cout << "|";
		for (size_t j = 0; j < m_width; j++)
		{
			std::cout << m_map[i][j] << " ";
		}
		std::cout << "|" << std::endl;
	}
	std::cout << " ";
	for (size_t i = 0; i < m_width; i++)
	{
		std::cout << "--";
	}
	return true;
}

Map::~Map()
{
}
