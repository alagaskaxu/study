#define _CRT_SECURE_NO_WARNINGS
#include "game.h"	//所有需要的头文件都在game.h里

//扫雷游戏的流程测试

void menu()	//菜单函数
{
	printf("************ ***********\n");
	printf("*****   扫雷游戏   *****\n");
	printf("*****    1.play   *****\n");
	printf("*****    0.exit   *****\n");
	printf("************ ***********\n");
}//menu()

void game()
{
	//printf("扫雷\n");
	/*
		1.布置雷,没有雷为'0',有雷的地方为 '1'
		2.排查雷
	*/

	//使用两个二维数组,一个存放雷,一个存放排查的信息
	//创建二维数组来存放雷
	char mine[ROWS][COLS];	//存放布置好的雷的信息(不可见)	初始化为'0'
	char show[ROWS][COLS];	//存放要展示的排查信息(展示)	初始化为'*'

	//初始化棋盘
	InitBoard(mine, ROWS, COLS , '0');
	InitBoard(show, ROWS, COLS , '*');

	//打印棋盘
	DisplayBoard(show, ROW, COL);	//只打印大小为9*9的棋盘,最外一圈(隐藏)不打印(

	//随机布置雷
	SetMine(mine, ROW, COL);	//雷随机布置在mine数组9*9

	//测试用,显示雷区,'1'为雷,正式版最后屏蔽
	DisplayBoard(mine, ROW, COL);	//只打印9*9的中间的棋盘,mine不展示,最后屏蔽

	//排查雷
	FindMine(mine, show, ROW, COL);


}//game()

int main()
{
	int input = 0;	//输入值
	//设置随机种子,一次就够,所以设置在主函数
	srand((unsigned int)time(NULL));	//将time类型的返回值强制类型转换为unsigned int类型

	do
	{
		menu();
		printf("请选择(1/0):> ");
		//fflush(stdin);	//清空全部缓冲区	fflush()刷新缓冲区函数,stdin标准输入流,如键盘,文件等; 刷新输入流的缓冲区
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			system("cls");	//清理屏幕,游戏开始
			game();	//扫雷游戏的具体运行
			break;
		case 0:
			system("cls");//清理屏幕,游戏结束
			printf("退出游戏\n");
			break;
		default:
			system("cls");//清理屏幕,重新选择
			printf("=======================\n");
			printf("!!输入错误!!\n请输入1或0\n");
			break;
		}

	} while (input);

	return 0;

}//main()

