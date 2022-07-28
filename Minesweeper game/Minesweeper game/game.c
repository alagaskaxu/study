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

//递归排查周围所有雷数,pwin为指针用来给标志位win传数值
void SearchBomm(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y, int* pwin)
{
	//递归可能会使得传入的坐标+1,-1导致超出棋盘,判断一下坐标合法性
	if (x >= 1 && x <= row && y >= 1 && y <= col)
	{
		//得到当前坐标周围一圈的雷数
		int num = get_mine_count(mine, x, y);

		//如果当前坐标周围没有雷,则开始递归
		if (0 == num )
		{
			//第一次排查的流程
			(*pwin)++;//win计数器+1
			//周围没有雷且没被标记,则show[x][y]元素变为' '或者'0'
			if ('!' != show[x][y])
			{
				show[x][y] = ' ';
			}
			
			//让(x,y)周围的八个坐标开始进行排查
			for (int i = -1; i < 2; i++)
			{
				for (int j = -1; j < 2; j++)
				{
					//为了避免重复排查同一坐标,造成死递归,设置限制,只排查元素为默认'*'的坐标,也能避免被标记的元素被递归,使游戏变简单
					if ('*' == show[x + i][y + j])
					{
						SearchBomm(mine, show, row, col, x + i, y + j, pwin);
					}
				}//for(j)
			}//for(i)

		}//if(0 == num)
		else
		{
			//当前坐标周围有雷则,将雷数记录在show数组,
			show[x][y] = num + '0';	//show数组为char类型,num为int类型
			//win计数器+1
			(*pwin)++;
		}

	}//if(坐标合法)

	//坐标合法,不使用函数
}

//手动标记雷
void MarkMine(char show[ROWS][COLS], int row, int col)
{
	//(x,y)坐标
	int x = 0;
	int y = 0;
	system("cls");	//清屏
	DisplayBoard(show, row, col);	//打印要标记的棋盘
	printf("==============================\n");
	printf("请输入要标记或去除的坐标(从1 1开始):> ");
	scanf("%d %d", &x, &y);
	//坐标是否合法
	if (x >= 1 && x <= row && y >= 1 && y <= col)
	{
		//判断坐标处元素能否标记还是去除
		if ('*' == show[x][y])
		{
			show[x][y] = '!';	//标记
			system("cls");	//清屏
			DisplayBoard(show, row, col);	//打印标记后的棋盘
			printf("成功标记(%d,%d)处", x, y);
		}
		else if ('!' == show[x][y])
		{
			show[x][y] = '*';
			system("cls");	//清屏
			DisplayBoard(show, row, col);	//打印标记后的棋盘
			printf("成功去除(%d,%d)的标记", x, y);
		}
	}//if(x&&x&&y&&y)
	else
	{	//非法坐标
		printf("\n====================\n");
		printf("!!!坐标错误!!!\n请重新输入坐标\n坐标范围为[1,9]\n");
		Sleep(500);	//等待0.5s
	}//else(标记坐标非法)
			
}//MarkMine()

