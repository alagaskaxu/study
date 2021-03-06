#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
	数组:一组相同类型元素的集合
	一维数组：(行)
	type_t arr_name [const_n];
	type_t 指数组的元素类型  
	const_n 一个常量表达式,用来指定数组大小
	arr_name 表示数组名,本质为数组首元素的地址

	二维数组 :(行,列)
	type_t arr_name [const_n] [const_n];	//行的大小可以省略,列的大小不能省略
*/

void bubble_sort(int ,int);	//冒泡排序

int main()
{

	int v[8];	//数组的定义;名叫v的数组,数组元素为int类型,数组大小为8个元素
	//int a[10] = { 0 };	//数组的初始化,部分初始化,第一个元素为0,剩下的默认为0
	//int a[10] = { 1,2,3,4,5,6,7,8,9,10 };	//数组的初始化,完全初始化
	int a[10] = { 1,2,3,4,5,6,4 };	//数组的初始化,部分初始化
	//int a[] = { 1,2,3,4,5 };	//根据初始化内容确定数组大小与a[5]={1,2,3,4,5};等价

	//字符(串)数组	(tips:字符串数组最后有一位隐藏的结束字符'\0',除非每一个字符都自己初始化如ch2)
	char ch1[5] = {'b','i','t'};//字符串数组,大小为5,元素类型为字符型,部分初始化	{'b','i','t',0'\0',0'\0'}
	char ch2[] = {'b','i','t'};	//字符串数组,大小为3,元素类型为字符型	{'b','i','t'}
	char ch3[5] = "bit";	//和char ch3[5] = {"bit"};等价和ch1数组类似大小为5  {'b','i','t',0'\0',0'\0'}
	char ch4[] = "bit";		//和ch4[]={'b','i','t','\0'}等价,大小为4 	{'b','i','t','\0'}

	//数组的使用： []下标引用操作符,就是数组访问的操作符;数组下标从0开始,第一个元素下标为0,第二个元素的下标为1
	int arr[10] = { 0 };
	arr[4] = 5;	//下标为4是第五个元素,赋值为5
	printf("%d\n", arr[4]);
	int sz = sizeof(arr) / sizeof(arr[0]);	//sz的值为数组的大小; sizeof求变量在内存中占几字节,arr表示数组名,本质为数组首元素的地址sizeof(arr)求数组arr在内存中一共占几字节
											//sizeof(arr[0])求数组第一个元素在内存中占几个字节,int类型应该是4字节
	int len1 = sizeof(ch1) / sizeof(ch1[0]);	//5 strlen = 3 ,char类型的字符串求字符串长度用strlen,因为字符串最后有隐藏的'\0'不能用sizeof,sizeof只会求出数组大小,无法求出字符串大小
	int len2 = sizeof(ch2) / sizeof(ch2[0]);	//3	strlen = ??
	int len3 = sizeof(ch3) / sizeof(ch3[0]);	//5	strlen = 3
	int len4 = sizeof(ch4) / sizeof(ch4[0]);	//4 strlen = 3
	printf("len1 = %d strlen = %d\n", len1 ,strlen(ch1));
	printf("len2 = %d strlen = %d\n", len2 ,strlen(ch2));	//没有'\0'字符串结束符,strlen()输出随即值;原理:strlen()遇到'\0'停止计数
	printf("len3 = %d strlen = %d\n", len3 ,strlen(ch3));
	printf("len4 = %d strlen = %d\n", len4 ,strlen(ch4));

	printf("arr数组的值为: ");
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

	//一维数组在内存中怎么存放的
	printf("\n数组arr在内存中的地址为:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("&arr[%d] = %p\n", i, &arr[i]);	//&取地址符,取出arr[i]的地址,打印地址用%p(用地址的格式打印)
									//32位的地址格式:十六进制,一共八个十六进制数,不够自动补0;一个十六进制数占4位(0x f = 1111)则一个地址占4字节(32个二进制数,32位)
									//64位的地址格式:十六进制,一共16个十六进制数位,不够自动补0;一个地址占8字节(64个二进制数,64位)
	}
	//每个元素之间相差4个内存地址,一个内存地址表示一个内存空间,一个内存空间占一个字节(8bit位),一个元素占4个字节,就是int类型的大小;如果是char类型则一个元素占1个字节(即1个地址)
	//由个元素地址可见:	1.一维数组在内存中是连续存放的!	2.随着数组下标的增长,地址由低地址到高地址变化,即数组首元素为地址,最后一个元素为高地址,由低到高存放

	//实践:

	int ar[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("p指针打印ar数组的值: ");
	int* p = ar;	//数组名是数组首元素的地址,将数组地址赋值该指针p,整形指针变量int*	 用来存放整形变量的地址,32位的地址占4字节,所以指针 p 也占4字节和int类型无关
	int i = 0;
	for ( i = 0; i < 10; i++)
	{
		printf("%d ", *p);	//*p 表示 p指针地址指向的元素
		p++;	//p = p + 1;	int类型指针p加1,不是内存地址+1,而是表示从这个地址的内存编号跳到下一个地址的首个内存编号(内存地址);
	}			//对于int类, 实际上是内存地址 + 4也是int指针p + 1;各个类型的指针加1对应的实际地址 + 几都不一样

	//二维数组
	int brr1[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12 };	//3行4列的二维数组的初始化(创建和赋值)	,完全初始化{ {1,2,3,4} , {5,6,7,8} , {9,10,11,12} }
	int brr2[3][4] = {1,2,3,4,5,6,7 };	//3行4列的二维数组的初始化(创建和赋值)	,部分初始化{ {1,2,3,4} , {5,6,7,0} , {0,0,0,0} }
	int brr3[3][4] = { {1,2},{3,4},{5,6} };	//3行4列的二维数组的初始化(创建和赋值)	,部分初始化{ {1,2,0,0} , {3,4,0,0} , {5,6,0,0} }
	//3行4列数组就是3个大小为4的一维数组组成的
	//可以理解为:br[3][4]就是由一维数组br[0] [4](br[0]为数组名),br[1] [4] , br[2] [4] 这三个一维数组组成的,数组名分别为br[0], br[1], br[2]

	int br[][4] = { {1,2},{1,2,3},{1,2,3,4} };	//3行4列 行的大小可以省略列的大小不能省(本质上就是一维数组的大小为常量表达式)
		//{ {1,2,0,0} , {1,2,3,0} , {1,2,3,4} }
	//如果列数不确定则无法判断下一行的元素是哪些(无法确定下一行从哪开始)
	//二维数组的使用:使用[]下标来访问元素,行号列号从0开始.a[0][0]为a数组的首元素(第1行第1列的元素)
	printf("打印二维数组br[3][4]的值为\n");
	for (int i = 0; i < 3; i++)		//i为行,j为列
	{
		for (int j = 0; j < 4; j++)
		{
			printf("br[%d][%d]= %d  ", i, j, br[i][j]);
		}
		printf("\n");	//打印完一行就换行
	}

	//二维数组在内存中如何存储
	printf("打印二维数组br[][4]各元素的地址为\n");
	for (int i = 0; i < 3; i++)		//i为行,j为列
	{
		for (int j = 0; j < 4; j++)
		{
			printf("br[%d][%d]= %p   ", i, j, &br[i][j]);	//打印地址
		}
		printf("\n");	//打印完一行就换行
	}
	//可以发现,类似一维数组加长了,每个元素之间还是相差相同的内存地址数(4个地址)
	//每行之间的两个元素也相差4个地址,br[0][3]与br[1][0]也一样相差4个内存地址
	//和一维数组一样地址是连续递增的! 依次增加4个地址(4字节,int类型的大小)
	//一行内部是连续的,跨行也是连续的

	//用指针实践,连续性
	int* q = br;
	printf("用指针q取出b[][4]的全部元素:\n");
	for ( i = 0; i < 12; i++)
	{
		printf("%d ", *q);
		q++;	//int指针加1,指向下一个整形的地址
	}

	//数组作为函数参数
	//冒泡排序
	int pop[] = { 9,8,7,6,5,4,3,2,1,0 };
	//排序为升序
	int n = sizeof(pop) / sizeof(pop[0]);//确定数组个数,进而确定要进行几次冒泡排序；n个数，n-1次排序
	//函数内无法用sizeof准确求出数组大小,必须在调用函数前求出数组大小,传入函数
	printf("\npop数组: ");
	for (i = 0; i < n; i++)
		printf("%d ", pop[i]);	//打印一开始的pop数组

	//冒泡排序函数
	bubble_sort(pop,n);	//冒泡排序：两两相邻的元素进行比较，并且可能交换
	//数组传参,实际上不是传数组,而是传数组首元素的地址(类似指针变量)
	printf("\n冒泡排序后:\n");
	for ( i = 0; i < n; i++)
		printf("%d ", pop[i]);

	//数组名是什么?  首元素的地址
	//验证,数组名为首元素的地址
	printf("\npop数组的地址: %p\n", pop);
	printf("pop[0]的地址: %p\n", &pop[0]);
	//地址一样
	//但是有两个例外
	//1. sizeof(数组名)且数组名为实参时,此时数组名表示整个数组,得到整个数组所占内存的大小; 数组名为形参时,数组名就是指针变量是地址
	//2. &数组名, 此时数组名表示整个数组,取出整个数组的地址
	printf("sizeof(pop)的结果为: %d\n", sizeof(pop));
	printf("&pop的结果为: %p\n", &pop);	//取出的整个数组的地址,数组的地址就是数组首元素的地址,但是两者意义不一样

	//证明&pop和pop的意义不一样,pop和&pop[0]等价
	printf("&pop+1的结果为: %p\n", &pop + 1);	//与&pop相差了一整个pop数组的地址,相差40字节,可以理解为指向了下一个数组
	printf("pop+1的结果为: %p\n", pop + 1);		//与pop相差了一个int类型的地址,相差4字节,可以理解为指向了下一个元素pop[1]
	printf("&pop[0]+1的结果为: %p\n", &pop[0] + 1);//与pop+1 一模一样,可以理解为指向了pop[1]

	//综上可得,虽然 &pop 和 pop 和 &pop[0] 取到的值都相同,但是 &pop 的意义不一样,为取得整个数组的地址
	// &pop 取到了整个数组的地址,指针+1会以一整个数组为单位进行跳转,指向下一个数组
	// pop 和 &pop[0]等价, 仅仅取得数组首元素的地址,指针+1会以一个元素为单位进行跳转,指向下一个元素

	return 0;
}

void bubble_sort(int arr[],int n)	//传入的是首元素地址(本质是指针变量),也因为是指针所以改变函数内的数组,主函数中的实际数组也会改变
{							//sizeof(arr)得到的其实是指针变量的大小(32位指针变量大小为4字节(一个地址的大小);64位为8字节)
	//int sz = sizeof(arr) / sizeof(arr[0]);//确定数组个数,进而确定要进行几次冒泡排序；n个数，n-1次排序
	//在创建的函数中使用sizeof实际求的是指针的大小,所以无法求出想要的数组大小
	int i = 0;
	for ( i = 0; i < n - 1; i++)
	{
		//一次冒泡排序的过程
		int j = 0;
		//简单算法优化
		int flag = 1;	//用来判断第一次冒泡排序时有没有交换过元素,如果第一次没交换过元素,则证明数组是有序的,不需要排序
		//可以减少运算次数
		for ( j = 0; j < n-1-i ; j++)
		{
			if (arr[j] > arr[j + 1])	//如果前一个数大于后一个数则交换位置
			{
				//交换位置
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;	//交换过元素,flag标志置0
			}
		}
		//简单优化
		if (1 == flag)
		{
			break;		//一次元素都没交换过表明已经按序了则跳出循环
		}				//有效减少差不多有序的数组的排序次数,如{0,1,2,3,4,5,6,7,8,9}不用全部循环运算一遍,直接得出是有序的直接跳出

	}

}