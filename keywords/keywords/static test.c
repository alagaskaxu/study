#define _CRT_SECURE_NO_WARNINGS

int g_val = 2022;//全局变量,不能重名,整个项目工程中都可以使用,生命周期直到程序结束
static int s_g_val = 1111;//static修饰的全局变量使变量只能在自己所在的.c源文件内部使用,外部其它源文件不能使用
	//全局变量能被外部使用是因为有外部链接属性,但被static修饰后变为内部链接属性,其它源文件不能链接到这个静态的全局变量
	//类似原本 全局变量的外部属性 变为了 局部变量的内部链接属性,称为静态全局变量,但是生命周期还是持续到程序结束
int add(int x, int y)
{
	return x + y;
}

static int add1(int x, int y)//当函数被static修饰时,和全局变量效果一样
{					//函数变为静态函数add1,内部链接属性,无法被外部调用,只能在源文件(static test.c)内部使用
					//静态函数只是让该函数只能在本文件使用,可以避免重名等,但是不意味着函数里的变量也变为静态
	return x + y;	//静态函数中的 int a; 和普通函数是一样的,会自动销毁,而不是变为static int a;
}

int sub(int x, int y)
{
	return x - y;
}
