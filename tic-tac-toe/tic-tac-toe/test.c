#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//<>表示先去系统目录寻找头文件,没有再去当前目前寻找头文件; ""表示先去当前目录寻找头文件,没有再去系统目录
					//库函数都在系统目录,自定义头文件一般不在系统目录,一般放在当前项目的当前目录
#include "game.h"	//游戏头文件,所以符号,函数的声明都在game头文件中,模块化方便调用,高内聚低耦合
//测试井字棋游戏的逻辑

void menu()
{
	printf("**************************\n");
	printf("******  井字棋游戏   ******\n");
	printf("******    1.play    ******\n");
	printf("******    0.exit    ******\n");
	printf("**************************\n");
}

void game()	
{
	//利用二维数组的下标作为 棋子 的坐标,用二维数组存储棋子的信息
	char board[ROW][COL];	//创建一个二维数组,作为棋盘,存放棋子的信息
	//row和col的定义都在game头文件,所有符号的定义,函数的声明都在头文件,模块化,便于调试与管理,高内聚低耦合
	//由于row和col可以人为修改数值,所以数组的初始化赋值不能写死,需要根据row和col的大小来动态初始化棋盘数组
	InitBoard(board, ROW, COL);	//初始化棋盘函数为"空白",写在函数里,方便模块化和调试和调用
	//函数的声明都放在game头文件,具体实现方法都在game.c文件,模块化,高内聚低耦合

	//打印棋盘函数
	DisplayBoard(board, ROW, COL);	//打印刚刚初始化的棋盘
	char ret = 0;	//游戏状态的返回值
	//开始下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);	//此时的ROW和COL用来判断玩家下的棋是否超出棋盘范围
		DisplayBoard(board, ROW, COL);	//打印下完棋后的棋盘
		//判断玩家是否赢得游戏
		ret = IsWin(board, ROW, COL);	//用来判断游戏的状态
		//返回'C'游戏继续,循环继续
		if ('C' != ret)	//不为C游戏结束,跳出游戏循环
			break;

		//电脑下棋
		ComputerMove(board, ROW, COL);	//此时的ROW和COL用来帮助电脑找到坐标范围来下棋
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢得游戏
		ret = IsWin(board, ROW, COL);	//用来判断游戏的状态
		//返回'C'游戏继续,循环继续
		if ('C' != ret)	//不为C游戏结束,跳出循环,来到下面的if判断
			break;
	}//while(1)

	if ('*' == ret)	//返回值'*'为玩家获胜
	{
		printf("*****************\n");
		printf("**  玩家获胜!!  **\n");
		printf("*****************\n");
	}
	else if ('#' == ret)	//返回值为'#'电脑获胜
	{
		printf("*****************\n");
		printf("**  电脑获胜!!  **\n");
		printf("*****************\n");
	}
	else		//返回值为'Q' 平局
	{
		printf("***********\n");
		printf("**  平局  **\n");	
		printf("***********\n");
	}

	DisplayBoard(board, ROW, COL);	//打印最后的结果
	printf("\n======================================\n");
} //void game()


int main()
{
	int input = 0;	//输入是否开始玩的值
	srand((unsigned int) time(NULL));	//用时间设置随机数种子;  (unsigned int)强制类型转换为unsigned int类型; time(NULL)用空指针调用时间函数; srand()设置随机数的种子

	do
	{
		menu();	//生成菜单
		printf("请选择(1/0):>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//printf("play\n");
			game();	//游戏运行函数
			break;
		case 0:
			printf("exit\n");
			break;
		default:
			printf("选择错误,请重新选择\n");
			break;
		}
	} while (input);

	return 0;
}

