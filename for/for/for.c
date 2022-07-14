#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//for循环语句
/*
	语句结构
		(初始化;判断部分;调整部分)
	for(表达式1;表达式2;表达式3)
		循环语句;
*/
//break 中止循环,跳出循环
//continue 继续,跳过本次循环,不执行后面的代码,开始下一循环的判断
// for循环中,从continue处跳过本次循环,然后执行调整部分的表达式3(如i+1),进入下一循环的判断; (带着i调整后的值进行下一个循环的判断)
//在while中,从continue处跳出本次循环时,根据代码的不同,调整部分不一定执行,i不一定会+1,进入下一个循环时i未被调整改变,可能会死循环

//建议:不可以在for循环内修改循环变量(i),防止for循环失去控制,变成死循环,产生bug
//建议:for语句的循环控制变量的取值采用"前闭后开区间"的写法 [) for(i=0 ;i<10 ;i++)
int main()
{
	printf("用for循环输出1-10\n");
	int i = 0;
	//		初始化;判断;调整
	for ( i = 1; i <= 10; i++)//输出1-10
	{
		printf("%d ", i);
	}

	//break在for中的效果
	printf("(\n在5时break)用for循环输出1-10\n");
	for (i = 1; i <= 10; i++)//输出1-10
	{
		if (i == 5)
			break;		//类似while,跳出循环,1234然后中止循环

		printf("%d ", i);
	}

	//continue在for中的效果
	printf("(\n在5时continue)用for循环输出1-10\n");
	for (i = 1; i <= 10; i++)//输出1-10
	{
		if (i == 5)
			continue;		//与while不太相同,continue跳过本次循环,但是执行表达式3,i+1,开始下一个循环的判断(类似回到for循环开始继续循环).
							//while中在continue处,直接跳出本次循环,根据代码不同,调整部分(表达式3)不一定执行,i不一定+1,用未调整的i的值进行下次循环的判断,下次循环可能会死循环

		printf("%d ", i); //输出1234678910 ,跳过5
	}

	//for循环的变种
	//变种1
	//判断部分省略(恒为真)就是死循环
	/*for (;;)
	{
		printf("变种1,死循环");
	}
	*/
	//省略初始化
	int j = 0;
	i = 0;
	for (; i < 3; i++)//i=0时进入循环,j循环结束,i+1=1进入循环,此时j的初始化被省略还是j=3,j循环结束,i+1依次类推,最后只能输出3次
					//由于省略了初始化,j一直为3,本想输出9次变为只输出了3次
	{
		for (; j < 3; j++)//i=0时,j加三次,输出三次
		{
			printf("\n省略初始化");
		}
	}

	//变种2,多变量
	for ( i = 0,j = 0; i < 2 && j<5 ; ++i, j++)
	{
		printf("\n多变量");//输出2次
	}

	//练习
	//几次循环
	for ( i = 0,j = 0; j=0; i++ , j++) //判断时j=0,0为假,不进循环,所以为0次循环
	{
		j++;
		printf("\n1");
	}

	return 0;
}