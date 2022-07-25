#pragma once
//井字棋游戏的头文件

//所有头文件的包含
#include <stdio.h>	//只需引用game.h头文件就包含了一些共同的头文件,减少重复代码
#include <stdlib.h>	//引入随机数函数 srand()和rand()
#include <time.h>	//time()函数


//符号的定义
#define ROW 3	//宏定义 标识符ROW的值为常量3	行为3
#define COL 3	//列为3	用标识符方便游戏的底层数值的改变,想改变棋盘大小只需改变行类的数值就行,无需把源代码全部修改



//函数的声明

//初始化棋盘函数,具体实现在game.c文件
void InitBoard(char board[ROW][COL], int row, int col);	//虽然声明时,可以省略形参但是不建议省略

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//判断游戏状态,是否获胜:判断1.玩家赢了	2.电脑赢了	3.平均	4.游戏继续
//玩家赢了返回'*';	电脑赢了返回'#';	平局返回'Q';	游戏继续返回'C'
char IsWin(char board[ROW][COL], int row, int col);

