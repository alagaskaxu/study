#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

//��Ϸ������ʵ��

//��ʼ������
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}//InitBoard()

//��ӡ����
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	printf("---------ɨ����Ϸ---------\n");
	//��ӡ�к�
	for (int j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");	//����
	//��ӡ����
	for (int i = 1; i <= row; i++)	//��ӡROW,COL�Ĵ�С(9*9),���±�1��ʼ��ӡ��9Ϊֹ
	{
		printf("%d ", i);	//��ӡ�к�
		for (int j = 1; j <= col; j++)
		{
				printf("%c ", board[i][j]);	//��ӡԪ���ַ�
		}
		printf("\n");
	}
}//DisplayBoard

/*
	static ����������
	���ξֲ�����
	����ȫ�ֱ���
	���κ���
*/

//��ӡ����,��Ϊ��̬����,ʹ�ô˺���ֻ����game.c�ļ���ʹ��
static void DisplayMine(char Mine[ROWS][COLS], int row, int col)
{
	printf("---------  #����#  ---------\n");
	//��ӡ�к�
	for (int j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");	//����
	//��ӡ����
	for (int i = 1; i <= row; i++)	//��ӡROW,COL�Ĵ�С(9*9),���±�1��ʼ��ӡ��9Ϊֹ
	{
		printf("%d ", i);	//��ӡ�к�
		for (int j = 1; j <= col; j++)
		{
			if ('1' == Mine[i][j])
				printf("# ", Mine[i][j]);	//���Ϊ�״�ӡ'#'��
			else
				printf("%c ", Mine[i][j]);	//�������ֱ�Ӵ�ӡԪ���ַ�
		}
		printf("\n");
	}
}//DisplayMine

//������
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	//����10����
	int count = MINES;
	while (count)	//countΪ0,�������
	{
		//��������±�,rand()�����ǵ���srand()������������������,ͷ�ļ�Ϊ<stdlib.h>
		int x = rand()%row + 1;		//�к�i,ȡģ+1��֤�������Χ��1-9֮��
		int y = rand()%col + 1;		//�к�j,%ģһ����n,�õ�������һ��С���Ǹ���n,������Χ��[0,n),+1��ΧΪ[1,n+1) �� [1,n]
		if ( '0' == mine[x][y])		//���mine�����ӦԪ����'0'Ϊ��,û����������
		{
			mine[x][y] = '1';		//'1'�ַ�1 ��ʾΪ��; '0'�ַ�0 ��ʾΪ��(û��)
			count--;	//������һ����,����count-1
		}

	}//while(count)

}//SetMine()

//���������Χ������,���Խ�д��FindMine����ǰ,��д��ͷ�ļ�,��Ϊֻ��FindMine����ʹ��
static int get_mine_count(char mine[ROWS][COLS], int x, int y)	//static���κ�����ʾ��̬����,ʹ�˺���ֻ����game.c�ļ���ʹ��,�����ط��޷�ʹ��
{
	/*
		�˸�����(�����Լ��Ÿ�)	(x-1,y-1) (x-1,y) (x-1,y+1) (x,y-1) |(x,y)�Լ�| (x,y+1) ......
	*/
	int count = 0;
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			count  += (mine[x + i][y + j] - '0');//mine������char����.'0'ASCII��Ϊint 48
		}
	}
	return count;	//����count��ֵ
}


//�Ų���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//�����Ų������
	int x = 0;	//�к�
	int y = 0;	//�к�
	int win = 0;
	while (win < row*col - MINES )	//��win�����������и��Ӷ�����û����(��ȥ����)����Ϸ��ʤ
	{
		printf("������Ҫ�Ų������,��������Ͻ�1 1��ʼ:> ");
		scanf("%d %d", &x, &y);	//x,y ��Χ[1,9]
		//�ж�����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//������괦�ǲ�����(����,game over; ������,��ʾ��Χ������,���Ų鵽����Ϣ����show����)
			if ('1' == mine[x][y])	//�Ų鴦����,��gameover
			{
				printf("===========��Ϸʧ��===========\n");
				printf("   !!!!!!!!!!Boom!!!!!!!!!!\n");
				//չʾһ������
				DisplayMine(mine, row, col);
				printf("   !!!(%d,%d)��Ϊ#��#\n", x, y);
				printf("===========��Ϸʧ��===========\n");
				break;
			}//if(����)
			else	//���괦������,ͳ��(x,y)��Χ������
			{
				int count = get_mine_count(mine, x, y);
				//�����Χ������show����,����չʾ
				//show�������ַ�,countΪint����,��Ҫ����ASCII���޸�һ��,�ٴ���show����
				//'0' -> 48 ; '1' -> 49 ; '2' - > 50 ; ....
				show[x][y] = '0' + count;

				//��ʾ�Ų������Ϣ
				DisplayBoard(show, row, col);	//��ӡ����

				win++;	//ֻҪ�����׾ͱ��һ��,������+1

			}//else(����)

		}//if(����ĺϷ���)
		else	//���겻�Ϸ�
		{
			printf("!!!�������!!!\n��������������\n���귶ΧΪ[1,9]\n");
		}//else(���겻�Ϸ�)

	}//while(win < row*col - MINES)
	
	if (row * col - MINES == win)
	{
		//չʾ����
		DisplayMine(mine, row, col);
		printf(" !!!!!  ��ϲ��  !!!!!\n");
		printf("!!!!!  ��Ϸ��ʤ  !!!!!\n");
		printf("============================\n");
	}

}//FindMine()


