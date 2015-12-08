#include <stdio.h>
#include <stdlib.h>

#define MIN_VALUE 100
#define MAX_VALUE 1000

int palindromic(int n) {
	static int i;
	static char buf[7];
	sprintf(buf, "%d", n);

	int max = (sizeof(buf) - 2);
	int median = (sizeof(buf) - 1) / 2;
	for (i = 0; i < median; i++) {
		if (buf[i] != buf[max-i]) return 0;
	}

	return 1;
}

int main() {
	static int n, x, y;

	int result = 0;
	for (x = MAX_VALUE-1; x >= MIN_VALUE; x--) {
		for (y = MAX_VALUE-1; y >= MIN_VALUE; y--) {
			n = x * y;
			if (n >= MAX_VALUE * MAX_VALUE) continue;
			if (n < result || n < MAX_VALUE * MIN_VALUE) break;
			if (palindromic(n) && n > result) {
				result = n;
				break;
			}
		}
	}

	printf("Result: %d\n", result);

	return 0;
}
