/*
	1006. 换个格式输出整数
	
	Description：	让我们用字母B表示“百”，字母S表示“十”，用“12...n”来表示个位数字（n<10），换个格式来输出任一个不超过3位的正整数。例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4.
	
	输入格式： 每个测试输入包含1个测试用例，给出正整数n（n<=1000）。
	输出格式： 每个测试用例的输出占一行，用规定的格式输出n。
	
	样例1：
		输入： 234
		输出： BBSSS1234
		
	样例2：
		输入： 23
		输出： SS123
	
*/

#include <stdio.h>

void anotherPrint(int num);

int main(void) {
	int num;
	scanf("%d",&num);
	anotherPrint(num);
	return 0;
}

void anotherPrint(int num) {
	int num_b, num_s, num_g;
	num_b = num/100;
	num_s = num /10-num_b*10;
	num_g = num%10;
	for (int i = 0;i < num_b; ++i)	printf("B");
	for (int i = 0;i < num_s; ++i)	printf("S");
	for (int i = 0;i < num_g; ++i)	printf("%d",i+1);
	printf("\n");
}