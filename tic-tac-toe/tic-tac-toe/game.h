#pragma once
//��������Ϸ��ͷ�ļ�

//����ͷ�ļ��İ���
#include <stdio.h>	//ֻ������game.hͷ�ļ��Ͱ�����һЩ��ͬ��ͷ�ļ�,�����ظ�����
#include <stdlib.h>	//������������� srand()��rand()
#include <time.h>	//time()����


//���ŵĶ���
#define ROW 3	//�궨�� ��ʶ��ROW��ֵΪ����3	��Ϊ3
#define COL 3	//��Ϊ3	�ñ�ʶ��������Ϸ�ĵײ���ֵ�ĸı�,��ı����̴�Сֻ��ı��������ֵ����,�����Դ����ȫ���޸�



//����������

//��ʼ�����̺���,����ʵ����game.c�ļ�
void InitBoard(char board[ROW][COL], int row, int col);	//��Ȼ����ʱ,����ʡ���βε��ǲ�����ʡ��

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);

//�������
void PlayerMove(char board[ROW][COL], int row, int col);

//��������
void ComputerMove(char board[ROW][COL], int row, int col);

//�ж���Ϸ״̬,�Ƿ��ʤ:�ж�1.���Ӯ��	2.����Ӯ��	3.ƽ��	4.��Ϸ����
//���Ӯ�˷���'*';	����Ӯ�˷���'#';	ƽ�ַ���'Q';	��Ϸ��������'C'
char IsWin(char board[ROW][COL], int row, int col);

