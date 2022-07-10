#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int add(int x,int y) //int整形的add函数,定义x,y为整形的形参(形式参数),调用该函数的实参(实际参数,下文为num1,num2)的数值赋值给形参x,y
{					//{}内为实现方法
	int s = 0;		//定义整形s与函数类型对应,最后返回
	s = x + y;		//求两数相加的和赋值给int整形s
	return s;		//函数的返回值为s的值,与函数类型(int)对应
}

int main(){
	int input = 0;//输入的值
	printf("if语句简单测试:选择输出1还是0?\n");
	scanf("%d", &input);//&取地址符,取个地址名input来存放数值
	if (input == 1)//if选择语句,c语言中=为赋值符,==才是等于判断
		printf("你输入了1\n");
	else
	{
		printf("你输入了0\n");
		printf("00000\n");
	}
	
	//while简单循环语句(除了while还有for,do....while语句)
	int	line = 0;
	while (line < 10) //while循环语句,一直到line=10结束
	{
		printf("%d\t写代码\n",line+1);
		line++;		//line+1,a=i++先将i赋值给a再i=i+1(a=i,i=i+1)
					//a=++i先i=i+1再将i赋值给a(i=i+1,a=i)
	}

	if (line == 10)//if语句判断是否达到要求
	{
		printf("已打 %d 行代码\n", line);
		printf("学成\n");
	}
	else
	{
		printf("已打 %d 行代码,未到10行", line);
	}

	//函数,输入不同值输出对应结果,一个函数可用重复调用
	int num1 = 0, num2 = 0;
	printf("调用两数求和\n");
	printf("输入num1为:");
	scanf("%d", &num1);//键盘输入num1
	printf("输入num2为:\n");
	scanf("%d", &num2);//输入num2

	int sum = add(num1, num2);//调用add函数来求两数相加,函数实现的方法在main函数外(见开头)

	printf("两数和为:%d\n", sum);//输出结果

	//数组,一组同类型的元素的集合,类似一块空间
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};//创建10个整形数值的数组
	char ch[5] = {'a','b','c','d','e'};//创建5个char类型的字符数值的字符数组,
										//如果没有设置数组个数,字符数组最后手动加'\0'(\0为结束符),
										// 不然会乱码(字符数组会一直找\0来结束,详细见/study/string下的string.c文件)
	//数组下标从0开始,arr[0]=>1,不赋初值则默认设为0
	printf("输出数组arr[10]的所有元素:\n");
	int i = 0;
	while (i < 10)
	{
		printf("%d ", arr[i]);
		i++;
	}
	return 0;
}