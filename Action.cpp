#include "Action.h"

void test()
{
	// �����ͼ
	Map map(20, 20);
	// ����ʳ���
	map.SetFood();
	// ��ʼ����
	map.initSnake();

	char player_move = 'a';
	bool play_continue = true;
	// ����ѭ��
	while (play_continue)
	{
		// �����Ļ
		system("cls");
		// ��ӡ��ͼ
		map.PrintMap();
		Sleep(300);
		// ����ƶ�
		if (_kbhit()) {
			player_move = _getch();
		}
		map.PlayerMoveSnake(player_move);
		// �ж�������
		play_continue = map.decSnake();
	}
}
