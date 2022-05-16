#include "Action.h"

void test()
{
	// 创造地图
	Map map(20, 20);
	// 设置食物点
	map.SetFood();
	// 初始化蛇
	map.initSnake();

	char player_move = 'a';
	bool play_continue = true;
	// 进入循环
	while (play_continue)
	{
		// 清除屏幕
		system("cls");
		// 打印地图
		map.PrintMap();
		Sleep(300);
		// 玩家移动
		if (_kbhit()) {
			player_move = _getch();
		}
		map.PlayerMoveSnake(player_move);
		// 判断玩家落点
		play_continue = map.decSnake();
	}
}
