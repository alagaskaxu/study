#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void test() 
{
	static int a = 1;//static修饰局部变量,改变了局部变量的生命周期(实际上改变了变量的存储类型,其变量变为静态,不会动态创建和动态销毁)
	a++;			//内存一般分为栈区,堆区,静态区
					//局部变量,函数参数等临时变量在栈区(创建就是push入栈,销毁就是pop出栈)
	printf("%d", a);//堆区用来动态内存分配; 全局变量和static修饰的变量放在静态区(生命周期一直到程序结束)
}


//关键字
//由c语言提供,不能自己创造关键字,关键字不能做变量名
/*
	常见关键字: auto break case char const continue default do double
	else enum extern float for goto if int long register return
	short signed sizeof static struct switch typedef union unsigned
	void volatile while
*/

// #define  定义常量和宏  预处理指令  没有分号,赋值号
#define MAX 100		//定义常量MAX
				//宏指根据一系列预定义的规则替换一定的文本模式,类似替换文本,如:mul用x*y来替换mul(x,y)这个文本
#define mul(x,y) x*y  //定义宏mul(乘)  文本替换,不会改变优先级,由于x,y可能为表达式,有优先级,使得结果与预期不同,
						//故最好写成((x)*(y)),手动加上优先级(优先级:运算顺序)
int main() 
{
	// auto 自动的, 自动创建自动销毁的, 每个局部变量都是auto修饰的,新语法有其它用法(暂不考虑)
	auto int o = 10;//局部变量都是auto修饰,一般省略auto(软件会自动添加auto修饰)
	// break(跳出) continue(继续) switch case do while for用于循环语句中
	// default 默认,用于switch case语句
	// if else 用于选择语句
	// char 字符类型, const 常变量, float 单精度浮点型, double 双精度类型, enum 枚举类型
	// int 整形, long 长整形, short 短整形
	// void 无类型,空类型
	// signed 有符号数, unsigned 无符号数
	// static 静态,修饰函数和变量为静态
	// struct 构造体, union 联合体(共用体)
	// extern 声明外部符号变量
	// goto 用于goto语句
	// register 寄存器关键字,建议(希望)将被修饰的值放入寄存器,具体是否放入寄存器由编译器决定
	register int regnum = 100;//建议将regnum中的值存入寄存器,一般用不到
	// return 返回,用来返回函数值
	// sizeof 求类型的大小,以字节为单位, typedef 类型重定义
	// volatile 特征修饰符,告诉编译器该变量是易变的,希望编译器去注意该变量的状态,时刻注意该变量是易变的,每次读取该变量的值都重新从内存中读取

	// **#define和#include不是关键字,他们是预处理指令

	typedef unsigned int u_int;//typedef 类型重定义,将unsigned int定义为u_int(类似取个别名,方便书写)
	//unsigned int u = 100;//等于u_int u = 100;
	u_int u = 100;
	
	int i = 0;
	while (i < 10)//没有static则输出10个2,有static int a=1;输出2-11
	{
		test();//函数里不用static则每次进入test函数将把形参a设为1,a++=2,输出2,因为a是局部变量,出作用域使a生命周期结束,a自动销毁
				//函数使用static int a=1;则a为静态局部变量,出工作域也不会销毁,a的值会保留
				//static修饰局部变量会改变局部变量的生命周期(本质上是改变了变量类型,使变量放在静态区),使其类似全局变量,直到程序结束才销毁
		i++;	//static修饰的静态变量不用放在函数外,便于程序的模块化
	}

	extern int g_val; //extern声明外部变量g_val;一般声明放在开头,main函数外方便
	extern int s_g_val; //extern声明外部变量s_g_val(静态的)
	printf("\nglobal value test= %d\n", g_val);//声明后可以使用外部的g_val全局变量
	//printf("static global test=%d\n", s_g_val);//s_g_val会保错,无法解析的外部符号
				//static修饰的全局变量只能在自己所在的源文件(static add.c)内部使用
	//全局变量能被外部使用是因为有外部链接属性,但被static修饰后变为内部链接属性,不能用于外部,但生命周期不变

	extern int add(int, int);//声明外部函数add
	extern int sub(int m, int n);//声明外部函数sub 括号()里只要类型与要调用函数格式对应就行,形参可以不一样或者不写
	int a = 0, b = 0, sum = 0, dif = 0;
	a = 30;
	b = 20;
	sum = add(a, b);//要使用自己写的外部的add函数,先声明函数
	dif = sub(a, b);//要使用自己写的外部的sub函数,先声明函数
	printf("a+b= %d\n", sum);//当外部函数被static修饰时,结果和静态全局变量一样,保错为无法解析
	printf("a-b= %d\n", dif);//当外部函数被static修饰时,结果和静态全局变量一样,保错为无法解析

	// #define  定义常量和宏  预处理指令
	printf("MAX = %d\n", MAX );
	int acc = 0, acc2 = 0;//acc两数积
	acc = mul(a, b);//就等于acc = a*b; 宏文本替换
	acc2 =mul(a+2, b);//acc2 =a+2*b; 30 + 2*20=30+40=70  完全替换,不会加优先级
	printf("mul宏 a*b=%d , %d\n", acc, acc2);
	return 0;
}