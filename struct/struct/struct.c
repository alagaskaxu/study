#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�ṹ�����
//�ṹ����һЩֵ�ļ���,��Щֵ��Ϊ��Ա����.�ṹ��ÿ����Ա���������� ��ͬ���� �ı���

//�ɼ��ṹ��
struct score
{
	char course_name[20];	//�γ�����
	char course_id[20];	//�γ�id
	int score;	//�γ̵ĳɼ�
};

//ѧ���Ľṹ��
struct Stu
{
	//��Ա����(�ṹ���Ա��������Ƕ�׽ṹ��)
	char name[20];	//����
	int age;	//����
	char id[20];	//ѧ��
	struct score sc;	//�����ɼ��ṹ�����͵� sc����,�ṹ�����Ƕ�׽ṹ��

}s1,s2;	//s1,s2Ҳ�ǽṹ������� s һ��,����s1��s2��ȫ�ֱ���

int main()
{
	//�ṹ�崴���������ʼ��
	struct Stu s = { "С��",20,"195080822",{"c����","c123",95} };	//����һ��Stu�ṹ�����͵�s����,s�Ǿֲ�����
	//�ṹ��ĳ�ʼ��{name,age,id	,sc{course_name,course_id,score} }	//Ƕ�׳�ʼ��

	//�ṹ���Ա�ķ���,ʹ��.��-> ���ʳ�Ա����
	printf("name = %s\n", s.name);	//����ѧ������
	//printf("age = %d\n", s.age);	//����ѧ������
	//printf("s.id = %s\n", s.id);	//����ѧ��id
	printf("course_name = %s\n", s.sc.course_name);	//����ѧ���Ŀγ̵�����
	printf("sc.score = %d\n", s.sc.score);	//����ѧ���Ŀγ̳ɼ�
	//->���ڽṹ��ָ�����ʱ
	struct Stu* ps = &s;
	printf("\nname = %s\n", ps->name);	//ָ�����ѧ������
	printf("age = %d\n", (*ps).age);	//���ýṹ��ָ����ʳ�Ա����,���Խ�����Ҳ����ֱ��ʹ��->
	printf("ps->id = %s\n", ps->id);	//ָ�����ѧ��id
	printf("course_name = %s\n", (*ps).sc.course_name);	//ָ������÷���ѧ���γ���
	printf("course_id = %s\n", ps->sc.course_id);	//ָ��->ֱ�ӷ���ѧ�������sc�ṹ���еĿγ�id




	return 0;
}



