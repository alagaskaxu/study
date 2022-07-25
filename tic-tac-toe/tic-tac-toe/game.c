#define _CRT_SECURE_NO_WARNINGS
#include "game.h"	//game.h头文件包含了一些共同的头文件如stdio.h,减少重复代码

//初始化棋盘函数为"空白"的具体实现方法
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0,j = 0;
	for ( i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';	//将棋盘数组初始化为空格,由于数组名就是指针,指向实际数组的地址,所以主函数的实参会改变
		}
	}
}

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);	//打印棋盘数组的数据
			if (j < col - 1)
			{
				printf("|");		//打印棋盘竖线分割,最后一个不用打印
			}
		}
		printf("\n");	//打印完一行就换行
		//打印棋盘横向分割线
		if (i < row -1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");	//打印棋盘横向分割线,最后一行不用打印
				if (j < col - 1)
				{
					printf("|");
				}
			}

			printf("\n");	//打印完棋盘横向分割后换行,到下一行
		}
	}
}

//玩家下棋
void PlayerMove(char board[][COL], int row, int col)	//形参可以省略,如果不省略二维数组,根据二维数据的定义行可以省略,但列不能省略,board[][COL]和board[ROW][COL]等价
{
	int x = 0, y = 0;
	printf("玩家下棋:>\n");
	printf("Tips:下棋的坐标从 1 1 开始, 坐标中间加空格\n");
	while (1)
	{
		printf("请输入下棋的坐标:> ");
		scanf("%d %d", &x, &y);
		//判断坐标合法性,玩家从坐标1 1开始而不是0 0,坐标 1 1 对应数组的[0][0]元素
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//判断坐标是否存在值,是否被占用; 玩家输入的坐标与实际数组的下标相差 1
			if (' ' == board[x - 1][y - 1])	//单个字符可以直接用等号判断其ASCII码是否相同,如果是字符串则需要使用strcmp()函数来比较
			{	//坐标未被占用
				board[x - 1][y - 1] = '*';	//在对应坐标的元素赋值为'*',模拟下棋
				break;	//break;用来跳出while循环,不是跳出if语句;跳出循环表述玩家正确下完棋了
			}
			else
			{
				//坐标被占用
				printf("坐标已被占用! 请重新输入\n");
				//break;	这里不能break,break不是跳出if语句,而且直接跳出while循环,如果加了break,坐标被占用就跳出循环,无法重新输入坐标了,玩家会被跳过
			}

		}
		else
		{
			printf("坐标非法!!请重新输入\n");	//坐标非法,继续while循环重新输入坐标
		}

	}
	
}

//电脑下棋,为了简单实现,电脑不用算法直接随机下
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋:>\n");

	while (1)	//一直循环,直接成功下出棋为止
	{
		int x = rand() % row;	//使用rand随机函数得到一个随机数,需要先用srand()函数设置一次随机种子,只设置一次随机种子就行,所以放在主函数里;如果放在被调用的本函数里,sand会被多次调用,产生不理想的值
		int y = rand() % col;		//%3 可以让0<随机数<3,分别为 0,1,2;所以模行(%row)或列(%col),可以让随机数的范围分别保持在 0 到 row 和 0 到 col 之间(开区间)
		//电脑下棋不用考虑人的逻辑从1 1开始;直接按数组的逻辑来从0 0开始;x y就是数组下标

		//电脑根据程序产生合法的坐标,所以不用判断坐标合法性
		//直接判断坐标是否可以放元素(是否可以下棋)
		if (' ' == board[x][y])
		{
			board[x][y] = '#';
			break;	//成功下棋,结束while循环
		}

	}

}

//判断游戏状态,是否获胜
char IsWin(char board[ROW][COL], int row, int col)
{

	return a;
}





