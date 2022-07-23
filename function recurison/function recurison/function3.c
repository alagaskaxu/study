#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//函数递归
/*
	递归:程序调用自身的编程技巧称为递归(recurison). 
	一个过程或函数在其定义或说明中有直接或间接调用自身的一种方法,通常把一个大型复杂问题转化为与原问题相似的规模较小的问题来求解
	递归策略只需要少量的程序就可以描述出解题过程所需的多次重复计算,大大减少了程序的代码量
	递归的主要思考方式在于:大事化小

	递归的两个必要条件:
	1.存在限制条件,当满足这个限制条件时,递归便不再继续(如果能一直递归,没有限制就是死递归,最后会报错,栈溢出)
	2.每次递归调用后越来越接近这个限制条件(如果递归太多次,栈就会溢出,报错)

	Tips:
	栈区会存放一些临时空间,临时变量,如局部变量,函数形参等; 堆区用来动态内存分配
	每个函数调用,都会在栈区分配空间,所以太多次递归可能导致栈区溢出
	递归函数:1.不能死递归,有跳出条件,每次递归逼近跳出条件  2.递归层次不能太深
*/


void print(unsigned int n)			//递归,print(1234)就等于print(123)+printf(4)
{									//print(123)就等于print(12)+printf(3)
	if (n > 9)//如果没有条件就是死递归 //print(12)就等于print(1)+printf(2)
									//print(1)就等于printf(1)
	{								//每次都是打印个位数(即<=9的数),如果数大于9则print(123)(用print打印除去个位的十位百位千位等等)再加上printf(4)(打印个位数)
		print(n / 10);		//先进print(123)函数,123>9再进print(12)直到print(1)时,不用进print函数顺序执行printf,打印1的个位数
							//print(1)结束后,再是print(12)顺序执行printf打印12的个位数,print(12)运行结束后,接着print(123)顺序执行,打印123的个位3.以此类推先打印1再2然后3最后4
	}						//递归函数,先由外到内执行函数,最后一个递归函数运行结束后;再由里到外依次执行代码出来
						
	printf("%d ", n % 10);	
}

//不用递归,普通的模拟strlen函数
int my_strlen(char* str)	//arr[]数组名就是首元素地址,str指针指向数组地址(首元素地址)
{
	int count = 0;	//计数变量
	while (*str != '\0')
	{
		count++;	//计数+1
		str++;	//地址+1,即指针str从指向arr[0]变成指向arr[1]
	}
	return count;
}

//递归模拟strlen函数
int rec_strlen(char* str)
{
	if (*str !='\0')
	{
		return 1 + rec_strlen(str + 1);		//如果使用str++,会发现函数传入了str原本的值,留下了str+1的值;++str则是传入str + 1,留下str + 1;都改变了原本str的值,容易出错,使用str + 1简单好理解
	}
	else
	{
		return 0;	//str指向'\0'返回0,*str的值为'\0'时结束
	}
	
}

//n的阶乘
int fac(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n* fac(n - 1);
	}
}

//递归函数求第n个斐波那契数
//递归函数fib()效率太低,有大量的重复操作,n稍微大点就要计算很久而且容易溢出
int fib(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return fib(n - 1) + fib(n - 2);
	}
}

//普通函数求斐波那契
int pfib(int n)
{
	int a = 1, b = 1;
	int c = 1;		//c = 1,表示0<n<=2时的斐波那契数,即第1个和第2个数是1

	while (n > 2 )
	{
		c = a + b;	//第三个数开始等于前两个数之和
		a = b;
		b = c;
		n--;
	}
	return c;
}

//逆序字符串
void reverse_string(char* str);

int main() 
{

	//练习1:接受一个无符号整形值,按照顺序打印它的每一位
	unsigned int num = 0;
	scanf("%u", &num);	//%u 表示无符号整形 ,unsigned int类型
	//输入1234
	//递归 - 函数自己调用自己
	print(num);	//自定义打印每一位数字的函数

	//模拟实现strlen函数
	char arr[] = "abcd";
	printf("\n字符串长度为:%d\n", my_strlen(arr));
	printf("用递归求字符串长度为:%d\n", rec_strlen(arr));

	//递归与迭代(重复操作)不考虑栈溢出的情况
	//求n的阶乘
	int n = 0;
	printf("求n(n>0)的阶乘,n = ");
	scanf("%d", &n);
	printf("%d 的阶乘为 %d\n", n, fac(n));

	//求n个斐波那契数列,前两个数的和为第三个数,1 1 2 3 5 8 13 21 34 ...
	n = 0;
	printf("求n(n>0)个斐波那契数列,n = ");
	scanf("%d", &n);
	//普通循环求斐波那契,效率比递归好
	printf("第%d 个斐波那契数为 %d\n", n, pfib(n));

	printf("递归求第%d 个斐波那契数为 %d\n", n, fib(n));
	//递归函数fib()效率太低,有大量的重复操作,n稍微大点(n=50,可能就算不出了,而且超过int的长度)就要计算很久而且容易溢出

	//循环复习
	//求1/1-1/2+1/3-1/4+.....+1/99-1/100的值

	int i = 0;
	double sum = 0.0;
	/*
	for ( i = 1; i <= 100; i++)
	{
		if (0 == i % 2)
		{
			sum -= 1.0 / i;
		}
		else
		{
			sum += 1.0 / i;
		}
	}
	*/
	int flag = 1;
	for (i = 1; i <= 100; i++)
	{
			sum += flag* 1.0 / i;
			flag = -flag;
	}
	
	printf("1/1-1/2+...+1/99-1/100 = %lf\n", sum);
	
	//递归练习
	//将字符串逆序输出
	char chr[] = "abcdef";
	reverse_string(chr);
	printf("逆序字符串为 %s\n", chr);

	return 0;
}

//逆序字符串
//	 reverse_string(char* str)
void reverse_string(char str[])	//char str[]和char* str本质一样都可以
{
	
	char tmp = *str;	//存放数组str的首个元素
	int len = strlen(str);
	*str = str[len - 1];	//最后一个元素放第一个
	str[len - 1] = '\0';	//最后一个元素变为'\0'
	if (strlen(str + 1)>= 2 )//当字符串个数在两个以上才开始递归
	{
		reverse_string(str + 1);	//逆序首地址str+1的数组
	}
	
	str[len - 1] = tmp;		//将首元素放最后

}