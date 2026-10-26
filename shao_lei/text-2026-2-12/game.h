#pragma once

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 11//行
#define COLS 11//列
#define ROW (ROWS-2)//游戏棋盘行
#define COL (COLS-2)//游戏棋盘列
#define Boom 10

void New_board(char board[ROWS][COLS], int rows,int cols, char input);//初始化棋盘

void Show_board(char board[ROWS][COLS], int row, int col);//打印棋盘

void Put_mine(char mine[ROWS][COLS], int row, int col);//放地雷

void Play_show(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//玩扫雷

char Find(char mine[ROWS][COLS], int x, int y);//查找周围地雷数

int Flag(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//插旗判断输赢

void Easy_show(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//简单难度