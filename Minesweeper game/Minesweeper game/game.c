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

//�ݹ��Ų���Χ��������,pwinΪָ����������־λwin����ֵ
void SearchBomm(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y, int* pwin)
{
	//�ݹ���ܻ�ʹ�ô��������+1,-1���³�������,�ж�һ������Ϸ���
	if (x >= 1 && x <= row && y >= 1 && y <= col)
	{
		//�õ���ǰ������ΧһȦ������
		int num = get_mine_count(mine, x, y);

		//�����ǰ������Χû����,��ʼ�ݹ�
		if (0 == num )
		{
			//��һ���Ų������
			(*pwin)++;//win������+1
			//��Χû������û�����,��show[x][y]Ԫ�ر�Ϊ' '����'0'
			if ('!' != show[x][y])
			{
				show[x][y] = ' ';
			}
			
			//��(x,y)��Χ�İ˸����꿪ʼ�����Ų�
			for (int i = -1; i < 2; i++)
			{
				for (int j = -1; j < 2; j++)
				{
					//Ϊ�˱����ظ��Ų�ͬһ����,������ݹ�,��������,ֻ�Ų�Ԫ��ΪĬ��'*'������,Ҳ�ܱ��ⱻ��ǵ�Ԫ�ر��ݹ�,ʹ��Ϸ���
					if ('*' == show[x + i][y + j])
					{
						SearchBomm(mine, show, row, col, x + i, y + j, pwin);
					}
				}//for(j)
			}//for(i)

		}//if(0 == num)
		else
		{
			//��ǰ������Χ������,��������¼��show����,
			show[x][y] = num + '0';	//show����Ϊchar����,numΪint����
			//win������+1
			(*pwin)++;
		}

	}//if(����Ϸ�)

	//����Ϸ�,��ʹ�ú���
}

//�ֶ������
void MarkMine(char show[ROWS][COLS], int row, int col)
{
	//(x,y)����
	int x = 0;
	int y = 0;
	system("cls");	//����
	DisplayBoard(show, row, col);	//��ӡҪ��ǵ�����
	printf("==============================\n");
	printf("������Ҫ��ǻ�ȥ��������(��1 1��ʼ):> ");
	scanf("%d %d", &x, &y);
	//�����Ƿ�Ϸ�
	if (x >= 1 && x <= row && y >= 1 && y <= col)
	{
		//�ж����괦Ԫ���ܷ��ǻ���ȥ��
		if ('*' == show[x][y])
		{
			show[x][y] = '!';	//���
			system("cls");	//����
			DisplayBoard(show, row, col);	//��ӡ��Ǻ������
			printf("�ɹ����(%d,%d)��", x, y);
		}
		else if ('!' == show[x][y])
		{
			show[x][y] = '*';
			system("cls");	//����
			DisplayBoard(show, row, col);	//��ӡ��Ǻ������
			printf("�ɹ�ȥ��(%d,%d)�ı��", x, y);
		}
	}//if(x&&x&&y&&y)
	else
	{	//�Ƿ�����
		printf("\n====================\n");
		printf("!!!�������!!!\n��������������\n���귶ΧΪ[1,9]\n");
		Sleep(500);	//�ȴ�0.5s
	}//else(�������Ƿ�)
			
}//MarkMine()

