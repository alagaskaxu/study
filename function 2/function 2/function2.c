#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "sub.h"		//引用自己的减法函数头文件,""
						//引用头文件,相当于把头文件的内容拷贝过来
//导入mult函数的头文件和静态库
#include "mult.h"
//导入静态库
#pragma comment(lib,"mult.lib")	//mult.lib 存在本function2文件里

//函数的嵌套调用和链式访问
//函数之间可以有机的组合

void test3()
{
	printf("hello\n");
}
int test2()
{	
	test3();	//调用test3
	return 0;
}

//函数的声明和定义
// 定义就是创造一个函数,指函数的具体实现
// 声明就是告知编译器存在一个函数
//形参可以加,也可省略,有形参类型就行; 函数声明告诉编译器有一个函数叫什么,参数是什么,返回类型是什么,具体是否存在,无关紧要
//函数声明一般出现在函数使用前,要先声明后调用
//函数声明一般放在头文件中,模块化,便于生成静态库lib

//int add(int, int);//函数声明,告诉编译器有这个函数,只需要放在函数调用前,一般放主函数前


int main()
{
	//嵌套调用
	test2();//调用tesst2,test2里调用test3; 嵌套调用

	//链式访问 : 把一个函数的返回值作为另一个函数的参数
	int len = strlen("abc");
	printf("%d\n", len);
	printf("%d\n", strlen("abc"));	//链式访问

	char arr1[20] = { 0 };
	char arr2[] = { "bit"};
	printf("%s\n", strcpy(arr1, arr2));	//strcpy()返回目的地的起始地址	(arr1的起始地址)

	printf("%d", printf("%d", printf("%d", 43)));	//输出4321; printf的返回值类型是int,返回值为打印在屏幕上的字符的个数;打印43,返回2,打印2返回1,打印1

	int a = 10;
	int b = 20;

	int add(int, int);//函数声明,告诉编译器有这个函数,只需要放在函数调用前,一般放主函数前,或者模块化放头文件中
	//int x,int y可以加,也可省略; 函数声明告诉编译器有一个函数叫什么,参数是什么,返回类型是什么,具体是否存在,无关紧要
	int c = add(a, b);
	printf("\n和为:%d\n", c);

	c = sub(b, a);	//函数声明在sub.h ,函数定义在subtraction.c文件
	printf("差为:%d\n", c);

	c = mult(a, b);
	printf("积为:%d\n", c);	//函数声明在mult.h,没有源码,只有mult.lib静态库,导lib静态库,也能使用函数


	return 0;
}

//函数的声明和定义
//编译器顺序编译,函数一般放主函数前,先编译(让编译器知道有这个函数)
int add(int x, int y)	//函数的定义如果放在主函数后,则需要先声明,就能使用
{
	return x + y;
}