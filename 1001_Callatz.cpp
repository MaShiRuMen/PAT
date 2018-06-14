#include <stdio.h>

int StepsToOne(int n) {
	int step = 0;
	if ( n > 1000 ) return 0;
	while(n != 1) {
		if(n%2 == 0) n /= 2;
		else n = (n*3+1)/2;
		++step;
	}
	return step;
}

int main(void) {
	int n, step;
	scanf("%d",&n);
	step = StepsToOne(n);
	printf("%d\n",step);
	return 0;
}
