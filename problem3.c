#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define VALUE 600851475143

int main() {
	long i = 2;
	long n = VALUE;
	int lastFactor;

	for (;;i++) {
		while (n % i == 0) {
			n /= i;
		}
		
		if (n == i || n == 1) {
			break;
		}
	}

	printf("Result: %ld\n", i);

	return 0;
}
