#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void test() 
{
	static int a = 1;//static���ξֲ�����,�ı��˾ֲ���������������(ʵ���ϸı��˱����Ĵ洢����,�������Ϊ��̬,���ᶯ̬�����Ͷ�̬����)
	a++;			//�ڴ�һ���Ϊջ��,����,��̬��
					//�ֲ�����,������������ʱ������ջ��(��������push��ջ,���پ���pop��ջ)
	printf("%d", a);//����������̬�ڴ����; ȫ�ֱ�����static���εı������ھ�̬��(��������һֱ���������)
}


//�ؼ���
//��c�����ṩ,�����Լ�����ؼ���,�ؼ��ֲ�����������
/*
	�����ؼ���: auto break case char const continue default do double
	else enum extern float for goto if int long register return
	short signed sizeof static struct switch typedef union unsigned
	void volatile while
*/

// #define  ���峣���ͺ�  Ԥ����ָ��  û�зֺ�,��ֵ��
#define MAX 100		//���峣��MAX
				//��ָ����һϵ��Ԥ����Ĺ����滻һ�����ı�ģʽ,�����滻�ı�,��:mul��x*y���滻mul(x,y)����ı�
#define mul(x,y) x*y  //�����mul(��)  �ı��滻,����ı����ȼ�,����x,y����Ϊ���ʽ,�����ȼ�,ʹ�ý����Ԥ�ڲ�ͬ,
						//�����д��((x)*(y)),�ֶ��������ȼ�(���ȼ�:����˳��)
int main() 
{
	// auto �Զ���, �Զ������Զ����ٵ�, ÿ���ֲ���������auto���ε�,���﷨�������÷�(�ݲ�����)
	auto int o = 10;//�ֲ���������auto����,һ��ʡ��auto(������Զ����auto����)
	// break(����) continue(����) switch case do while for����ѭ�������
	// default Ĭ��,����switch case���
	// if else ����ѡ�����
	// char �ַ�����, const ������, float �����ȸ�����, double ˫��������, enum ö������
	// int ����, long ������, short ������
	// void ������,������
	// signed �з�����, unsigned �޷�����
	// static ��̬,���κ����ͱ���Ϊ��̬
	// struct ������, union ������(������)
	// extern �����ⲿ���ű���
	// goto ����goto���
	// register �Ĵ����ؼ���,����(ϣ��)�������ε�ֵ����Ĵ���,�����Ƿ����Ĵ����ɱ���������
	register int regnum = 100;//���齫regnum�е�ֵ����Ĵ���,һ���ò���
	// return ����,�������غ���ֵ
	// sizeof �����͵Ĵ�С,���ֽ�Ϊ��λ, typedef �����ض���
	// volatile �������η�,���߱������ñ������ױ��,ϣ��������ȥע��ñ�����״̬,ʱ��ע��ñ������ױ��,ÿ�ζ�ȡ�ñ�����ֵ�����´��ڴ��ж�ȡ

	// **#define��#include���ǹؼ���,������Ԥ����ָ��

	typedef unsigned int u_int;//typedef �����ض���,��unsigned int����Ϊu_int(����ȡ������,������д)
	//unsigned int u = 100;//����u_int u = 100;
	u_int u = 100;
	
	int i = 0;
	while (i < 10)//û��static�����10��2,��static int a=1;���2-11
	{
		test();//�����ﲻ��static��ÿ�ν���test���������β�a��Ϊ1,a++=2,���2,��Ϊa�Ǿֲ�����,��������ʹa�������ڽ���,a�Զ�����
				//����ʹ��static int a=1;��aΪ��̬�ֲ�����,��������Ҳ��������,a��ֵ�ᱣ��
				//static���ξֲ�������ı�ֲ���������������(�������Ǹı��˱�������,ʹ�������ھ�̬��),ʹ������ȫ�ֱ���,ֱ���������������
		i++;	//static���εľ�̬�������÷��ں�����,���ڳ����ģ�黯
	}

	extern int g_val; //extern�����ⲿ����g_val;һ���������ڿ�ͷ,main�����ⷽ��
	extern int s_g_val; //extern�����ⲿ����s_g_val(��̬��)
	printf("\nglobal value test= %d\n", g_val);//���������ʹ���ⲿ��g_valȫ�ֱ���
	//printf("static global test=%d\n", s_g_val);//s_g_val�ᱣ��,�޷��������ⲿ����
				//static���ε�ȫ�ֱ���ֻ�����Լ����ڵ�Դ�ļ�(static add.c)�ڲ�ʹ��
	//ȫ�ֱ����ܱ��ⲿʹ������Ϊ���ⲿ��������,����static���κ��Ϊ�ڲ���������,���������ⲿ,���������ڲ���

	extern int add(int, int);//�����ⲿ����add
	extern int sub(int m, int n);//�����ⲿ����sub ����()��ֻҪ������Ҫ���ú�����ʽ��Ӧ����,�βο��Բ�һ�����߲�д
	int a = 0, b = 0, sum = 0, dif = 0;
	a = 30;
	b = 20;
	sum = add(a, b);//Ҫʹ���Լ�д���ⲿ��add����,����������
	dif = sub(a, b);//Ҫʹ���Լ�д���ⲿ��sub����,����������
	printf("a+b= %d\n", sum);//���ⲿ������static����ʱ,����;�̬ȫ�ֱ���һ��,����Ϊ�޷�����
	printf("a-b= %d\n", dif);//���ⲿ������static����ʱ,����;�̬ȫ�ֱ���һ��,����Ϊ�޷�����

	// #define  ���峣���ͺ�  Ԥ����ָ��
	printf("MAX = %d\n", MAX );
	int acc = 0, acc2 = 0;//acc������
	acc = mul(a, b);//�͵���acc = a*b; ���ı��滻
	acc2 =mul(a+2, b);//acc2 =a+2*b; 30 + 2*20=30+40=70  ��ȫ�滻,��������ȼ�
	printf("mul�� a*b=%d , %d\n", acc, acc2);
	return 0;
}