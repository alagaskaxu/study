#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//指针初阶与进阶
//指针:编程语言中的一个对象,利用地址,它的值指向存在电脑存储器中另一地方的值.地址指向所需的变量单元
//一个内存单元占一字节对应一个地址编号
//int* pa; 用来存放地址的变量叫指针变量,pa为int型的指针变量
//指针变量在32位平台占4字节(32bit),在64位平台占8字节(64bit)
int my_strlen(char* str);
int my_strlen2(char* str);
int main()
{
	int a = 10;	//内存中占4字节
	int* pa = &a;	//取a的首地址存入pa指针,用来存放地址的变量叫指针变量
	*pa = 20;	//将指针pa指向的变量赋值为20

	//指针和指针类型
	char* pc;	//char类型的指针
	float* pf;	//float类型的指针
	printf("指针大小 %d\n", sizeof(pa));	//4
	printf("指针大小 %d\n", sizeof(pc));	//4
	printf("指针大小 %d\n", sizeof(pf));	//4

	//指针类型的意义
	a = 0x11223344;	//32位平台,16进制最大为0xffffffff,一个f为15占4bit(1111)
	pc = &a;	//char* pc;
	*pc = 0;	//char类型指针虽然占4字节,但是char类型原本为1字节的类型
	printf("char类型指针改int a=%x\n", a);	//11223300 ,char类型一字节,而int类型 44占一字节被char类型的指针改为00
	int arr[10] = { 0 };	//数组名为首元素地址
	int* p = arr;	//数组名就是首元素地址就是指针
	pc = arr;
	printf("p的地址为 %p\n", p);	//p和pc的地址一样
	printf("p+1的地址为 %p\n", p + 1);	//p+1的实际地址为p的地址+4(int类型的+1下一个地址要跳过一个int类型(4字节)即4个地址编号)
	printf("pc的地址为 %p\n", pc);
	printf("pc+1的地址为 %p\n", pc + 1);	//pc+1的地址为pc+1(char类型的+1下一个地址要跳过1个char类型(1字节)即1个地址编号)

	/*
		1.指针类型决定了:指针解引用时的权限有多大(简单理解:指针存放首元素地址,指针类型决定了从首地址开始一共可以访问几个地址,再结束)
		2.指针类型决定了:指针+1的步长(指针向前或向后走一步,能走多长字节),如int类型的指针+1一步就是4字节,char类型的指针一步为1字节,double类型的指针走一步就+8字节
	*/

	//指针的解引用: *pa ,表示pa指针对应的那个元素,解引用可以通过*pa来改变对应变量的值

	//野指针:野指针就是指针指向的位置是不可知的(随机的,不正确的,没有明确限制的)
	//野指针一般会导致程序崩溃
	/*
	* 野指针的成因:
	* 1.指针未初始化
	* 2.指针越界访问
	* 3.指针指向的空间被释放了
	*/
	//1.指针未初始化导致野指针
	// int* pb;	//pb是一个局部的指针变量,局部变量不初始化的话,默认是随机值
	// *pb = 20;	//pb指向的就是随机的地址,pb是野指针,*pb不可确定非法访问内存了

	//2.指针越界导致野指针
	/*
	p = arr;
	int i = 0;
	for ( i = 0; i <= 10; i++)	//p多加一次,一共加了11次,最后一次p指针越界,超过arr的大小了,最后变成野指针
	{
		*p = i;
		p++;
	}
	*/

	//3.指针指向的空间被释放了
	//详细看动态内存的知识

	/*
	* 如何规避野指针
	* 1.指针初始化
	* 2.小心指针越界
	* 3.指针指向空间被释放时 将指针置为NULL空指针, p = NULL;
	* 4.指针使用之前检查有效性(指针是否为空,是否为野指针)
	*/
	//当前不知道指针应该初始化为什么地址时,直接初始化为NULL空指针
	int* pb = NULL;

	//指针运算
	//指针+-整数
	//如上面的p+1,pc+1,p++

	//指针-指针:得到两个指针之间的元素个数  (指针+指针没有意义)
	//!!指针相减的前提是:两个指针指向同一空间,如:同一个数组
	p = &arr[0];
	pb = &arr[9];
	printf("&arr[9] - &arr[0] = %d\n", pb - p);	//9,两个指针之间一9个元素

	//指针的关系运算
	float values[5];
	float* vp;
	for ( vp = &values[0]; vp < &values[5]; vp++)	//vp < &value[5] 指针的关系运算, vp++ 指针+整数
	{
		*vp = 0;	//*vp对应的变量赋值为0
		printf("%d ", *vp);	//0 0 0 0 0 
	}

	//my_strlen - 求字符串长度
	int len = my_strlen("abc");	//传的参数为char类型的指针 指向字符串的首元素(a)的地址
	printf("\nstrlen = %d\n", len);

	int len2 = my_strlen2("abcd");
	printf("\nstrlen2 = %d\n", len2);

	//指针与数组
	int ar[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("ar = %p\n", ar); //数组名就是数组首元素的首地址
	printf("&ar[0] = %p\n", &ar[0]); //首元素地址
	p = ar;	//int* p = ar; 指针p指向数组首元素地址
	int i = 0;
	for ( i = 0; i < 10; i++)
	{
		//p + i 就是指向了数组下标为i的元素,*(p + i) 就是 ar[i]的值
		printf("%p <=> %p\n", &ar[i], p + i);	//对应地址一样
		printf("*(p + i) = %d\n", *(p + i));
		//等价: ar[i] <==> *(ar + i) <==> *(p + i) <==> *(i + p) <==> *(i + ar) ?== i[ar]
	}

	//ar[i] ?==? i[ar] 结果对吗?等价吗
	printf("ar[2] = %d\n", ar[2]);	//3
	printf("p[2] = %d\n", p[2]);	//3,p[2]与ar[2]等价,因为都是同一指针, p = ar;原理: p[2] => *(p + 2) => *(ar + 2) => ar[2]
	printf("2[ar] = %d\n", 2[ar]);	//3,结果正确
	printf("2[p] = %d\n", 2[p]);	//3,同理
	//原理: 编译器编译时 []为操作符,将 ar[2] 编译为*(ar + 2) ,与*(2 + ar)等价
	//*(2 + ar)转为 []表示 就是 2[ar]
	//因为ar就是指针,p = ar;所以 ar[2] 与 p[2] 也等价

	//二级指针:用来存放指针变量的地址
	//指针变量也是变量,既然是变量就有对应的地址,指针变量的地址就存放在二级指针里

	a = 10;	//int a = 10;
	pa = &a;//一级指针, int* pa = &a;	//int表示为pa指向的变量类型是int型的整形变量, * 表示pa为指针变量. 总体表示为 pa为指向int整形变量的指针变量,pa的值为a的地址
	int** ppa = &pa;//二级指针ppa
	//第一个int* 表示ppa指向的变量类型是int类型的指针变量,第二个 * 表示ppa为指针变量
	//总体理解为 ppa为指向int*(指向int整形的指针)变量的指针变量,ppa的值为pa指针的地址

	//如何通过二级指针找到变量
	//*ppa 与 pa等价,ppa的值是pa的地址,对ppa一次解引用得到pa的值,*ppa == pa
	//由于*pa == a,所以对*ppa再解引用就能找到对应的变量 a , * *ppa == a;
	**ppa = 20;	//等价 a = 20;
	printf("**ppa = %d\n", **ppa);

	//三级指针,按照int** ppa类推
	int*** pppa = &ppa;
	// int**表示为二级指针类型,最后的 * 表示pppa为指针变量,总体为: pppa是指向二级指针类型的指针变量,即pppa为三级指针,pppa的值为二级指针的地址
	// *pppa == ppa;  **pppa == pa; ***pppa == a;
	***pppa = 30;	// 等价 a = 30;
	printf("***pppa = %d\n", ***pppa);

	//指针数组:用来存放指针元素的数组
	char ch[5] = { 0 };	//字符数组
	//arr,ar为整形数组

	//创建整形指针数组parr
	int* parr[5];	//5个整形指针类型的元素
	char* pch[5];	//字符指针数组pch的创建



	return 0;
}

//利用计数器count求字符串长度
int my_strlen(char* str)
{
	int count = 0;
	while (*str != '\0')	//指针指向的元素不是'\0'时
	{
		count++;
		str++;	//指针后移到下一元素
	}
	return count;
}
//利用同一空间指针相减得到元素求字符串长度
int my_strlen2(char* str)
{
	char* start = str;
	while (*str != '\0')	//指针指向的元素不是'\0'时
	{
		str++;	//指针后移到下一元素
	}
	return str - start;	//指针相减得到两个地址之间的元素个数
}

