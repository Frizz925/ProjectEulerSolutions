#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN_VALUE 1
#define MAX_VALUE 20

int* generate_memes(int n, int *len) {
	static int *pepes;
	char memes[n+1];
	int i, p, q, flag;

	for (i = 0; i < n+1; i++) {
		memes[i] = 0;
	}

	p = 2; q = 1;
	while (flag != 1) {
		for (i = p; i <= n; i += p) {
			if (i == p) continue;
			memes[i] = 1;
		}

		flag = 1;
		for (i = p+1; i <= n; i++) {
			if (memes[i] == 0) {
				flag = 0;
				p = i;
				q++;
				break;
			}
		}
	}

	*len = q;
	p = 0;
	pepes = (int*) malloc(sizeof(int) * q);
	for (i = 2; i <= n; i++) {
		if (!memes[i]) {
			pepes[p] = i;
			p++;
		}
	}

	return pepes;
}

int main() {
	double a;
	int i, len, result = 1;
	int *memes = generate_memes(MAX_VALUE, &len);

	for (i = 0; i < len; i++) {
		a = floor(log(MAX_VALUE) / log((double) memes[i]));
		result *= (int) pow((double) memes[i], a);
		printf("%d\n", memes[i]);
	}

	printf("Result: %d\n", result);

	return 0;
}
