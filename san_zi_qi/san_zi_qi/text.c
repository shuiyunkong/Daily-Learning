#define  _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

//写一个三字棋游戏
//game.h和game.c主要是放运用的函数声明和函数的
//text.c放main函数的游戏主要执行流程的代码

void menu() {
	printf("***************************\n");
	printf("*********1.开始游戏********\n");
	printf("*********0.退出游戏********\n");
	printf("***************************\n");
}

void game() {
	char qiPan[ROW][COL] = { 0 };//三字棋的棋盘
	//初始化棋盘
	qiPan_chushihua(qiPan,ROW,COL);

	int a = 1;//执行第一次教程的参数

	while (1) {

		//开始的新手教程
		if (a == 1) {
			printf("\n请按照示例形式选择你要下的指定位置\n");
			printf("棋盘示例:\n");
			printf("  0   1   2 \n");
			printf("0   |   |   \n");
			printf(" ---|---|---\n");
			printf("1   |   |   \n");
			printf(" ---|---|---\n");
			printf("2   |   |   \n");
			printf("示例：行 列\n");
			printf("示例：1 1\n");
			a--;
		}

		//打印棋盘
		printf("\n");
		daYin(qiPan, ROW, COL);
		//开始下棋
		//玩家下的棋是*号，机器下棋用#号表示
		printf("\n");
		again://玩家坐标输入有误跳转到此
		printf("玩家请下棋(玩家棋子为*):>\n");
		
		int row = 0;//行
		int col = 0;//列
		scanf("%d %d", &row, &col);

		//判断玩家输入的坐标是否正确：1.不能越界。2.不能已经有非空格字符。
		//如果玩家输入的坐标有问题，返回1。没问题返回0。
		if (panDuan(qiPan, row, col)) {
			printf("\n下棋位置有问题，不能超出棋盘或者下到已经有棋子的位子\n");
			printf("请重新选择\n");
			goto again;
		}

		//玩家下棋的程序
		xiaQi_player(qiPan,row,col);
		//判断输赢的程序
		//可以判断输赢了返回1，不能返回0
		if (game_over(qiPan)) {
			daYin(qiPan, ROW, COL);
			break;
		}
			
		//机器下棋的程序
		xiaQi_ai(qiPan);
		//判断输赢的程序
		if (game_over(qiPan)) {
			daYin(qiPan, ROW, COL);
			break;
		}
	}

}

int main() {

	srand((unsigned int)time(NULL));//使rand生成随机数
	int input = 0;

	do {
		//菜单选项
		menu();
		//选择循环
		printf("请选择选项:>\n");
		scanf("%d", &input);
		switch (input) {
		//1代表开始游戏
		case 1:
			game();//三字棋游戏执行函数
			break;
		//0代表结束游戏
		case 0:
			printf("感谢游玩\n");
			Sleep(1000);
			printf("即将退出游戏\n");
			break;
		//1和0以外的代表选择错误，需要重新执行菜单选项，让玩家重新选择
		default:
			printf("选择错误\n");
			printf("请在1和0中选择\n");
			break;
		}
		
	} while (input);
	system("pause");
	

	return 0;
}

