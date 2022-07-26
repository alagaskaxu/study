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
		}//内for(j)
	}//外for(i)
}//InitBoard()

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
		}//内for(j)循环

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
		}//if()

	}//外for(i)循环
}//DisplayBoard()

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
			}//内if(' ' == board)

		}
		else
		{
			printf("坐标非法!!请重新输入\n");	//坐标非法,继续while循环重新输入坐标
		}//外if(x&&x&&y&&y)

	}//while(1)
	
}//PlayerMove()

//电脑下棋,为了简单实现,电脑不用算法直接随机下
//想要电脑智能,可以利用米字查找和权值表来求当前位置的权值大小
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

	}//while(1)

}//ComputerMove()

//判断棋盘是否满了
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < col; j++)
		{
			if (' ' == board[i][j])
			{
				return 0;	//棋盘有'空',不满返回0
			}
		}//for(j)
	}//for(i)

	return 1;	//棋盘满了,返回1
}//IsFull()

//米字搜索查找(x,y)处周围连成线的棋子个数
int Getcount(char board[ROW][COL], int x,int y)
{/*
				-x
				|	
		-y -----|------>+y
			   /|\
		 (1,-1) |	(1,1)
				+x
 */
	//创建方向数组,类似y_x坐标系,四个正方向(x,y): |(1,0) --(0,1) /(1,-1) \(1,1)	半个米字
	//坐标(x,y) x为棋盘数组的行,y为列
	int vx[4] = {1,0,1,1};
	int vy[4] = {0,1,-1,1};
	int count = 0;//计数有几个棋子相连

	for (int i = 0; i < 4; i++)	//从四个方向中选一个方向;
	{
		count = 1;	//默认棋子下在当前位置时的情况,标记为一颗棋子相连
		for (int j = -1; j < 2; j+=2)	//j用来控制方向的正负性,达到一个方向的两边一起查找,最后形成米字八向查找
		{
			int dx = x + j * vx[i];	//dx为原坐标向四周的偏移坐标,即原坐标X四周的坐标的横坐标x为dx
			int dy = y + j * vy[i];	//dy为原坐标向四周的偏移坐标,即原坐标y四周的坐标的横坐标x为dy
			//方向确定完毕
			//开始判断这个方向上相连几个子
			//当偏移后的坐标仍在棋盘数组范围内时开始枚举判断,计数
			while (dx >=0 && dx < ROW && dy >= 0 && dy < COL)
			{
				//开始查找坐标(x,y)对应方向是否有相同(元素)棋子;元素不为空的判断放在此函数外,可以减少运算量和通用性
					if (board[x][y] == board[dx][dy])	//同一方向上有相同棋子count+1
					{
						count++;	//count+1
					}
					else
					{
						break;	//原坐标(x,y)元素与偏移后的坐标(dx,dy)元素不同则跳出循环
					}
			
				//向对应方向继续偏移一次坐标
				dx = dx + j * vx[i];
				dy += j * vy[i];
				//直到偏移坐标到边界结束循环
			}//while(dx&&dx&&dy&&dy)
			//while循环结束
			//得到一个正方向或者一个负方向的count的值

		}//for(j)
		//for(j)循环结束,得到一条直线上的count值
		if (count >= WINNUM)
		{
			count = WINNUM;
			return count;	//count >= WINNUM说明有人获胜了返回count的值
		}
	}//for(i)

	return count;	//如果count各方向没超过WINNUM则返回count最后的值
}//Getcount

//判断游戏状态,是否获胜
char IsWin(char board[ROW][COL], int row, int col)
{
	//判断当前坐标的元素各个方向是否连成一线
	for (int i = 0; i < row; i++)	//i为行
	{
		int count = 0;
		for (int j = 0; j < col; j++)	//j为列
		{	
			if (' ' != board[i][j])		//board元素不为空时开始计算此处连线的棋子个数
			{
				count = Getcount(board, i, j);	//得到连线棋子个数
				if (WINNUM == count)	//如果count为WINNUM表示当前坐标有一个方向连成一线
				{
					return board[i][j];	//返回当前元素为'*'或'#
				}
			}//此元素为空直接查看下一个元素
			
		}//for(j列)
	}//for(i行)

	//判断是否平局(棋盘是否满了)
	int ret = IsFull(board, row, col);	//棋盘满了没结束就平局了;棋盘满了,返回1;没满返回0
	if (1 == ret)
		return 'Q';

	//没结束没平局,返回'C'
	return 'C';

}//IsWIn()

