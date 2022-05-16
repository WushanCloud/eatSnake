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
		// ������Ϸ
		return;
	}
	srand((unsigned)time(NULL)); //��ʼ�������
put_point:
	o_length = rand() % m_length;
	o_width = rand() % m_width;

	// �жϵ�ǰ���ɵ���û�г�ͻ
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
	// �����β��ʧ
	m_player_snake.DelEnd();
}

void Map::SetSnake(char diretc)
{
	
}

bool Map::decSnake()
{
	// �жϵ�ǰ��λ�ã��õ�����ߵ���
	int s_head_l = 0;
	int s_head_w = 0;
	m_player_snake.PutHead(s_head_l, s_head_w);

	// �õ���ͼ����
	int s_head_l_2 = 0;
	int s_head_w_2 = 0;
	m_map_snake.PutHead(s_head_l_2, s_head_w_2);

	// ��ǰ�����ͼ�߽�
	if (s_head_l >= m_length || s_head_w >= m_width)
	{
		return false;
	}
	// ��ͼ�жϵ�ǰ���ϰ�ͨ��
	else if (m_map[s_head_l][s_head_w] == MAP_POINT) 
	{
		// ��ͼ���Ϊ��ͷ
		m_map[s_head_l][s_head_w] = SNAKE_HEAD;
		if (m_player_snake.GetLength() != 1) {
			// ԭ��ͷ��Ϊ����
			m_map[s_head_l_2][s_head_w_2] = SNAKE_BODY;
		}
		else {
			// ԭ��ͷ��Ϊ��ͼ
			m_map[s_head_l_2][s_head_w_2] = MAP_POINT;
		}
		
		// ���µ�ͼ��ͷ
		m_map_snake.SetHead(s_head_l, s_head_w);


		// ��ͼ��β��ʧ

		// ���õ���ͼ��β
		int s_end_l = 0;
		int s_end_w = 0;
		m_map_snake.PutEnd(s_end_l, s_end_w);
		// ��ͼ��ʶ��β��ʧ
		m_map[s_end_l][s_end_w] = MAP_POINT;
		// ��ͼ��β��ʧ
		m_map_snake.DelEnd();

		return true;
	}
	// ��ͼ�жϵ�ǰ��ʳ��
	else if (m_map[s_head_l][s_head_w] == MAP_FOOD)
	{
		// ��ͼ���Ϊ��ͷ
		m_map[s_head_l][s_head_w] = SNAKE_HEAD;
		// ԭ��ͷ��Ϊ����
		m_map[s_head_l_2][s_head_w_2] = SNAKE_BODY;
		// ���µ�ͼ��ͷ
		m_map_snake.SetHead(s_head_l, s_head_w);
		// ��ͼ��β����ʧ������ʳ��
		// ����߳���+1
		int s_end_l = 0;
		int s_end_w = 0;
		m_map_snake.PutEnd(s_end_l, s_end_w);
		m_player_snake.SetEnd(s_end_l, s_end_w);
		SetFood();
		return true;
	}
	// ����
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
