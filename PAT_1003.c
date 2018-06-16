/*
	1003 我要通过！

	Description：

	“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送：
	只要读入的字符串满足下列条件系统就输出“答案正确”，否则输出“答案错误”。
	得到“答案正确”的条件是：
	1. 字符串中必须仅有P,A,T这三种字符，不可以包含其他字符；
	2. 任意形如xPATx的字符串都可以获得“答案正确”，其中x或者是字符串，或者是仅由字母A组成的字符串；
	3. 如果aPbTc是正确的，那么aPbATca也是正确的，其中a,b,c均或者是空字符串，或者是仅由字母A组成的字符串。
	
	现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的的。

	输入格式：每个测试输入包含1个测试用例。第1行给出一个自然数n,是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。
	输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。

	输入样例：
	8
	PAT
	PAAT
	AAPATAA
	AAPAATAAAA
	xPATx
	PT
	Whatever
	APAAAPTAA

	输出样例：
	YES
	YES
	YES
	YES
	NO
	NO
	NO
	NO

 */

#include <stdio.h>
#define MAXLEN 101

int judgeString(char str[]);

int main(void) {
	char str[MAXLEN];
	int count;
	scanf("%d",&count);
	while(count--) {
		scanf("%s",str);
		printf("%s\n", str);
		if (judgeString(str) == 1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

int judgeString(char str[]) {
	int i, flag, flag_p, flag_t;
	int num[5] = {0};
	printf("%d %d %d\n", num[0], num[1], num[2]);
	int point;
	point = 0;
	flag_p = flag_t = flag = 0;
	for(i = 0;str[i] != 0; ++i) {
		if (str[i] == 'A') {
			num[point]++;
		}
		else if(str[i] == 'P') {
			if (flag_p == 1) { flag = 0; break;}
			else { flag_p = 1; point = 1;}
		}
		else if(str[i] == 'T') {
			if (flag_t == 1) { flag = 0; break;}
			else { flag_t = 1; point = 2;}
		}
		else { flag = 1; break;}
	}
	printf("%d %d %d\n", num[0], num[1], num[2]);
	printf("%d %d %d\n", flag_p, flag_t, flag);
	if (flag == 1 || num[1] == 0) return 0;
	if (flag_p != 1 || flag_t != 1) return 0;
	if (num[2] != num[0]*num[1]) return 0;
	return 1;
}