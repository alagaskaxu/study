#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//字符串:用""括起来的一串字符
/*字符串的结束标准是\0的转义字符, 
在计算字符串长度时\0是结束标志,不算字符串的内容*/
int main() {
	//字符数组,数组:一组相同类型的元素
	char ac1[] = { "abc" };//数组元素实际有4个,最后为\0不显示
	char ac2[] = { 'a','b','c' };//没\0结束标志在c后面会有乱码,一般这样的数组自己在最后加上'\0'元素
	char ac3[] = {'a','b','c','\0'};//和1输出结果一样
	printf("ac1=%s\n", ac1);//输出abc字符串
	printf("ac2=%s\n", ac2);//输出abc字符加乱码的字符串(直到找到\0结束)
	printf("ac3=%s\n", ac3);//输出abc字符串
	int len = strlen("abc");//求字符串abc的长度
	printf("len=%d\n", len);//输出结果3,\0不算在字符串的内容不算在长度中
	printf("ac1size=%d\n", sizeof(ac1));//输出为4,sizeof求占用几个字节,一个英文字符占一个字节,中文占两个
	printf("ac1len=%d\n", strlen(ac1));//输出为3.只算字符串长度,不计算\0
	printf("ac2len=%d\n", strlen(ac2));//输出为随机数值

	return 0;
}