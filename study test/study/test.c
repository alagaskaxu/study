#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int main()
//{
//	char ch  =  'a'; //�ַ���
//	int age = 20; //����
//	printf("bit����\n");
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
int age = 100;//ȫ�ֱ���,����������һ��
int main() {
	int age = 20;//�ֲ�����,�ֲ�����
	float weight = 50.5;
	double sum = 0;
	scanf("%d %f", &age, &weight);
	sum = age + weight;
	printf("age=%d\n", age);
	printf("weight=%f\n", weight);
	printf("sum=%lf\n", sum);
	return age;
}
