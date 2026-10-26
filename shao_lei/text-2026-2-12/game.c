#define  _CRT_SECURE_NO_WARNINGS 1

#include"game.h"


void New_board(char board[ROWS][COLS], int rows, int cols, char input) {
	int i = 0;
	for (i = 0; i < rows; i++) {
		int j = 0;
		for (j = 0; j < cols; j++) {
			board[i][j] = input;
		}
	}
}

void Show_board(char board[ROWS][COLS], int row, int col) {
	int i = 0;
	printf("--------------------------\n");
	printf("   ");
	for (i = 1; i <= col; i++) {
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++) {
		int j = 0;
		printf("%d  ", i);
		for (j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("--------------------------\n");

}

void Put_mine(char mine[ROWS][COLS], int row, int col) {
	int x = 0;
	int y = 0;
	int boom = Boom;
	while (boom) {
		x = rand() % row + 1;//生成1~9的随机数
		y = rand() % col + 1;
		if (mine[x][y] != '1') {
			mine[x][y] = '1';
			boom--;
		}
	}
	//Show_board(mine, ROW, COL);
}

char Find(char mine[ROWS][COLS], int x, int y) {
	int sum = 0;
	int i = 0;
	int j = 0;
	for (i = -1; i <= 1; i++) {
		for (j = -1; j <= 1; j++) {
			sum = sum + (mine[x + i][y + j] - '0');
		}
	}
	if (sum == 0)
		return ' ';
	else
		return sum + '0';
}

int Flag(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int i = 0;
	int count = 0;
	for (i = 1; i <= row; i++) {
		int j = 0;
		for (j = 1; j <= col; j++) {
			if ((show[i][j] == '#') && (mine[i][j] == '1'))
				count++;
		}
	}
	if (count == Boom)
		return 1;

	return 0;
}

void Easy_show(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	//首先选择一个不是地雷的随机位置，然后找周围一圈是否有地雷
	int x = 0;
	int y = 0;
	while (1) {
		x = rand() % row + 1;//生成1~9的随机数
		y = rand() % col + 1;
		if (mine[x][y] != '1')
			break;
	}
	int i = 0;
	int j = 0;
	for (i = -1; i <= 1; i++) {
		for (j = -1; j <= 1; j++) {
			if (mine[x + i][y + j] != '1') {
				show[x + i][y + j] = Find(mine, x + i, y + j);
			}
		}
	}
}

void Play_show(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {

	int x = 0;
	int y = 0;
	int a = 0;
	int win = ((row*col)-Boom);

	while (win) {
		//打印棋盘
		//Show_board(mine, ROW, COL);
		Show_board(show, ROW, COL);
		//玩家扫雷
		//插旗：0是正常扫雷，1是插旗
		printf("坐标 坐标 1或者0\n");
		printf("最后一个0是正常扫雷，1是插旗\n");
		printf("请玩家选择:>");
		scanf("%d %d %d", &x, &y,&a);
		//判断玩家的坐标的合法性
		if (a == 1 && show[x][y]=='*') {
			show[x][y] = '#';
			int flag = 0;
			int i = 0;
			for (i = 1; i <= row; i++) {
				int j = 0;
				for (j = 1; j <= col; j++) {
					if (show[i][j] == '#')
						flag++;
				}
			}
			//如果插的旗子全在地雷的上方，并且旗子数和地雷数相同，则胜利返回1，没有返回0
			if(flag==Boom)
				if (Flag(mine,show,row,col))
					win = 0;
		}
		else if (a == 0) {
			if (x >= 1 && x <= row && y >= 1 && y <= col && (show[x][y] == '*' || show[x][y] == '#')) {
				//1.如果是雷游戏结束 2.如果不是，显示出周围8格有多少雷
				//判断输赢：1.点到雷炸死  2.没有点到雷，选完所有没有地雷的地方胜利

				if (mine[x][y] == '1') {
					printf("很遗憾，你被炸死了\n");
					Show_board(mine, ROW, COL);
					break;
				}
				else {
					show[x][y] = Find(mine, x, y);
					win--;
				}
			}
			else {
				printf("前面两个坐标非法，请重新选择:>\n");
			}
		}
		else {
			printf("最后一个坐标非法，请重新选择:>\n");
		}
	
	}
	if (win == 0) {
		printf("恭喜你！获胜了！！！\n");
		printf("你的棋盘:>\n");
		Show_board(show, ROW, COL);
		printf("地雷位置:>\n");
		Show_board(mine, ROW, COL);
	}
}