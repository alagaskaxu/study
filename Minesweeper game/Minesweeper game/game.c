#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

//游戏函数的实现

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}//InitBoard()

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	printf("---------扫雷游戏---------\n");
	//打印列号
	for (int j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");	//换行
	//打印棋盘
	for (int i = 1; i <= row; i++)	//打印ROW,COL的大小(9*9),从下标1开始打印到9为止
	{
		printf("%d ", i);	//打印行号
		for (int j = 1; j <= col; j++)
		{
				printf("%c ", board[i][j]);	//打印元素字符
		}
		printf("\n");
	}
}//DisplayBoard

/*
	static 的三个作用
	修饰局部变量
	修饰全局变量
	修饰函数
*/

//打印雷区,设为静态函数,使得此函数只能在game.c文件内使用
static void DisplayMine(char Mine[ROWS][COLS], int row, int col)
{
	printf("---------  #雷区#  ---------\n");
	//打印列号
	for (int j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");	//换行
	//打印棋盘
	for (int i = 1; i <= row; i++)	//打印ROW,COL的大小(9*9),从下标1开始打印到9为止
	{
		printf("%d ", i);	//打印行号
		for (int j = 1; j <= col; j++)
		{
			if ('1' == Mine[i][j])
				printf("# ", Mine[i][j]);	//如果为雷打印'#'号
			else
				printf("%c ", Mine[i][j]);	//其它情况直接打印元素字符
		}
		printf("\n");
	}
}//DisplayMine

//布置雷
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	//布置10个雷
	int count = MINES;
	while (count)	//count为0,布置完成
	{
		//生成随机下标,rand()函数记得用srand()在主函数内设置种子,头文件为<stdlib.h>
		int x = rand()%row + 1;		//行号i,取模+1保证随机数范围在1-9之间
		int y = rand()%col + 1;		//列号j,%模一个数n,得到的余数一定小于那个数n,余数范围是[0,n),+1则范围为[1,n+1) 即 [1,n]
		if ( '0' == mine[x][y])		//如果mine数组对应元素是'0'为空,没有雷则存放雷
		{
			mine[x][y] = '1';		//'1'字符1 表示为雷; '0'字符0 表示为空(没雷)
			count--;	//布置完一个雷,雷数count-1
		}

	}//while(count)

}//SetMine()

//获得坐标周围的雷数,可以仅写在FindMine函数前,不写入头文件,因为只有FindMine函数使用
static int get_mine_count(char mine[ROWS][COLS], int x, int y)	//static修饰函数表示静态函数,使此函数只能在game.c文件内使用,其它地方无法使用
{
	/*
		八个方向(加上自己九个)	(x-1,y-1) (x-1,y) (x-1,y+1) (x,y-1) |(x,y)自己| (x,y+1) ......
	*/
	int count = 0;
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			count  += (mine[x + i][y + j] - '0');//mine数组是char类型.'0'ASCII码为int 48
		}
	}
	return count;	//返回count的值
}


//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//输入排查的坐标
	int x = 0;	//行号
	int y = 0;	//列号
	int win = 0;
	while (win < row*col - MINES )	//当win计数器到所有格子都打开且没踩雷(减去雷数)则游戏获胜
	{
		printf("请输入要排查的坐标,坐标从左上角1 1开始:> ");
		scanf("%d %d", &x, &y);	//x,y 范围[1,9]
		//判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//检查座标处是不是雷(是雷,game over; 不是雷,显示周围的雷数,将排查到的信息传入show数组)
			if ('1' == mine[x][y])	//排查处是雷,则gameover
			{
				printf("===========游戏失败===========\n");
				printf("   !!!!!!!!!!Boom!!!!!!!!!!\n");
				//展示一下雷区
				DisplayMine(mine, row, col);
				printf("   !!!(%d,%d)处为#雷#\n", x, y);
				printf("===========游戏失败===========\n");
				break;
			}//if(踩雷)
			else	//坐标处不是雷,统计(x,y)周围的雷数
			{
				int count = get_mine_count(mine, x, y);
				//存放周围雷数到show数组,用来展示
				//show数组存放字符,count为int整数,需要利用ASCII码修改一下,再存入show数组
				//'0' -> 48 ; '1' -> 49 ; '2' - > 50 ; ....
				show[x][y] = '0' + count;

				//显示排查出的信息
				DisplayBoard(show, row, col);	//打印棋盘

				win++;	//只要不是雷就标记一下,计数器+1

			}//else(非雷)

		}//if(坐标的合法性)
		else	//坐标不合法
		{
			printf("!!!坐标错误!!!\n请重新输入坐标\n坐标范围为[1,9]\n");
		}//else(坐标不合法)

	}//while(win < row*col - MINES)
	
	if (row * col - MINES == win)
	{
		//展示雷区
		DisplayMine(mine, row, col);
		printf(" !!!!!  恭喜你  !!!!!\n");
		printf("!!!!!  游戏获胜  !!!!!\n");
		printf("============================\n");
	}

}//FindMine()


