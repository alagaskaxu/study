#define _CRT_SECURE_NO_WARNINGS
#include "game.h"	//������Ҫ��ͷ�ļ�����game.h��

//ɨ����Ϸ�����̲���

void menu()	//�˵�����
{
	printf("************ ***********\n");
	printf("*****   ɨ����Ϸ   *****\n");
	printf("*****    1.play   *****\n");
	printf("*****    0.exit   *****\n");
	printf("************ ***********\n");
}//menu()

void game()
{
	//printf("ɨ��\n");
	/*
		1.������,û����Ϊ'0',���׵ĵط�Ϊ '1'
		2.�Ų���
	*/

	//ʹ��������ά����,һ�������,һ������Ų����Ϣ
	//������ά�����������
	char mine[ROWS][COLS];	//��Ų��úõ��׵���Ϣ(���ɼ�)	��ʼ��Ϊ'0'
	char show[ROWS][COLS];	//���Ҫչʾ���Ų���Ϣ(չʾ)	��ʼ��Ϊ'*'

	//��ʼ������
	InitBoard(mine, ROWS, COLS , '0');
	InitBoard(show, ROWS, COLS , '*');

	//��ӡ����
	DisplayBoard(show, ROW, COL);	//ֻ��ӡ��СΪ9*9������,����һȦ(����)����ӡ(

	//���������
	SetMine(mine, ROW, COL);	//�����������mine����9*9

	//������,��ʾ����,'1'Ϊ��,��ʽ���������
	DisplayBoard(mine, ROW, COL);	//ֻ��ӡ9*9���м������,mine��չʾ,�������

	//�Ų���
	FindMine(mine, show, ROW, COL);


}//game()

int main()
{
	int input = 0;	//����ֵ
	//�����������,һ�ξ͹�,����������������
	srand((unsigned int)time(NULL));	//��time���͵ķ���ֵǿ������ת��Ϊunsigned int����

	do
	{
		menu();
		printf("��ѡ��(1/0):> ");
		//fflush(stdin);	//���ȫ��������	fflush()ˢ�»���������,stdin��׼������,�����,�ļ���; ˢ���������Ļ�����
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			system("cls");	//������Ļ,��Ϸ��ʼ
			game();	//ɨ����Ϸ�ľ�������
			break;
		case 0:
			system("cls");//������Ļ,��Ϸ����
			printf("�˳���Ϸ\n");
			break;
		default:
			system("cls");//������Ļ,����ѡ��
			printf("=======================\n");
			printf("!!�������!!\n������1��0\n");
			break;
		}

	} while (input);

	return 0;

}//main()

