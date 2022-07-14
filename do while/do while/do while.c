#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//do while语句
/*
	语法结构
	do
		循环语句;
	while(表达式);
*/

//break 跳出中止循环
//continue 在do while语句中,跳过本次循环,不执行continue后的代码,直接进行循环条件的判断

int main()
{
	//输出一到十
	printf("用do while语句输出一到十:\n");
	int i = 1;
	do
	{
		printf("%d ", i);
		i++;
	} while (i <= 10);

	//break在do while语句中的效果;跳出循环
	printf("\n(i==5时break)用do while语句输出一到十:\n");
	i = 1;
	do
	{
		if (i == 5)	//在i==5时break跳出循环
			break;
		printf("%d ", i);//结果为1 2 3 4 
		i++;
	} while (i <= 10);

	//continue在do while语句中的效果;跳出循环
	/*
	printf("\n(i==5时continue)用do while语句输出一到十:\n");
	i = 1;
	do
	{
		if (i == 5)	//在i==5时continue跳出本次循环,跳过下面的代码,直接进行while条件的判断
			continue;
		printf("%d ", i);//结果为1 2 3 4 死循环
		i++;
	} while (i <= 10);
	
	*/

	return 0;
}