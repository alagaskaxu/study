#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//变量的作用域(变量名的可用范围)与生命周期
int main() {
	printf("hello\n");
	int a = 10;
	printf("a=%d\n", a);
	return 0;
}