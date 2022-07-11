#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//指针
//指针与内存地址有关,32位地址线有2^32个地址编号(64位有2^64个地址)
//一个地址编号对应一个内存空间,一个内存空间占1字节(Byte)

int main()
{
	int a = 699324;//a在内存中要分配空间--4字节,699324d==十六进制(aabbc)H,两个十六进制为一字节(8位); 用&a可以得到a所在空间的第一个地址(最低位)
				//f10 调试,调出调试窗口中的内存窗口,&a(取a的第一个地址)可以看到a在内存中的地址,内存由低到高为bc ab 0a 00
				//一个内存空间从左到右(left-->right)为高4位到低4位,内存地址由低到高排序(low<--high),先存低位地址再存高位地址,故bc在最低的内存空间,然后是ab,0a,00
				//如果内存地址从高到低(h-->l)排序则为 00 0a ab bc ,得aabbc,由高到低看便于理解
	printf("a在内存中的地址为: %p\n", &a);//%p用于打印地址,&a取得a在内存空间中的第一个地址,而第二个地址就是第一个+1,以此类推最后一个地址(第四个)为第一个+3
						//地址每次运行都由系统自动分配

	int* pa = &a;//pa用来存放a的地址,在c语言中pa叫做指针变量,用*来定义指针变量
	//注意!!:  * 表示pa为指针变量; int 表示pa存储的地址所在的对象是int类型的(确定指针的范围4字节)

	char ch = 'c';
	char* pc;//定义一个字符指针pc
	pc = &ch;//表示指针pc 指向 ch 所在的地址

	*pa = 20;//这里的*叫解引用操作,解就是把该地址对应的东西解出来
			//此时*pa指通过pa的地址来找到a,再将20赋值给a(将20赋值给pa指向的地址所存放的对象a)
	printf("a= %d\n", a);

	//指针大小  输出全是4Byte(32位)或8Byte(64位),不同编译器大小可能不一样,但是指针大小在同一个编译器里都是相同的
	//指针的大小取决于地址的存储需要多少空间,32位的地址需要32位(bit)/8bit(一个内存空间存一字节(8位))=4字节,64位=64b/8b=8字节
	printf("int*= %d\n",sizeof(int*));
	printf("short*= %d\n",sizeof(short*));
	printf("long*= %d\n",sizeof(long*));
	printf("long long*= %d\n",sizeof(long long*));
	printf("char*= %d\n",sizeof(char*));
	printf("float*= %d\n",sizeof(float*));
	printf("double*= %d\n",sizeof(double*));

	//结构体 struct 用于描述,创建复杂对象,复杂类型

	struct stu  //创建一个学生类型stu; 注意:struct的大括号{}外有分号;  struct构造体一般放main函数外或者作为全局变量方便调用
	{
		//成员变量
		char name[20];//姓名
		int age;//年龄
		double score;//成绩
	};

	struct stu s = { "张三", 20, 85.5 };//创建一个学生类叫s,给s初始化
	printf("1姓名:%s ,年龄:%d ,成绩:%lf\n", s.name, s.age, s.score);// 结构体变量.成员变量  用来访问结构体的成员变量

	struct stu* ps = &s;//取s的地址
	printf("22姓名:%s ,年龄:%d ,成绩:%lf\n", (*ps).name, ps->age, ps->score);// 指针->成员变量(不用*直接用指针)  用指针来访问结构体的成员变量
										//*ps 解引用操作 就等于s ,需要() ,不用*则直接指针指向成员变量

	return 0;
}