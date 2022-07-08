#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//变量的作用域(变量名的可用范围)与生命周期(变量的创建到销毁的时间段)
//常量:不会改变的量
int g_val = 2020; //全局变量
extern int g_val2;//声明变量,生命周期为程序的生命周期,从程序开始到结束
int main() {
	//1.字面常量
	3.14;//浮点型常量
	10;//整型常量
	'a';//字符常量,'a' (占内存1字节，等于整型数值97)
	"abcdef";//字符串常量,"abc" (占内存4字节，字符串长度3）
						//"a" (占内存2字节，字符串长度1）
	//2.const修饰的常变量
	//int num =10;//num为变量
	const int num = 10;//num为常变量,具有常量的不可变属性,虽然数值不可变但本质仍是变量
	//const int n=10;
	//int a[n] = { 0 };n报错,数组定义必须为常量,可证n有常量性质,但仍为变量

	//3.#define定义的标识符常量
#define MAX 100 //一般放开头,MAX为标识符
	int n = MAX;
	int a[MAX] = { 0 };//max完全是常量,不可变
	printf("n=%d\n", n);//n=100

	//4.枚举常量,可用一 一列举的常量如性别,星期几
	enum Sex//enum枚举关键字,定义枚举类
	{   //Sex这种枚举类的变量的所有数值
		MALE男 = 3,//默认从0开始递增(0,1,2),=3可赋初值为从3开始递增,或全赋特定初值
		FEMALE女,
		SECRET保密  //这三个值为枚举常量
	};
	enum Sex s = MALE男;//s为枚举类变量,MALE男为枚举常量
	s = FEMALE女;
	printf("s=%d\n", s);
	printf("MALE=%d\n", MALE男);
	printf("FEMALE=%d\n", FEMALE女);
	printf("1:%d\n", g_val);
	printf("hello\n");
	{				//局部开始
		int a = 10; //局部变量,生命周期从进入局部范围开始,到出局部范围结束
		printf("a=%d\n", a);
		printf("2:%d\n", g_val);
	}						//局部结束
	printf("3:%d\n", g_val);
	printf("g_val2=%d\n", g_val2);//外部文件内的全局变量,使用extern进行声明后可用
	return 0;
}
