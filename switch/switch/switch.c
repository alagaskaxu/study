#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//switch语句 适用于多分支语句
/*
	switch(整形表达式)
	{
		语句项;
	}
	语句项一般为case语句如下
	case 整形常量表达式: 
		语句;
		
	case语句后一般加上break跳出switch,达到中止的效果
	case决定入口,break决定出口
	break; 只跳出自身所在的switch
*/

int main()
{
	int day = 0;
	//float day = 0; 报错 switch和case里必须是整形,case必须整形常量
	//不过可以用字符,因为字符本质是整形常量的ASCII码值
	printf("输入星期几:\n");
	scanf("%d", &day);

	switch (day)
	{
	case 1:		
		printf("星期一");
		break;	//case语句最后用break跳出switch语句,达到中止的效果
	case 2:
		printf("星期二");
	case 3:		//如果没有break跳转出去,则代码在跳转到对应case语句在执行完语句后就会继续顺序执行下面的语句,直到break跳出
		printf("星期三");
	case 4:
		printf("星期四");
	case 5:
		printf("星期五");
		break;
	case 6:
		printf("星期六");
		break;
	case 7:
		printf("星期天");
		break;
	default:	//默认,如果以上情况都没有则执行默认default
		printf("输入错误!!!");
		break;
	}

	printf("\n\n输入星期几,输出1-5工作日,6-7周末:\n");
	switch (day)  //break可以按自己需求放置
	{
	default:	//除了能匹配的case其它都执行默认语句
		printf("输入错误!!!");//default没有特定顺序,一般放最后
		break;
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("工作日\n");
		break;
	case 6:
	case 7:
		printf("周日\n");
		break;//可以不加,但是加上,便于理解,而且方便扩展case8
	}

	//练习
	int n = 0, m = 0;
	n = 1;
	m = 2;
	switch (n) //n=1
	{
	case 1:
		m++;  //m=3,没有break继续顺序执行
	case 2:
		n++;  //n=2
	case 3:
		switch (n)  //switch可以嵌套
		{		//n=2
		case 1: //跳过 case 1
			n++;
		case 2:	 //n=2
			m++; //m=3+1=4
			n++; //n=2+1=3
			break; //跳出这个switch 
		}
	case 4:  //break只跳出一个switch
		m++; //m=4+1=5
	default:
		break;//遇到break跳出switch
	}
	printf("m = %d, n = %d \n", m, n);//m= 5, n= 3

	return 0;
}