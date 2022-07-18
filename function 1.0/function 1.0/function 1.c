#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>		//strcpy()函数的头文件

//函数讲解
//函数:也称子程序,是一个大型程序中的某部分代码,由一个或多个大型语句块组成,负责完成某项特定任务,具备一定的独立性
//一般会有输入参数和返回值,提供对过程的封装和细节的隐藏,这些代码通常被集成为软件库
//c语言中函数的分类:1.库函数(c语言编译器自带的一些基础功能的库函数) 2.自定义函数
//库函数文档  https://cplusplus.com/reference/	https://zh.cppreference.com/w/
//常用库函数有:IO函数(输入输出函数),字符串操作函数,字符操作函数,内存操作函数,时间/日期函数,数字函数,其它库函数

//求最大值的函数
int get_max(int x,int y)	//自定义函数get_max,形参x,y
{					
	int z = 0;
	if (x > y)
		z = x;
	else
		z = y;
	return z;	//返回z的值(即最大值)
}

//交换两个整形变量的内容

/*void swap(int x, int y)	//不需要返回值,则用void定义函数
*						//此时swap函数被调用时,实参传给形参,其实 形参是实参的一份临时拷贝,改变形参,不能改变实参
{						//用int x,y是形参;a,b的值传入x,y,但是实参和形参两者地址不同
	int tmp = 0;		//形参的值最后改变了位置,但是形参的地址与实参无关,导致实参没有变化
	tmp = x;			//或者说形参的改变,不影响实参,除非把值传给实参或者让形参的地址和实参地址一样,地址一样则改变形参就是改变实参
	x = y;				//最后使得调用该函数,没效果
	y = tmp;
}
*/
//正确写法:用指针,传地址
void swap(int* pa, int* pb)	//不需要返回值,则用void定义函数
{
	int tmp = 0;
	tmp = *pa; //此时*pa就表示实参a, * 为解引用,表示该地址所对应的那个变量(*pa 就是pa地址所指向的变量a,即*pa就是int变量a)
	*pa = *pb;
	*pb = tmp;
}

int main()
{
	//库函数
	//通过文档学习 strcpy函数
	//char* strcpy ( char* destination, const char* source );在string.h头文件下.  功能:copy string(拷贝字符串,包括'\0')
	//*表示指针变量	调用库函数先引对应头文件string.h
	char arr1[20] = { 0 };
	char arr2[] = "hello";
	strcpy(arr1, arr2);	//数组名本身就是地址 是指针类型
	printf("%s\n", arr1);	//打印arr1中字符串  %s指以字符串格式来打印

	//学习menset函数; 内存设置函数memoryset
	//void * memset ( void * ptr, int value, size_t num );
	//功能: Sets the first num bytes of the block of memory pointed by ptr to the specified value (interpreted as an unsigned char).
	// 将ptr指针所指向的内存的前num个字节的内容设置为value的值
	//size_t: tpyedef unsigned int  size_t;

	char arr[] = "welcome to c";
	memset(arr, 'x', 5);	//将arr地址指向的内存块中前 5 个字节的内容替换为'x'(value为x的ASCII码,'x'字符在计算机中用int类型的ASCII码存放,char类型的ASCII码(120)自动转换为字符(x) )
	printf("%s\n", arr);


	//自定义函数
	//和库函数一样,有函数名和函数类型,但由是自己设定
	/*
	函数组成:
	ret_type fun_name(para1, *)
	{				//函数体
		statement;	//语句项
	}
	ret_type 返回类型
	fun_name 函数类型
	para1	 函数参数
	*/
	//实参:真实传给函数的参数,实参可以是:常量,变量,表达式,函数等.在进行函数调用时,它们都必须有确定的值,以便把这些值传给形参
	//形参:形式参数,指函数名后括号内的变量,形参只在函数被调用时才实例化,函数调用完后自动销毁.形参只在函数中有效

	//例子:写一个函数可以找出两个整数中的最大值
	int a = 10;
	int b = 20;	//实参a,b
	int max = get_max(a + 15 , get_max(b,50));	//调用自定义函数get_max,实参可以是:常量,变量,表达式,函数等
	printf("max = %d\n", max);

	//交换两个整形变量的内容
	a = 10;
	b = 20;
	//swap(a, b);	//直接传值,发现函数没效果只是形参改变,实参没变; 需要传地址,才能改变实参
	swap(&a, &b);
	printf("a=10,b=20,交换后:a= %d,b= %d\n", a, b);

	return 0;
}