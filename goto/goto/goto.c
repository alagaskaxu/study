#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>		//strcmp()函数头文件
#include <stdlib.h>		//system()函数

//goto 语句
/*
	c语言中提供了可以随意滥用的goto语句和标记跳转的标号
	理论上goto语句没有必要,但是某些场合下goto语句还可以使用,
	常见用法就是中止程序在某些深度嵌套的结构的处理过程,例如一次跳出两次以上的多层循环.
	只能在一个函数范围内跳转,不能跨函数
*/


int main()
{
flag:
	printf("hello\n");
	printf("haha\n");

	//goto flag;	//跳转到flag
				//死循环

	//一分钟关机
	//cmd中shutdown -s为设置关闭此计算机 -r为重启 -t为设置多少秒后关机
	//shutdown -a 为放弃关机
	//c语言中system()函数 专门用来执行系统命令

	char input[20] = { 0 };//存放输入的信息
	system("shutdown -s -t 60");
again:
	printf("电脑将在一分钟后关机,输入:\"取消\"来取消关机\n");
	scanf("%s", input);
	if (strcmp(input,"取消") == 0)	//strcmp函数用来比较字符串,相等返回值为0
	{
		system("shutdown -a");
		printf("关机已取消\n");
	}
	else
	{
		goto again;
	}

	/*一般不用goto也能达到效果,而且逻辑不会乱
	char input[20] = { 0 };
	system("shutdown -s -t 60");
	while(1)
	{
		printf("电脑将在一分钟后关机,输入:\"取消\"来取消关机\n");
		scanf("%s", input);
		if (strcmp(input,"取消") == 0)	//strcmp函数用来比较字符串,相等返回值为0
		{
			system("shutdown -a");
			printf("关机已取消\n");
			break;
		}
	}
	*/

	//开发时编译器为Debug,开发版本,调试版本
	//编译器改为Release,编译完成后,会产生release发行版本的exe文件(软件的正式版本)


	/*
		goto语句的真正运用场景
		for(...)
			for(...)
			{	
				for(..)
				{
					if(disaster)
						
						goto error;		//用于一下跳出多次循环,嵌套,直接到指定代码块

				}
			}
			...
	error:
		if(disaster)
			....//要处理的错误情况
	*/
	return 0;
}