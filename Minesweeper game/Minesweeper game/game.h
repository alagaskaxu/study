#pragma once
//游戏头文件

//头文件的包含
#include <stdio.h>	//printf() ....
#include <stdlib.h>	//rand() srand()
#include <time.h>	//time()
#include <Windows.h>//sleep()

//符号定义
#define ROW 9 	//实际棋盘为9*9,最外边存在一圈隐藏边界,防止坐标越界
#define COL 9 
#define ROWS ROW + 2	//创建的数组大小为11*11
#define COLS COL + 2	//最外边存在一圈隐藏边界,防止坐标越界
#define MINES 1		//雷的数量

//函数声明

//数组初始化
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);	//展示的棋盘为9*9 传入ROW,COL,形参小写便于区分

//在mine数组中随机布置雷
void SetMine(char mine[ROWS][COLS], int row, int col);

//排查雷;将mine数组的情况传导到show数组,数组一样,共用row和col
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

//获得周围雷数
//int get_mine_count(char mine[ROWS][COLS], int x, int y);	//此函数仅用来为FindMine提供帮助,可以不写在头文件里,在FindMine()前编写该函数即可

//递归排查一片区域
void SearchBomm(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y, int* pwin); //此函数仅用来为FindMine提供帮助,可以不写在头文件里,在FindMine()前编写该函数即可


//手动标记雷
void MarkMine(char show[ROWS][COLS], int row, int col);