//�Ų���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//ѡ�����
	int choice = 0;
	int start = 1;	//startΪ1ʽ������Ϸ,startΪ0 ʱ������Ϸ
	//�����Ų������
	int x = 0;	//�к�
	int y = 0;	//�к�
	//��ʤ�����ı�Ǳ���
	int win = 0;
	int* pwin = &win;	//ָ��pwinʹ�õ���SearchBoom�����ܸ�win��ֵ

	//ֻҪ�����׾ͱ��һ��,win+1
	//��win�����������и��Ӷ�����û����(��ȥ����)����Ϸ��ʤ,ѭ������
	while (win < row*col - MINES && 1 == start)
	{
		printf("================\n");
		printf("1.�Ų���\n");
		printf("2.��ǻ�ȡ����\n");
		printf("0.������Ϸ\n");
		printf("��ѡ����� 1 or 2 :> ");
		//fflush(stdin);	//ʧЧ,��������,�����Ǳ�������д������,fflushֻ֧��file*����,����ֻ��ˢ���ļ����Ļ�����,�������벻��??
		//�����Ͽ������ȫ��������	fflush()ˢ�»���������,stdin��׼������,�����,�ļ���; ˢ���������Ļ�����

		//����getchar()��ѭ��,һ��һ�����
		while ((choice = getchar()) != '\n')	//getchar�õ�һ���ַ�,whileһֱѭ���õ��ַ�һֱ��\n
			;//�����,��������,��ֹ�������Զ�����,ȥ��'\n'�ַ�
		
		scanf("%d", &choice);
		switch (choice)
		{
			//�Ų���
		case 1:
			system("cls");	//����
			DisplayBoard(show, row, col);	//��ӡҪ�Ų������
			printf("======================================\n");
			printf("������Ҫ�Ų������,��������Ͻ�1 1��ʼ:> ");
			while ((choice = getchar()) != '\n')	//getchar�õ�һ���ַ�,whileһֱѭ���õ��ַ�һֱ��\n
				;//�����,��������,��ֹ���������޹����ݴ�������,ȥ��'\n'�ַ�
			scanf("%d %d", &x, &y);	//x,y ��Χ[1,9]
			//�ж�����Ϸ���
			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				//������괦�ǲ�����(����,game over; ������,��ʾ��Χ������,���Ų鵽����Ϣ����show����)
				//�Ų鴦��������show[x][y]Ԫ��δ���Ų��ʱ,�����Ų麯��,ͳ����Χ���
				if ('1' != mine[x][y] && '*' == show[x][y])
				{
					//�ݹ��Ż�
					//�õݹ�ʵ���Ų�һ������,�õ�һƬ��Ϣ
					SearchBomm(mine, show, row, col, x, y, pwin);

					//������Ļ
					system("cls");
					//��ʾ���Ų������Ϣ
					DisplayBoard(show, row, col);	//��ӡ����

				}	//if((x,y)����������δ���Ų��)
				else if ('1' == mine[x][y])	//�Ų鴦����,��gameover
				{
					system("cls");	//�����Ļ
					printf("===========��Ϸʧ��===========\n");
					printf("   !!!!!!!!!!Boom!!!!!!!!!!\n");
					//չʾһ������
					DisplayMine(mine, row, col);
					printf("  !!(%d,%d)��Ϊ#��#\n", x, y);
					printf("===========��Ϸʧ��===========\n");
					start = 0;;	//�����Ų�����ѭ��
				}	//es-if(x,y)��Ϊ��
				else	//show[x][y]��ΪĬ�ϵ�'*'���ʾ�˴��Ѿ��Ų��
				{
					//��ʾ���Ų������Ϣ,������"cls"����ָ��,��������չʾ
					//DisplayBoard(show, row, col);	//��ӡ����
					printf("====================\n");
					printf(" (%d,%d)�����Ų��\n", x, y);
					printf("====================\n");
				}

			}//if(����ĺϷ���)
			else	//���겻�Ϸ�
			{
				printf("\n====================\n");
				printf("!!!�������!!!\n��������������\n���귶ΧΪ[1,9]\n");
				Sleep(500);	//�ȴ�0.5s
			}//else(���겻�Ϸ�)
			break;

			//�����
		case 2:
			//�Ƿ���Ҫ�����
			while ((choice = getchar()) != '\n')	//getchar�õ�һ���ַ�,whileһֱѭ���õ��ַ�һֱ��\n
				;//�����,��������,��ֹ���������޹����ݴ�������,ȥ��'\n'�ַ�
			MarkMine(show, row, col);
			break;

			//start == 0ʱ������Ϸ
		case 0:
			start = 0;
			system("cls");
			break;
		default:
			printf("\n=================\n");
			printf("!!�������!!\n������0,1��2\n");
			Sleep(500);	//�ȴ�0.5s
			break;
		}//switch(choice)

	}//while(win < row*col - MINES && 1 == start)
	
	if (row * col - MINES == win)
	{
		//չʾ����
		system("cls");	//����
		DisplayMine(mine, row, col);
		printf(" !!!!!  ��ϲ��  !!!!!\n");
		printf("!!!!!  ��Ϸ��ʤ  !!!!!\n");
		printf("============================\n");
		Sleep(500);	//�ȴ�0.5s
	}
}//FindMine()


