#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int add(int x,int y) //int���ε�add����,����x,yΪ���ε��β�(��ʽ����),���øú�����ʵ��(ʵ�ʲ���,����Ϊnum1,num2)����ֵ��ֵ���β�x,y
{					//{}��Ϊʵ�ַ���
	int s = 0;		//��������s�뺯�����Ͷ�Ӧ,��󷵻�
	s = x + y;		//��������ӵĺ͸�ֵ��int����s
	return s;		//�����ķ���ֵΪs��ֵ,�뺯������(int)��Ӧ
}

int main(){
	int input = 0;//�����ֵ
	printf("if���򵥲���:ѡ�����1����0?\n");
	scanf("%d", &input);//&ȡ��ַ��,ȡ����ַ��input�������ֵ
	if (input == 1)//ifѡ�����,c������=Ϊ��ֵ��,==���ǵ����ж�
		printf("��������1\n");
	else
	{
		printf("��������0\n");
		printf("00000\n");
	}
	
	//while��ѭ�����(����while����for,do....while���)
	int	line = 0;
	while (line < 10) //whileѭ�����,һֱ��line=10����
	{
		printf("%d\tд����\n",line+1);
		line++;		//line+1,a=i++�Ƚ�i��ֵ��a��i=i+1(a=i,i=i+1)
					//a=++i��i=i+1�ٽ�i��ֵ��a(i=i+1,a=i)
	}

	if (line == 10)//if����ж��Ƿ�ﵽҪ��
	{
		printf("�Ѵ� %d �д���\n", line);
		printf("ѧ��\n");
	}
	else
	{
		printf("�Ѵ� %d �д���,δ��10��", line);
	}

	//����,���벻ֵͬ�����Ӧ���,һ�����������ظ�����
	int num1 = 0, num2 = 0;
	printf("�����������\n");
	printf("����num1Ϊ:");
	scanf("%d", &num1);//��������num1
	printf("����num2Ϊ:\n");
	scanf("%d", &num2);//����num2

	int sum = add(num1, num2);//����add���������������,����ʵ�ֵķ�����main������(����ͷ)

	printf("������Ϊ:%d\n", sum);//������

	//����,һ��ͬ���͵�Ԫ�صļ���,����һ��ռ�
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};//����10��������ֵ������
	char ch[5] = {'a','b','c','d','e'};//����5��char���͵��ַ���ֵ���ַ�����,
										//���û�������������,�ַ���������ֶ���'\0'(\0Ϊ������),
										// ��Ȼ������(�ַ������һֱ��\0������,��ϸ��/study/string�µ�string.c�ļ�)
	//�����±��0��ʼ,arr[0]=>1,������ֵ��Ĭ����Ϊ0
	printf("�������arr[10]������Ԫ��:\n");
	int i = 0;
	while (i < 10)
	{
		printf("%d ", arr[i]);
		i++;
	}
	return 0;
}