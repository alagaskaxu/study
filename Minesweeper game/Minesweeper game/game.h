#pragma once
//��Ϸͷ�ļ�

//ͷ�ļ��İ���
#include <stdio.h>	//printf() ....
#include <stdlib.h>	//rand() srand()
#include <time.h>	//time()
#include <Windows.h>//sleep()

//���Ŷ���
#define ROW 9 	//ʵ������Ϊ9*9,����ߴ���һȦ���ر߽�,��ֹ����Խ��
#define COL 9 
#define ROWS ROW + 2	//�����������СΪ11*11
#define COLS COL + 2	//����ߴ���һȦ���ر߽�,��ֹ����Խ��
#define MINES 1		//�׵�����

//��������

//�����ʼ��
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col);	//չʾ������Ϊ9*9 ����ROW,COL,�β�Сд��������

//��mine���������������
void SetMine(char mine[ROWS][COLS], int row, int col);

//�Ų���;��mine��������������show����,����һ��,����row��col
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

//�����Χ����
//int get_mine_count(char mine[ROWS][COLS], int x, int y);	//�˺���������ΪFindMine�ṩ����,���Բ�д��ͷ�ļ���,��FindMine()ǰ��д�ú�������

//�ݹ��Ų�һƬ����
void SearchBomm(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y, int* pwin); //�˺���������ΪFindMine�ṩ����,���Բ�д��ͷ�ļ���,��FindMine()ǰ��д�ú�������


//�ֶ������
void MarkMine(char show[ROWS][COLS], int row, int col);

