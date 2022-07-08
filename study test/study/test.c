#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int main()
//{
//	char ch  =  'a'; //字符类
//	int age = 20; //整形
//	printf("bit比特\n");
//	printf("%d\n", 100);
//	printf("%d\n",age);
//	printf("%d\n", sizeof(char));
//	printf("%d\n", sizeof(short));
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof(long));
//	printf("%d\n", sizeof(long long));
//	printf("%d\n", sizeof(float));
//	printf("%d\n", sizeof(double));
//	return 0;
//}
int age = 100;//全局变量,不建议名字一样
int main() {
	int age = 20;//局部变量,局部优先
	float weight = 50.5;
	double sum = 0;
	scanf("%d %f", &age, &weight);
	sum = age + weight;
	printf("age=%d\n", age);
	printf("weight=%f\n", weight);
	printf("sum=%lf\n", sum);
	return age;
}
