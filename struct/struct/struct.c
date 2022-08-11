#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//结构体初阶
//结构体是一些值的集合,这些值称为成员变量.结构的每个成员变量可以是 不同类型 的变量

//成绩结构体
struct score
{
	char course_name[20];	//课程名字
	char course_id[20];	//课程id
	int score;	//课程的成绩
};

//学生的结构体
struct Stu
{
	//成员变量(结构体成员变量可以嵌套结构体)
	char name[20];	//名字
	int age;	//年龄
	char id[20];	//学号
	struct score sc;	//创建成绩结构体类型的 sc对象,结构体可以嵌套结构体

}s1,s2;	//s1,s2也是结构体变量和 s 一样,但是s1和s2是全局变量

int main()
{
	//结构体创建对象与初始化
	struct Stu s = { "小明",20,"195080822",{"c语言","c123",95} };	//创建一个Stu结构体类型的s对象,s是局部变量
	//结构体的初始化{name,age,id	,sc{course_name,course_id,score} }	//嵌套初始化

	//结构体成员的访问,使用.和-> 访问成员变量
	printf("name = %s\n", s.name);	//访问学生名字
	//printf("age = %d\n", s.age);	//访问学生年龄
	//printf("s.id = %s\n", s.id);	//访问学生id
	printf("course_name = %s\n", s.sc.course_name);	//访问学生的课程的名字
	printf("sc.score = %d\n", s.sc.score);	//访问学生的课程成绩
	//->用于结构体指针访问时
	struct Stu* ps = &s;
	printf("\nname = %s\n", ps->name);	//指针访问学生名字
	printf("age = %d\n", (*ps).age);	//利用结构体指针访问成员变量,可以解引用也可以直接使用->
	printf("ps->id = %s\n", ps->id);	//指针访问学生id
	printf("course_name = %s\n", (*ps).sc.course_name);	//指针解引用访问学生课程名
	printf("course_id = %s\n", ps->sc.course_id);	//指针->直接访问学生对象的sc结构体中的课程id




	return 0;
}



