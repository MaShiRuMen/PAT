/*
	1004. 成绩排名
	
	Description:
	
	读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。
	输入格式：每个测试输入包含1个测试用例，格式为：
		第一行： 正整数n
		第二行： 第1个学生的姓名 学号 成绩
		第三行： 第2个学生的姓名 学号 成绩
		...	...	...
		第n+1行： 第n个学生的姓名 学号 成绩
	其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。
	
	输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有		1空格。
	
	输入样例：
		3
		Joe 	Math990112	89
		Mike	CS991301	100
		Mary	EE990830	95
	输出样例：
		Mike CS991301
		Joe Math990112

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {	//定义学生信息结构体，用来保存学生信息；
	char name[11];	//保存学生姓名；
	char stu_num[11];	//保存学生学号；
	int score;	//保存学生分数；
} Stu; 
typedef Stu *StuPointer;

int main() {
	StuPointer S, max, min;	//定义三个指向Student的指针；
	int n;
	scanf("%d", &n);
	S = (StuPointer)malloc(n*sizeof(Stu));	//初始化S指针，并分配空间；
	max = min = S;	//令两个指针初始化都指向S[0]；
	while(n > 0) {
		scanf("%s %s %d", S->name, S->stu_num, &S->score);
		if (S->score > max->score ) max = S;	//找到最大的score的学生，用max指向它；
		if (S->score < min->score )	min = S;	//找到最小的score的学生，用min指向它；
		S++;
		n--;
	}
	printf("%s %s\n", max->name, max->stu_num);
	printf("%s %s\n", min->name, min->stu_num);
	return 0;
}