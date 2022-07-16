#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	//srand();rand();等函数的头文件
#include <time.h>	//time();的头文件

//猜字游戏
//自动产生一个1-100的随机数字,猜对显示恭喜,猜错则告诉猜大了还是小了,直到猜对为止
//可重复游玩,除非退出游戏

void menu()	//打印游戏菜单的函数
{
	printf("******************************\n");
	printf("*********   1.play   *********\n");
	printf("*********   0.exit   *********\n");
	printf("******************************\n");
}

void game()	//猜字游戏的实现过程
{
	//1.先生产随机数,用rand函数(int rand(void) 无参,返回类型为整形)生产随机数,使用头文件stdlib.h
		//time()返回值的类型为time_t(结构体定义的64位的int类型),而srand的参数类型为unsigned int类型,所以用()强制转换time_t类型为unsigned int类
	//srand((unsigned int)time(NULL));	//void srand (unsigned int seed);设置随机数生成的起点(也叫设置随机数的种子),设置固定值则返回固定的随机数如srand(2);  rand()返回值45
				//当srand( );中的参数为随机值或为动态变化的数(时间戳)时,rand()就会返回一个真随机数
				//time_t time(time_t*timer);	time()函数可以返回一个类型为time_t(_int64)类型的时间戳(动态变化的数)  时间戳:利用现在时间来换算出一个值(如:用现在时间与计算机起始时间的差值换算成秒为单位的一串数字就叫时间戳)
	int ranum = rand()%100 + 1;	//rand返回了一个0 - 32767之间的假随机数字,想要随机,需要先使用srand设置随机的起点
					//想生产1-100的随机数只需要模100求余再+1,rand()%100 +1
					// 想产生0-100的数就模101; 想产生0-n的数,就模(n+1);0-n一共有n+1个数,所以模(n+1);或者说想产生多少个数(从零开始)就模多少
					//取模就是取余,余数不会大于等于模的数;余数<被除数
	//printf("ranum = %d\n", ranum);//如果直接用rand来设置随机数,发现每次程序重新运行的随机值都一样(从41开始的一串随机数),假随机; rand函数范围为0- RAND_MAX(值为十六进制0x7fff(32767d))

	//2.猜数字
	int guess = 0;
	while (1)	//一直猜数字,直到猜对
	{
		printf("请猜数字为:>");
		scanf("%d", &guess);
		if (guess < ranum)
		{
			printf("猜小了\n");
		}
		else if (guess > ranum)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("!!!恭喜你!!!\n猜对了,随机数为:%d\n",ranum);
			break;		//只有猜对了,才跳出while
		}

	}
}

int main ()
{
	int input = 0;						//NULL 空,time()里的参数为time_t类型的指针,time(NULL);表示传一个空指针
	srand((unsigned int)time(NULL));	//如果放在被调用的函数,每次被调用都设置一遍时间戳种子,随机值容易非常靠近,所以直接放在主函数,程序启动时只设置一次就行了,时间跨度也被拉长,随机值也不容易靠近

	do
	{
		menu();	//打印开始界面的函数
		printf("请选择1/0:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//printf("猜数字\n");
			game();		//自己定义的game函数,实际游戏的实现逻辑
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请选择1.play或者0.exit\n");
			break;	//跳出switch语句
		}


	} while (input);//用input作为判断条件,input = 1为真,继续循环,0为假,退出循环结束游戏,其它数字也是真,继续重新选择

	return 0;
}