#define  _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

//初始化棋盘
void qiPan_chushihua(char arr[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			arr[i][j] = ' ';
		}
	}
}

//打印棋盘
//输出样式：
//   |   |   
//---|---|---
//   |   |   
//---|---|---
//   |   |
void daYin(char arr[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++) {
		int j1 = 0;
		for (j1 = 0; j1 < col; j1++) {
			printf(" %c ", arr[i][j1]);
			if (j1 < col - 1)
				printf("|");
		}
		printf("\n");

		if (i < row - 1) {
			int j2 = 0;
			for (j2 = 0; j2 < col; j2++) {
				printf("---");
				if (j2 < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

//判断玩家坐标是否正确
int panDuan(char arr[ROW][COL], int row, int col) {
	//判断是否越界
	if (row < 0 || row >= ROW || col < 0 || col >= COL) {
		return 1;
	}
	//判断是否下在有棋子的地方
	if ((arr[row][col]=='*')||(arr[row][col]=='#')) {
		return 1;
	}
	return 0;
}

//玩家下棋
void xiaQi_player(char arr[ROW][COL], int row, int col) {
	arr[row][col] = '*';
}

//机器下棋
void xiaQi_ai(char arr[ROW][COL]) {
	//随机生成坐标
	int a = 1;
	int x = 0;
	int y = 0;
	while (a) {
		x = rand() % ROW;//行
		y = rand() % COL;//列
		a = panDuan(arr, x, y);
	}
	arr[x][y] = '#';
}

//判断输赢----三个相同棋子连成一条线就是胜利
int game_over(char arr[ROW][COL]) {
	int a = 0;//如果为2则机器赢，为1则玩家赢，3为平局
	int i = 0;
	int count = 0;

	for (i = 0; i < ROW; i++) {
		int j = 0;
		for (j = 0; j < COL; j++) {
			//横着
			if ((arr[i][j] == '*') && (arr[i][j + 1] == '*') && (arr[i][j + 2] == '*') && (j + 2 < COL))
				a = 1;
			if ((arr[i][j] == '#') && (arr[i][j + 1] == '#') && (arr[i][j + 2] == '#') && (j + 2 < COL))
				a = 2;
		}
	}

	for (i = 0; i < COL; i++) {
		int j = 0;
		for (j = 0; j < ROW; j++) {
			//竖着
			if ((arr[j][i] == '*') && (arr[j+1][i] == '*') && (arr[j+2][i] == '*') && (j + 2 < ROW))
				a = 1;
			if ((arr[j][i] == '#') && (arr[j + 1][i] == '#') && (arr[j + 2][i] == '#') && (j + 2 < ROW))
				a = 2;
		}
	}

	for (i = 0; i < ROW; i++) {
		int j = 0;
		for (j = 0; j < COL; j++) {
			//斜着1
			if ((arr[i][j] == '*') && (arr[i + 1][j - 1] == '*') && (arr[i + 2][j - 2] == '*') && (i + 2 < ROW) && (j - 2 >= 0))
				a = 1;
			if ((arr[i][j] == '#') && (arr[i + 1][j - 1] == '#') && (arr[i + 2][j - 2] == '#') && (i + 2 < ROW) && (j - 2 >= 0))
				a = 2;
		}
	}

	for (i = ROW - 1; i >= 0; i--) {
		int j = 0;
		for (j = 0; j < COL; j++) {
			//斜着2
			if ((arr[i][j] == '*') && (arr[i - 1][j - 1] == '*') && (arr[i - 2][j - 2] == '*') && (i - 2 >= 0) && (j - 2 >= 0))
				a = 1;
			if ((arr[i][j] == '#') && (arr[i - 1][j - 1] == '#') && (arr[i - 2][j - 2] == '#') && (i - 2 >= 0) && (j - 2 >= 0))
				a = 2;
		}
	}

	if (a == 1) {
		printf("恭喜玩家获胜！！！\n");
		return 1;
	}
	else if (a == 2) {
		printf("再接再厉\n");
		return 1;
	}

	//平局判断
	for (i = 0; i < ROW; i++) {
		int j = 0;
		for (j = 0; j < COL; j++) {
			if (arr[i][j] != ' ')
				count++;
		}
	}
	if (count == ROW * COL) {
		printf("平局\n");
		return 1;
	}
	return 0;
}














