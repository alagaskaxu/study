#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//do while���
/*
	�﷨�ṹ
	do
		ѭ�����;
	while(���ʽ);
*/

//break ������ֹѭ��
//continue ��do while�����,��������ѭ��,��ִ��continue��Ĵ���,ֱ�ӽ���ѭ���������ж�

int main()
{
	//���һ��ʮ
	printf("��do while������һ��ʮ:\n");
	int i = 1;
	do
	{
		printf("%d ", i);
		i++;
	} while (i <= 10);

	//break��do while����е�Ч��;����ѭ��
	printf("\n(i==5ʱbreak)��do while������һ��ʮ:\n");
	i = 1;
	do
	{
		if (i == 5)	//��i==5ʱbreak����ѭ��
			break;
		printf("%d ", i);//���Ϊ1 2 3 4 
		i++;
	} while (i <= 10);

	//continue��do while����е�Ч��;����ѭ��
	/*
	printf("\n(i==5ʱcontinue)��do while������һ��ʮ:\n");
	i = 1;
	do
	{
		if (i == 5)	//��i==5ʱcontinue��������ѭ��,��������Ĵ���,ֱ�ӽ���while�������ж�
			continue;
		printf("%d ", i);//���Ϊ1 2 3 4 ��ѭ��
		i++;
	} while (i <= 10);
	
	*/

	return 0;
}