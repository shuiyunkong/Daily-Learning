#define  _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu() {
	printf("****************************\n");
	printf("**********  1.play  ********\n");
	printf("**********  0.exit  ********\n");
	printf("****************************\n");
}

void Challenge() {
	printf("****************************\n");
	printf("**********  1.easy  ********\n");
	printf("**********  2.hart  ********\n");
	printf("****************************\n");
}

void game() {
	char mine[ROWS][COLS] = { 0 };//埋雷数组
	char show[ROWS][COLS] = { 0 };//展示数组
	//初始化
	//埋雷数组初始化为'0'，等下地雷为'1'
	New_board(mine,ROWS,COLS,'0');
	//埋雷
	Put_mine(mine,ROW,COL);
	//展示数组初始化为'*'
	New_board(show,ROWS,COLS,'*');
	//打印棋盘
	//Show_board(mine, ROW, COL);
	//Show_board(show, ROW, COL);

	//游戏模式选择 1.简单 2.困难
	//简单模式可以开局随机显示一片没有地雷的区域
	//困难模式开局不会显示
	Challenge();
	int input = 0;
	printf("请选择难度:>\n");
	scanf("%d", &input);
	if (input == 1)
		Easy_show(mine,show,ROW,COL);

	//开始游戏
	Play_show(mine,show,ROW,COL);


}

int main() {

	srand((unsigned int)time(NULL));

	int input = 0;

	do {
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("即将退出游戏\n");
			Sleep(1000);
			break;
		default:
			printf("输入错误，请在1或0中选择：\n");
			break;
		}
	} while (input);
	system("pause");

	return 0;
}