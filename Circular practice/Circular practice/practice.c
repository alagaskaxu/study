#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>		//system函数的头文件,vs2019好像不引头文件也可以使用,不报错
#include <string.h>		//strlen的头文件
#include <Windows.h>	//sleep函数的头文件
//循环练习

//循环遍历找一个数字x
/*
int binsearch(int x, int v[], int n)//数组作为函数参数的时候，实际只相当于传递一个数组首地址（和指针作用是一样的），
						//而不是为数组分配空间，和实际声明定义的数组是有区别的，这个可以不指定大小
						//可以用length=sizeof(a)/sizeof(a[0])来求数组长度大小
						//好的习惯：当数组作为函数参数时，最好将数组大小也作为函数的一个参数,如此函数的n
{
	int a = 0;
	for (int i = 0; i < n; i++)	//从头到尾遍历数组,数组很大时计算较慢
	{
		if (x == v[i])
			return i;		//返回第一个数字x的位置
	}
	return -1;
}
*/
//二分查找法,比遍历快,但是数有重复时,找到的数不一定是按顺序的第一个满足要求的数
int binsearch(int x, int v[], int n)
{
	int left = 0, right = n - 1;//二分查找法,左边的数组下标为 0,右边的数组下标为总大小(n)-1
	int mid = 0;//定义二分查找的中间值(平均值)
	//二分查找时,如果第一个数或者最后一个数为目标x,也能找到.甚至可以先判断left和right的值是否就是目标x,如果是直接返回
							//如果写成left != right ,left == right最后一次循环不会执行,少测一个数,left == right直接跳过了循环,通过调试发现i直接等于最后运算过的值i =left=right
	while (left <= right)	//重复多次二分查找,来得到结果
	{						//当left在right左变时保持循环,当left==right时是最后一个数,判断完最后一个数,循环结束
		//下面为一次二分查找的结果
		mid = (left + right) / 2;	//mid为左右下标的中间值(平均值)
		if (v[mid] < x)		//如果中间的值小于要查找的值x,由于递增则中间值左边的直接舍去,直接开始查找(mid+1)中间值右边到right之间的值
		{
			left = mid + 1;		//如果为left = mid ;假设当v[mid=5]<x;left=mid=5,right=6时,
								//下次循环 mid=11/2=5,v[5]还是<x,left=mid=5,right=6,最后变为死循环
		}						//综上,left = mid+1
		else if (v[mid] > x)	//v[mid]>x时,right向左移动,原理同上,最后right = mid -1;
		{
			right = mid - 1;
		}
		else	//v[mid] = x ;找到结果
		{
			return mid;
		}
		
		//一次二分查找结束
	}
	//return -1;	//可以直接写return -1;返回到主函数,为了便于代码理解,写成if函数
	if (left > right)	//最后一次循环结束,如果还没有v[mid] = x;则表示找不到想要的数
						//而(left == right)最后一次循环结束后,没有找到值x,则不是left+1,就是right-1,因left == right,所以left > right,相差1
	{
		return -1;	//-1 为自定义的值,在主函数内设置为未找到
	}
	return -1;
}

