#include <stdio.h>

int sum;

int fibonacci(int a, int b, int max) {
	if (a >= max) return;
	printf("%d, ", a);
	sum += (a % 2 == 0) ? a : 0;
	fibonacci(b, a+b, max);
}

int main() {
	sum = 0;
	fibonacci(1, 2, 4000000);
	printf("\n%d\n", sum);
	return 0;
}
