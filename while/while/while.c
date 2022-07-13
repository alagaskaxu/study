#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//while 循环语句

/*
	while语法结构
	while(表达式)		while(exp)
		一条循环语句;			{
								多条循环语句;
							}
*/

//在循环中有break和continue会影响循环的执行逻辑
//break 跳出循环,用于永久的中止循环
//contine 继续,用于跳过本次循环中continue后面的代码,但没有完全中止整个循环继续
//而是跳过本次循环后继续后面的循环

int main()
{
	//输出一到十
	int i = 1;
	printf("while语句输出1-10:\n");
	while (i <= 10)
	{
		printf("%d ", i);
		i++;
	}

	i = 1;
	printf("\nwhile语句输出1-10(i=5时break跳出循环):\n");
	while (i<=10)
	{
		if (i == 5)//当i=5时,break跳出循环,循环结束,最后输出4
			break;
		printf("%d ", i);
		i++;
	}

	/*i = 1;
	printf("\nwhile语句输出1-10(i=5时continue出循环,跳过i++成为死循环):\n");
	while (i <= 10)
	{				//通过f10调试可以发现
		if (i == 5)//当i=5时,continue出循环,i没+1,i==5继续循环,最后1234然后死循环
			continue;//i==5,出这次循环,不执行下面代码,i==5回到while开头继续执行while循环,发现i==5执行continue死循环
		printf("%d ", i);
		i++;
	}
	*/
	
	//用continue只跳过i=5这次循环,则i++写在continue前
	i = 0;
	printf("\nwhile语句输出1-10(i=5时continue跳出一次循环,且不死循环):\n");
	while (i < 10)
	{
		i++;
		if (i == 5)//当i=5时,continue跳出i==5这次的循环(不执行continue后的代码),继续后面的循环
			continue;
		printf("%d ", i);
	}
	printf("\n");

	//练习1
	printf("输入一个字符:\n");
	char cha = '0';
	cha = getchar();//从文件或标准输入(键盘)中得到一个字符,不过getchar()规定的返回值是int类型的ASCII码值,虽然可以用char来定义,不过getchar还能读取数字和EOF(-1),所以建议用规定的int来定义getchar函数,防止BUG
	putchar(cha);//输出一个字符,类似printf("%c",ch);

	
	//持续输入字符(串),输出字符(串),直到文件结束或者遇到EOF
	printf("\n可持续输入字符直到文件结束:\n");
	int ch = 0;	//ch是int类所以ch存放的是字符的ASCII码
	//char ch = 0;//char和int只是字符还是ASCII的区别,都可以用%d输出ascii码,也可以用%c输出字符
	while ((ch = getchar()) != EOF)// getchar :从一个文件流(文件)或者标准输入(一般指键盘的输入)获取一个字符; EOF(-1) : end of file 表示文本文件结束符
		//在文本文件中,数据都是以字符的ASCII代码值的形式存放.ASCII代码值的范围是0~127,不可能出现-1,因此可以用EOF作为文件结束标志
	{
		putchar(ch);//输出一个字符,类似printf("%c",ch);
	}	//键盘上Ctrl+z按键就是EOF可以结束输入

		//回车(\n)也算字符也会被getchar和putchar,因为输入函数和键盘实际输入直接有个缓冲区(缓存区),
		//键盘打的所有字符先存入缓存区,遇到getchar再存入对应位置,遇到putchar输出之前缓冲区的内容
		//在上面输入一个字符时,如果多打几个,会全存入缓存区,遇到putchar输出一个,再遇到持续get输入和持续输出putchar时会把之前缓存区的字符全部get然后put全部输出
	//例子:
	//输入密码
	char password[20] = { 0 };
	printf("请输入密码: \n");//输入123,回车(\n)确认,在缓冲区中存在123\n,被输入函数scanf取走123,最后留下\n
	scanf("%s", password);//数组名本身就是地址,不用取地址符& ;scanf读取字符串会在空格和回车(\n)处停止,\n被留着缓冲区
							// 用 ^ 可以用来在特定地方停止,scanf("%[^\n]",password);表示遇到换行符停止,这样空格不会停止读入 ,%[^sdf]表示遇到s,d,f任意一个字符就停止读入
	//scanf("%[^\n]",password); 使用^,可以将空格也读入,存入password中

	//使用getcahr,最好先清理缓冲区
	int tmp = 0;	//中间变量tmp,用来清理缓冲区,充当垃圾桶
	while ( (tmp = getchar()) != '\n') //如果不用循环,只用一个getchar来清理,只能清理一个字符,而由于scanf遇到空格也会停止,如果输入的字符串中包含空格,那么空格后的字符都会在缓冲区
	{					//要完全清理缓冲区就需要使用while循环,一直清理到回车(\n)为止,而\n也正好是最后一个存入temp的字符
		;	//空语句,使得tmp一直被getchar的新字符覆盖,直到get到'\n'字符
	}
	putchar(tmp);//查看tmp里的字符,发现确实只剩一个回车符(\n)
	//getchar();//再用一个不赋值的getcahr来清空缓冲区,类似垃圾桶,就能解决缓冲区的问题

	printf("请确实密码(Y/N): ");
	char pass = getchar();//如果没有清空缓冲区,由于其它字符和回车(\n)在缓冲区,被getchar存入pass
	if (pass == 'Y'||pass == 'y')
	{
		printf("确认成功\n密码为:%s",password);//输入密码123 abc ,结果为123 可见空格后的字符被清理了
											//想完整保存123 abc,则需要使用scanf("%[^\n]",password);利用^ 来保存空格,强制规定只到回车(\n)才停止读入
	}
	else
	{
		printf("确认失败\n");
	}

	//练习2
	printf("\n只持续输出0-9的字符:\n");
	ch = 0;//int ch
	while ((ch = getchar() ) != EOF )//ctrl+z为EOF
	{
		if (ch < '0' || ch > '9') //如果ch不是0-9的数字则执行continue跳出本次循环,既不打印除数字外的字符
								//注意'',因为getchar()得到的是字符的ASCII码,0-9为字符,其ASCII码为48-57,不是十进制的0-9
			continue;
		putchar(ch);
	}

	return 0;
}