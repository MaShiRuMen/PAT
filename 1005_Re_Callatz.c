/*
	1005. 继续(3n+1)猜想
	卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。	当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。例如对n=3进行验证的时候，我们需要计算3、5、8、4、2、1，则当我们对n=5、8、4、2进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这4个数已经在验证3的时候遇到过了，我们称5、8、4、2是被3“覆盖”的数。我们称一个数列中的某个数n为“关键数”，如果n不能被数列中的其他数字所覆盖。	现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。	输入格式：每个测试输入包含1个测试用例，第1行给出一个正整数K(k <= 100)，第2行给出K个互不相同的待验证的正整数n(1<=n<=100)的值，数字间用空格隔开。	输出格式：每个测试用例的输出占一行，按从大到小的顺序输出关键数字。数字间用1个空格隔开，但一行中最后一个数字后没有空格。

	输入样例：
	6
	3 5 6 7 8 11

	输出样例：
	7 6

*/

#include <stdio.h>

#define MAXLEN 101	// 设置数组的最大长度；

int num[MAXLEN] = {0};	// 用来保存输入的数字；
int result[MAXLEN] = {0};	// 用来保存关键数字；
int mark[MAXLEN] = {0};	// 用来标记关键数字的位置；

void judgeCallatz(int n,int len);	// 计算数字的callatz数组，并标记出非关键字；

int main(void) {
	int i, j, steps;
	int len, re_len, flag;	// len表示num数组的长度，由用户输入。re_len表示result数组的长度；
							// flag 是冒泡排序的标志；
	scanf("%d",&len);
	for( i = 0; i < len; ++i) scanf("%d",&num[i]);
	
	for( i = 0; i < len; ++i) {
		if (mark[i] == 0) {
			judgeCallatz(num[i],len);	// 对于num数组中非关键字标记出来；
		}
	}
	re_len = 0;
	for( i = 0; i < len; ++i) {
		if (mark[i] == 0) result[re_len++] = num[i];	// 将标记为关键字的元素存入result数组；
	}
	for( i = 0; i < re_len; ++i) {	// 进行冒泡排序；
		flag = 0;
		for( j = 0; j < re_len-i-1; ++j) {
			if(result[j] < result[j+1]) {
				int temp = result[j];
				result[j] = result[j+1];
				result[j+1] = temp;
				flag = 1;
			}
		}
		if(flag == 0) break;
	}
	printf("%d",result[0]);
	for( i = 1; i < re_len; ++i) {
		printf(" %d",result[i]);
	}
	return 0;
}

void judgeCallatz(int n,int len) {
	int step, i;
	step = 0;	i = 0;
	while( n != 1 ) {
		if(n%2 == 0) n /= 2;
		else n = (n*3+1)/2;
		for( i = 0; i < len; ++i) {
			if( n==num[i] && mark[i]==0 ) {
				mark[i] = 1;
			}
		}
		++step;
	}
}