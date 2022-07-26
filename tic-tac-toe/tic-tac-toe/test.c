#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	//<>��ʾ��ȥϵͳĿ¼Ѱ��ͷ�ļ�,û����ȥ��ǰĿǰѰ��ͷ�ļ�; ""��ʾ��ȥ��ǰĿ¼Ѱ��ͷ�ļ�,û����ȥϵͳĿ¼
					//�⺯������ϵͳĿ¼,�Զ���ͷ�ļ�һ�㲻��ϵͳĿ¼,һ����ڵ�ǰ��Ŀ�ĵ�ǰĿ¼
#include "game.h"	//��Ϸͷ�ļ�,���Է���,��������������gameͷ�ļ���,ģ�黯�������,���ھ۵����
//���Ծ�������Ϸ���߼�

void menu()
{
	printf("**************************\n");
	printf("******  ��������Ϸ   ******\n");
	printf("******    1.play    ******\n");
	printf("******    0.exit    ******\n");
	printf("**************************\n");
}

void game()	
{
	//���ö�ά������±���Ϊ ���� ������,�ö�ά����洢���ӵ���Ϣ
	char board[ROW][COL];	//����һ����ά����,��Ϊ����,������ӵ���Ϣ
	//row��col�Ķ��嶼��gameͷ�ļ�,���з��ŵĶ���,��������������ͷ�ļ�,ģ�黯,���ڵ��������,���ھ۵����
	//����row��col������Ϊ�޸���ֵ,��������ĳ�ʼ����ֵ����д��,��Ҫ����row��col�Ĵ�С����̬��ʼ����������
	InitBoard(board, ROW, COL);	//��ʼ�����̺���Ϊ"�հ�",д�ں�����,����ģ�黯�͵��Ժ͵���
	//����������������gameͷ�ļ�,����ʵ�ַ�������game.c�ļ�,ģ�黯,���ھ۵����

	//��ӡ���̺���
	DisplayBoard(board, ROW, COL);	//��ӡ�ոճ�ʼ��������
	char ret = 0;	//��Ϸ״̬�ķ���ֵ
	//��ʼ����
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);	//��ʱ��ROW��COL�����ж�����µ����Ƿ񳬳����̷�Χ
		DisplayBoard(board, ROW, COL);	//��ӡ������������
		//�ж�����Ƿ�Ӯ����Ϸ
		ret = IsWin(board, ROW, COL);	//�����ж���Ϸ��״̬
		//����'C'��Ϸ����,ѭ������
		if ('C' != ret)	//��ΪC��Ϸ����,������Ϸѭ��
			break;

		//��������
		ComputerMove(board, ROW, COL);	//��ʱ��ROW��COL�������������ҵ����귶Χ������
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ����Ϸ
		ret = IsWin(board, ROW, COL);	//�����ж���Ϸ��״̬
		//����'C'��Ϸ����,ѭ������
		if ('C' != ret)	//��ΪC��Ϸ����,����ѭ��,���������if�ж�
			break;
	}//while(1)

	if ('*' == ret)	//����ֵ'*'Ϊ��һ�ʤ
	{
		printf("*****************\n");
		printf("**  ��һ�ʤ!!  **\n");
		printf("*****************\n");
	}
	else if ('#' == ret)	//����ֵΪ'#'���Ի�ʤ
	{
		printf("*****************\n");
		printf("**  ���Ի�ʤ!!  **\n");
		printf("*****************\n");
	}
	else		//����ֵΪ'Q' ƽ��
	{
		printf("***********\n");
		printf("**  ƽ��  **\n");	
		printf("***********\n");
	}

	DisplayBoard(board, ROW, COL);	//��ӡ���Ľ��
	printf("\n======================================\n");
} //void game()


int main()
{
	int input = 0;	//�����Ƿ�ʼ���ֵ
	srand((unsigned int) time(NULL));	//��ʱ���������������;  (unsigned int)ǿ������ת��Ϊunsigned int����; time(NULL)�ÿ�ָ�����ʱ�亯��; srand()���������������

	do
	{
		menu();	//���ɲ˵�
		printf("��ѡ��(1/0):>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//printf("play\n");
			game();	//��Ϸ���к���
			break;
		case 0:
			printf("exit\n");
			break;
		default:
			printf("ѡ�����,������ѡ��\n");
			break;
		}
	} while (input);

	return 0;
}

