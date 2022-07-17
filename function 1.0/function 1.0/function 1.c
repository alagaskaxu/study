#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>		//strcpy()函数的头文件

//函数讲解
//函数:也称子程序,是一个大型程序中的某部分代码,由一个或多个大型语句块组成,负责完成某项特定任务,具备一定的独立性
//一般会有输入参数和返回值,提供对过程的封装和细节的隐藏,这些代码通常被集成为软件库
//c语言中函数的分类:1.库函数(c语言编译器自带的一些基础功能的库函数) 2.自定义函数
//库函数文档  https://cplusplus.com/reference/	https://zh.cppreference.com/w/
//常用库函数有:IO函数(输入输出函数),字符串操作函数,字符操作函数,内存操作函数,时间/日期函数,数字函数,其它库函数
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
	//to do

	return 0;
}