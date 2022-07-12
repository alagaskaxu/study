#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//语句:c语言中由一个分号;隔开的就是一条语句 a=b; 1+1; (单单一个; 叫空语句)
//ifelse分支选择语句
/*
	if语句结构:
	if(表达式)		表达式非零时则为真,为真if语句执行,为假if语句不执行
		语句;
					//多分支
	if(表达式)			if(表达式1)
		语句1;				语句1;
	else				else if(表达式2)
		语句2;				语句2;
						else
							语句3;
	如果满足表达式则执行if语句,不满足则执行else语句
	if,else下的语句默认只支持一条语句,如果要运行多条语句需要加大括号{}
	if()
	{
		语句1;
		语句2;
		语句n;
	}
	else
	{
		语句1;
		语句2;
	}
*/
int test(int a)
{
	if (0 == a) //如果a==0则返回0,用0==a,表达意思一样,同时可以防止等号写成赋值号,0 = a会报错(常量不能被赋值),而a = 0不会报错,有效减少错误
		return 0;//return 完后,直接出函数,下面的代码不会运行
	printf("test");
	return 1;
}
int main()
{
	int age = 50;
	//双分支,要么满足条件,要么不满足条件
	if (age >= 18) //如果age>=18则运行if语句输出成年
		printf("成年\n");
	else
	{
		printf("未成年\n");//如果age不满足age>=18,则运行else语句输出未成年
		printf("不能抽烟\n");
	}		//if else 默认只支持一条语句,想执行多条语句,则加{},不加则ifelse只运行其下的语句1,语句2为普通语句顺序执行,不算为ifelse下的分支语句
	//多分支
	if (age < 18)
	{
		printf("多分支测试:少年\n");
	}
	else if (age >= 18 && age < 26)//不能写成18<= age <26;应该使用逻辑与&&,写成age>=18&&age<26(表明两个结果都要为真)
					//假设age=60,运行时18<= 60 <26,18<=60为真1,然后1<26为真,最后就会判断错误,输出60为青年
	{
		printf("多分支测试:青年\n");
	}
	else if (26<= age && age <40)//age >= 26 和26 <= age都可以,(假设age=60, 26<=60&&60<40 ,结果为 (真)1 && 0(假) ==> 0(假) 不满足条件不执行该语句)
	{
		printf("多分支测试:壮年\n");
	}
	else if (age < 60)	//age >= 40也可以不写,写了有助于代码理解
	{
		printf("多分支测试:中年\n");
	}
	else if (age >= 60 && age < 100)
	{
		printf("多分支测试:老年\n");
	}
	else				//最后的else可以不写,后面的普通语句顺序执行, else if就是if语句
	{
		printf("多分支测试:神仙\n");
	}

	int a = 0;
	int b = 2;
	if (a == 1)//a!=1,下面的语句不执行
		if (b == 2)		//此if语句因为上一个if未执行,直接被跳过,使得与它对应的else也被跳过了
			printf("b=2\n");
	else		//注意!!:else默认与最近的if匹配,与是否对其无关,对应的if被跳过,此else也被跳过了
		printf("a=1??\n");//什么都没能输出,想输出a=1??则需要按格式加{}形成代码块
	printf("a!=1,b根本没被判断\n");

	printf("测试return的效果:%d\n", test(a));

	//练习:判断数是否为奇数(1-100)

	int num = 0;
	printf("输入一个1 - 100的数:\n");
	scanf("%d", &num);
	if (num < 1 || num>100)
	{
		printf("%d 不在1-100范围内\n", num);
	}
	else if (1 == num % 2)//奇数就是除于2余 1 的数,故num模2来取余来判断是否等于1
	{
		printf("%d 是奇数\n", num);
	}
	else
	{
		printf("%d 不是奇数\n", num);
	}
	//用while函数列出1-100的奇数

	int n = 0;
	while (n < 100)
	{
		n++;
		if (n%2)
		{
			printf("%d ", n);
		}
	}

	printf("\n");

	int m = 0, i = 0;
	int arr[100] = { 0 };
	while (i<100)
	{
		m++;
		arr[i] = m;
		if (m%2)
		{
			printf("%d ", arr[i]);
		}
		i++;
	}


	return 0;
}