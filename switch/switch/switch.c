#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//switch��� �����ڶ��֧���
/*
	switch(���α��ʽ)
	{
		�����;
	}
	�����һ��Ϊcase�������
	case ���γ������ʽ: 
		���;
		
	case����һ�����break����switch,�ﵽ��ֹ��Ч��
	case�������,break��������
	break; ֻ�����������ڵ�switch
*/

int main()
{
	int day = 0;
	//float day = 0; ���� switch��case�����������,case�������γ���
	//�����������ַ�,��Ϊ�ַ����������γ�����ASCII��ֵ
	printf("�������ڼ�:\n");
	scanf("%d", &day);

	switch (day)
	{
	case 1:		
		printf("����һ");
		break;	//case��������break����switch���,�ﵽ��ֹ��Ч��
	case 2:
		printf("���ڶ�");
	case 3:		//���û��break��ת��ȥ,���������ת����Ӧcase�����ִ��������ͻ����˳��ִ����������,ֱ��break����
		printf("������");
	case 4:
		printf("������");
	case 5:
		printf("������");
		break;
	case 6:
		printf("������");
		break;
	case 7:
		printf("������");
		break;
	default:	//Ĭ��,������������û����ִ��Ĭ��default
		printf("�������!!!");
		break;
	}

	printf("\n\n�������ڼ�,���1-5������,6-7��ĩ:\n");
	switch (day)  //break���԰��Լ��������
	{
	default:	//������ƥ���case������ִ��Ĭ�����
		printf("�������!!!");//defaultû���ض�˳��,һ������
		break;
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("������\n");
		break;
	case 6:
	case 7:
		printf("����\n");
		break;//���Բ���,���Ǽ���,�������,���ҷ�����չcase8
	}

	//��ϰ
	int n = 0, m = 0;
	n = 1;
	m = 2;
	switch (n) //n=1
	{
	case 1:
		m++;  //m=3,û��break����˳��ִ��
	case 2:
		n++;  //n=2
	case 3:
		switch (n)  //switch����Ƕ��
		{		//n=2
		case 1: //���� case 1
			n++;
		case 2:	 //n=2
			m++; //m=3+1=4
			n++; //n=2+1=3
			break; //�������switch 
		}
	case 4:  //breakֻ����һ��switch
		m++; //m=4+1=5
	default:
		break;//����break����switch
	}
	printf("m = %d, n = %d \n", m, n);//m= 5, n= 3

	return 0;
}