//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//选项变量
	int choice = 0;
	int start = 1;	//start为1式继续游戏,start为0 时结束游戏
	//输入排查的坐标
	int x = 0;	//行号
	int y = 0;	//列号
	//获胜条件的标记变量
	int win = 0;
	int* pwin = &win;	//指针pwin使得调用SearchBoom函数能给win传值

	//只要不是雷就标记一下,win+1
	//当win计数器到所有格子都打开且没踩雷(减去雷数)则游戏获胜,循环结束
	while (win < row*col - MINES && 1 == start)
	{
		printf("================\n");
		printf("1.排查雷\n");
		printf("2.标记或取消雷\n");
		printf("0.结束游戏\n");
		printf("请选择操作 1 or 2 :> ");
		//fflush(stdin);	//失效,不起作用,可能是编译器或写法问题,fflush只支持file*类型,可能只能刷新文件流的缓冲区,键盘输入不行??
		//理论上可以清空全部缓冲区	fflush()刷新缓冲区函数,stdin标准输入流,如键盘,文件等; 刷新输入流的缓冲区

		//利用getchar()加循环,一个一个清空
		while ((choice = getchar()) != '\n')	//getchar得到一个字符,while一直循环得到字符一直到\n
			;//空语句,清理缓冲区,防止缓冲区自动输入,去掉'\n'字符
		
		scanf("%d", &choice);
		switch (choice)
		{
			//排查雷
		case 1:
			system("cls");	//清屏
			DisplayBoard(show, row, col);	//打印要排查的棋盘
			printf("======================================\n");
			printf("请输入要排查的坐标,坐标从左上角1 1开始:> ");
			while ((choice = getchar()) != '\n')	//getchar得到一个字符,while一直循环得到字符一直到\n
				;//空语句,清理缓冲区,防止缓冲区的无关数据传入输入,去掉'\n'字符
			scanf("%d %d", &x, &y);	//x,y 范围[1,9]
			//判断坐标合法性
			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				//检查座标处是不是雷(是雷,game over; 不是雷,显示周围的雷数,将排查到的信息传入show数组)
				//排查处不是雷且show[x][y]元素未被排查过时,进入排查函数,统计周围情况
				if ('1' != mine[x][y] && '*' == show[x][y])
				{
					//递归优化
					//用递归实现排查一个坐标,得到一片信息
					SearchBomm(mine, show, row, col, x, y, pwin);

					//清理屏幕
					system("cls");
					//显示已排查过的信息
					DisplayBoard(show, row, col);	//打印棋盘

				}	//if((x,y)处不是雷且未被排查过)
				else if ('1' == mine[x][y])	//排查处是雷,则gameover
				{
					system("cls");	//清空屏幕
					printf("===========游戏失败===========\n");
					printf("   !!!!!!!!!!Boom!!!!!!!!!!\n");
					//展示一下雷区
					DisplayMine(mine, row, col);
					printf("  !!(%d,%d)处为#雷#\n", x, y);
					printf("===========游戏失败===========\n");
					start = 0;;	//跳出排查程序的循环
				}	//es-if(x,y)处为雷
				else	//show[x][y]不为默认的'*'则表示此处已经排查过
				{
					//显示已排查过的信息,由于有"cls"清屏指令,这里重新展示
					//DisplayBoard(show, row, col);	//打印棋盘
					printf("====================\n");
					printf(" (%d,%d)处已排查过\n", x, y);
					printf("====================\n");
				}

			}//if(坐标的合法性)
			else	//坐标不合法
			{
				printf("\n====================\n");
				printf("!!!坐标错误!!!\n请重新输入坐标\n坐标范围为[1,9]\n");
				Sleep(500);	//等待0.5s
			}//else(坐标不合法)
			break;

			//标记雷
		case 2:
			//是否需要标记雷
			while ((choice = getchar()) != '\n')	//getchar得到一个字符,while一直循环得到字符一直到\n
				;//空语句,清理缓冲区,防止缓冲区的无关数据传入输入,去掉'\n'字符
			MarkMine(show, row, col);
			break;

			//start == 0时结束游戏
		case 0:
			start = 0;
			system("cls");
			break;
		default:
			printf("\n=================\n");
			printf("!!输入错误!!\n请输入0,1或2\n");
			Sleep(500);	//等待0.5s
			break;
		}//switch(choice)

	}//while(win < row*col - MINES && 1 == start)
	
	if (row * col - MINES == win)
	{
		//展示雷区
		system("cls");	//清屏
		DisplayMine(mine, row, col);
		printf(" !!!!!  恭喜你  !!!!!\n");
		printf("!!!!!  游戏获胜  !!!!!\n");
		printf("============================\n");
		Sleep(500);	//等待0.5s
	}
}//FindMine()


