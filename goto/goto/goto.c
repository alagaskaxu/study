#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>		//strcmp()����ͷ�ļ�
#include <stdlib.h>		//system()����

//goto ���
/*
	c�������ṩ�˿����������õ�goto���ͱ����ת�ı��
	������goto���û�б�Ҫ,����ĳЩ������goto��仹����ʹ��,
	�����÷�������ֹ������ĳЩ���Ƕ�׵Ľṹ�Ĵ������,����һ�������������ϵĶ��ѭ��.
	ֻ����һ��������Χ����ת,���ܿ纯��
*/


int main()
{
flag:
	printf("hello\n");
	printf("haha\n");

	//goto flag;	//��ת��flag
				//��ѭ��

	//һ���ӹػ�
	//cmd��shutdown -sΪ���ùرմ˼���� -rΪ���� -tΪ���ö������ػ�
	//shutdown -a Ϊ�����ػ�
	//c������system()���� ר������ִ��ϵͳ����

	char input[20] = { 0 };//����������Ϣ
	system("shutdown -s -t 60");
again:
	printf("���Խ���һ���Ӻ�ػ�,����:\"ȡ��\"��ȡ���ػ�\n");
	scanf("%s", input);
	if (strcmp(input,"ȡ��") == 0)	//strcmp���������Ƚ��ַ���,��ȷ���ֵΪ0
	{
		system("shutdown -a");
		printf("�ػ���ȡ��\n");
	}
	else
	{
		goto again;
	}

	/*һ�㲻��gotoҲ�ܴﵽЧ��,�����߼�������
	char input[20] = { 0 };
	system("shutdown -s -t 60");
	while(1)
	{
		printf("���Խ���һ���Ӻ�ػ�,����:\"ȡ��\"��ȡ���ػ�\n");
		scanf("%s", input);
		if (strcmp(input,"ȡ��") == 0)	//strcmp���������Ƚ��ַ���,��ȷ���ֵΪ0
		{
			system("shutdown -a");
			printf("�ػ���ȡ��\n");
			break;
		}
	}
	*/

	//����ʱ������ΪDebug,�����汾,���԰汾
	//��������ΪRelease,������ɺ�,�����release���а汾��exe�ļ�(�������ʽ�汾)


	/*
		goto�����������ó���
		for(...)
			for(...)
			{	
				for(..)
				{
					if(disaster)
						
						goto error;		//����һ���������ѭ��,Ƕ��,ֱ�ӵ�ָ�������

				}
			}
			...
	error:
		if(disaster)
			....//Ҫ����Ĵ������
	*/
	return 0;
}