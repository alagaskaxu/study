#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>		//strcpy()函数的头文件
#include <math.h>		//sqrt()开方函数

//函数讲解
//函数:也称子程序,是一个大型程序中的某部分代码,由一个或多个大型语句块组成,负责完成某项特定任务,具备一定的独立性
//一般会有输入参数和返回值,提供对过程的封装和细节的隐藏,这些代码通常被集成为软件库
//c语言中函数的分类:1.库函数(c语言编译器自带的一些基础功能的库函数) 2.自定义函数
//库函数文档  https://cplusplus.com/reference/	https://zh.cppreference.com/w/
//常用库函数有:IO函数(输入输出函数),字符串操作函数,字符操作函数,内存操作函数,时间/日期函数,数字函数,其它库函数

//求最大值的函数
int get_max(int x,int y)	//自定义函数get_max,形参x,y;传值调用
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
//正确写法:用指针,传地址; 传址调用
void swap(int* pa, int* pb)	//不需要返回值,则用void定义函数
{
	int tmp = 0;
	tmp = *pa; //此时*pa就表示实参a, * 为解引用,表示该地址所对应的那个变量(*pa 就是pa地址所指向的变量a,即*pa就是int变量a)
	*pa = *pb;
	*pb = tmp;
}

int is_prime(int n)
{
	//用n除2-(n-1)的数,如果整除,则不是素数,返回0
	int j = 0;						//假设数m=p*Q,且p≤Q则m=p*Q≥p*p即p≤√m,Q≥√m 所以m必有一个小于或等于其平方根的因数
	for ( j = 2; j <= sqrt(n); j++)	//用开方sqrt()函数优化运算次数,原理:一个数必有一个小于或等于其平方根的因数.(类似用除2来去除大因数只求小的因数是否满足条件,因为对应大因数*小因数等于要判断的数,而只要有一个因数,就不是素数)
									//根号i的平方等于i本身,必有一个小于或等于根号i的因数
	{
		if (n % j == 0)
			return 0;
	}
	return 1; //返回1表示是素数
}

//一个函数不写返回类型,默认返回int类型
int is_leap_year(int y)
{	//是闰年返回1,不是返回0
	if ( ( y%4 == 0 && y%100 !=0 ) || (y%400 == 0))	//(y%4 == 0) 可以加括号方便理解,也可以不加,因为优先级,逻辑运行一样,结果一样
		return 1;		//初级运算符( )、[ ]、->、.  >单目运算符>算数运算符(先乘除后加减)>关系运算符>逻辑运算符（不包括！）>条件运算符>赋值运算符>逗号运算符
	return 0;			//简单记就是：！ > 算术运算符 > 关系运算符(>,<,==,!=等) > && > || > 赋值运算符

	//return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);	直接返回if的判断结果是1还是0,也可以
}

//二分查找
int binary_search(int v[], int k,int n)
{									//数组ar传参,实际传递的不是数组本身,仅仅传过去了数组首元素ar[0]的地址,所以int v[]本质是int* v 一个叫v的指针类型,而非int类型的数组
	//int sz = sizeof(v) / sizeof(v[0]);	//sizeof(v)只能求出指针变量 v 的长度为4字节(32位指针变量为4字节,64位8字节),求不出main函数中ar[]的总字节长度,所以32位编译器中sz = 4字节除以v[0]的4字节等于1;如果是64位,sz = 8字节/4字节 = 2(可以用f10调试查看)
	int left = 0,right = n-1;
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (v[mid] < k)
			left = mid + 1;
		else if (v[mid] > k)
			right = mid - 1;
		else
			return mid;	//找到目的数
	}

	return -1;	//未找到
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
	fun_name 函数名
	para1	 函数参数
	*/
	//实参:真实传给函数的参数,实参可以是:常量,变量,表达式,函数等.在进行函数调用时,它们都必须有确定的值,以便把这些值传给形参
	//形参:形式参数,指函数名后括号内的变量,形参只在函数被调用时才实例化,函数调用完后自动销毁.形参只在函数中有效
	//一个函数不写返回类型,默认返回int类型

	//例子:写一个函数可以找出两个整数中的最大值
	int a = 10;
	int b = 20;	//实参a,b						//传值调用
	int max = get_max(a + 15 , get_max(b,50));	//调用自定义函数get_max,实参可以是:常量,变量,表达式,函数等
	printf("max = %d\n", max);

	//交换两个整形变量的内容
	a = 10;
	b = 20;
	//swap(a, b);	//直接传值,发现函数没效果只是形参改变,实参没变; 需要传地址,才能改变实参
	swap(&a, &b);	//传址调用
	printf("a=10,b=20,交换后:a= %d,b= %d\n", a, b);

	//通过函数输出100-200的素数
	printf("100-200间的素数有:\n");
	int i = 0,count = 0;
	for ( i = 100; i <= 200; i++)
	{
		//判断i是否为素数
		if (is_prime(i) == 1)
		{
			count ++;
			printf("%d ", i);
		}
	}
	printf("\n一共有%d个素数\n",count);

	//用函数打印1000-2000年的闰年
	int y = 0;
	count = 0;
	printf("1000-2000年中为闰年的是:\n");
	for ( y = 1000; y <= 2000; y++)
	{
		//是闰年返回1,不是返回0
		if (is_leap_year(y) == 1)
		{
			count++;
			printf("%d ", y);
		}
	}
	printf("\n一共有%d个闰年\n", count);

	//用函数,实现一个整形有序数组的二分查找
	int ar[] = { 10,11,12,13,14,15,16,17,18,19 };
	int key = 17;
	int sz = sizeof(ar) / sizeof(ar[0]);
	int ret = binary_search(ar,key,sz);	//数组ar传参,实际传递的不是数组本身,仅仅传过去了数组首元素ar[0]的地址
	//找到返回找到位置的下标,找不到返回-1
	if (-1 == ret )
	{
		printf("数组中不存在目标数\n");
	}
	else
	{
		printf("存在,ar[%d] = %d\n", ret, ar[ret]);
	}

	return 0;
}