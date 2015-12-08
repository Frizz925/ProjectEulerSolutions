#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN_VALUE 1
#define MAX_VALUE 10

int* generate_memes(int n, int *len) {
	static int *pepes;
	char memes[n+1];
	int i, p, q, flag;

	for (i = 0; i < n+1; i++) {
		memes[i] = 0;
	}

	p = 2; q = 0;
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
	int i, len;
	int *memes = generate_memes(20, &len);
	for (i = 0; i < len; i++) {
		printf("%d\n", memes[i]);
	}
	return 0;
}
