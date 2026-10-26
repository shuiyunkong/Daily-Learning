#pragma once

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

#define ROW 3//行
#define COL 3//列

//初始化棋盘声明
void qiPan_chushihua(char arr[ROW][COL], int row, int col);

//打印棋盘声明
void daYin(char arr[ROW][COL], int row, int col);

//玩家下棋程序的声明
void xiaQi_player(char arr[ROW][COL], int row, int col);

//判断玩家坐标是否正确声明
int panDuan(char arr[ROW][COL], int row, int col);

//机器下棋程序声明
void xiaQi_ai(char arr[ROW][COL]);

//判断输赢程序声明
int game_over(char arr[ROW][COL]);