#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>		//strcpy()������ͷ�ļ�

//��������
//����:Ҳ���ӳ���,��һ�����ͳ����е�ĳ���ִ���,��һ�����������������,�������ĳ���ض�����,�߱�һ���Ķ�����
//һ�������������ͷ���ֵ,�ṩ�Թ��̵ķ�װ��ϸ�ڵ�����,��Щ����ͨ��������Ϊ�����
//c�����к����ķ���:1.�⺯��(c���Ա������Դ���һЩ�������ܵĿ⺯��) 2.�Զ��庯��
//�⺯���ĵ�  https://cplusplus.com/reference/	https://zh.cppreference.com/w/
//���ÿ⺯����:IO����(�����������),�ַ�����������,�ַ���������,�ڴ��������,ʱ��/���ں���,���ֺ���,�����⺯��
int main()
{
	//�⺯��
	//ͨ���ĵ�ѧϰ strcpy����
	//char* strcpy ( char* destination, const char* source );��string.hͷ�ļ���.  ����:copy string(�����ַ���,����'\0')
	//*��ʾָ�����	���ÿ⺯��������Ӧͷ�ļ�string.h
	char arr1[20] = { 0 };
	char arr2[] = "hello";
	strcpy(arr1, arr2);	//������������ǵ�ַ ��ָ������
	printf("%s\n", arr1);	//��ӡarr1���ַ���  %sָ���ַ�����ʽ����ӡ

	//ѧϰmenset����; �ڴ����ú���memoryset
	//void * memset ( void * ptr, int value, size_t num );
	//����: Sets the first num bytes of the block of memory pointed by ptr to the specified value (interpreted as an unsigned char).
	// ��ptrָ����ָ����ڴ��ǰnum���ֽڵ���������Ϊvalue��ֵ
	//size_t: tpyedef unsigned int  size_t;

	char arr[] = "welcome to c";
	memset(arr, 'x', 5);	//��arr��ַָ����ڴ����ǰ 5 ���ֽڵ������滻Ϊ'x'(valueΪx��ASCII��,'x'�ַ��ڼ��������int���͵�ASCII����,char���͵�ASCII��(120)�Զ�ת��Ϊ�ַ�(x) )
	printf("%s\n", arr);


	//�Զ��庯��
	//to do

	return 0;
}