int main()
{
	//n的阶乘
	int i = 0,acc = 1,n= 0; //acc为乘积
	printf("求n的阶乘,输入n为:\n");
	scanf("%d", &n);
	for ( i = 1; i <= n; i++)
	{
		acc = acc * i;		//acc = 1*2*3*4*..*n
	}
	printf("%d的阶乘为: %d\n", n, acc);

	//1!+2!+3!+...+10!(!为阶乘符号)
	int j = 0;
	int sum = 0;
	for ( i = 1; i <= 10; i++)	//双循环思路:1!+2!+3!+..n!,所有每个数的阶乘都算一遍再加起来
	{
		acc = 1;//!!!!每次进入阶乘计算时将乘积acc重置为1
		for (j = 1; j <= i; j++)
		{
 			acc = acc * j;		//acc = 1*1; acc = 1*2; acc = 1*2*3*...*i; acc=i!
		}
		sum += acc;	//sum = sum + acc; sum = 0+1; sum = 1+1*2 = 3; sum = 3+1*2*3=9 ;
					//sum = 1+1*2+1*2*3+....+1*2*3*...*i = 1!+2!+3!+...+i!
	}
	printf("1-10阶乘的和为: %d\n", sum);

	//1-n的阶乘
	n = 0,sum = 0, acc = 1;
	printf("求1-n的阶乘之和,输入n为:\n");
	scanf("%d", &n);
	for ( i = 1; i <= n; i++) //n改为10就是1-10的阶乘和
	{
		acc = acc * i;	//单循环思路:(n-1)!*n=n!,n!不需要重新从1算起,只要用前面(n-1)的阶乘再乘上n就得到n!
		sum = sum + acc;
	}
	printf("1-n阶乘的和为: %d\n", sum);

	//在一个有序数组中查找具体的某个数字.
	//编写int binsearch(int x,int v[],int n);在递增数组中查找x

	int a[10] = {0,1,2,3,4,5,6,7,8,9}, x = 7;
	//在a有序数组中查找7
	int sz = sizeof(a) / sizeof(a[0]);//求出数组元素的总个数
	i = 0;
	i = binsearch(x, a, sz);	//二分查找找出是否有7,如果数有重复,二分法找到的数不一定是按顺序的第一个满足要求的数
	if (-1 == i)
		printf("数组a[10]未找到对应数字%d\n",x);
	else
		printf("a[%d] 为数字x = %d", i, a[i]);

	//编写代码,演示多个字符从两端移动,向中间汇聚的效果
	//welcome to c!!!
	//###############
	char arr1[] = "welcome to c!!!";
	char arr2[] = "###############";
	int left = 0;	//左下标
	int right = strlen(arr1) - 1;	//strlen函数,求字符串长度,到'\0'结束,'\0'不计算在长度内; sizeof操作符求定义的变量生效后所占的内存数(变量在内存中占多少字节大小)
							//由于字符串结尾有一个隐藏的'\0'字符,所以用sizeof计算字符串数组的元素个数,会把隐藏的'\0'也计算在内得出数组实际的元素个数,而隐藏的'\0'一般用不到且不建议更改它(会导致字符串找不到结束符)
							//本意是想求字符串最右的字符的下标,用sizeof会比预想的多一个'\0'字符,相比用strlen求出字符串的长度会大1

	while (left <= right)	//当left与right交错过后,所有元素替换打印完毕
		//最后一次循环可能是left == right ,或者left+1=right时,具体看字符串长度是奇数还是偶数,但是最后一次循环打印完结果后,left一定会大于right,然后循环结束,所以循环的判断条件为left<=right
	{
		//一次数组的替换
		arr2[left] = arr1[left];//用1数组左边的元素替换2数组左边的元素
		arr2[right] = arr1[right];
		system("cls");	//执行清屏指令
		printf("%s\n", arr2);
		Sleep(500);	//sleep函数,单位为ms;睡眠500ms(等待500ms)
		left++;
		right--;
	}

	//模拟用户登录情景,并且只能登录三次.(只允许输入三次密码,如果密码正确则提示登录成功,如果三次均输入错误,则推出程序)
	i = 0 , j = 3;  //之前定义过,直接赋值初始化
	char password[20] = {0};
	//假设正确密码为字符串"123456"
	for ( i = 0; i < 3; i++) //最多输入三次,循环3次
	{
		j--;
		printf("(正确密码为123456)请输入密码:\n");
		scanf("%s", password);
		//if ("123456" == password)	//两个字符串的比较,不能使用 ==等号,而是使用strcmp函数(字符串比较函数)来专门比较字符串
		//strcmp(str1,str2);如果str1<str2返回<0的值; str1 == str2 返回值为0;str1>str2返回>0的值
		//str1 = abcd ;strcmp函数一个字符一个字符去比较其ASCII码的值的大小,abc都一样为0
		//str2 = abcccc ;到第四个字符d和c时str1的d的ASCII码>c的ASCII码,得到>0的值;d>c最后直接返回>0的值;不看整体字符串的长度,而是比较单个字符的大小
		if (strcmp(password, "123456") == 0) //如果字符串相等,这strcmp函数返回值为 0
		{
			printf("密码正确,登录成功\n");
			break;
		}
		else
		{
			printf("密码错误,还有%d次机会\n", j);
		}

	}
	//输入3次密码后,for循环结束接下来执行后面的代码
	if (3 == i)//当密码正确时break,i一定小于3; 当i=2时第三次输入密码,如果正确break,i仍为2, 如果密码错误i++,i变为3.
				//只有3次循环结束(即输入过三次密码),密码全部错误时,i才会等于3; 避免密码正确也输出if里的失败语句
	{
		printf("三次密码均错误,退出程序\n");
	}



	return 0;
}