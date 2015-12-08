#include <stdio.h>
#include <math.h>

typedef struct Node {
	char data;
	struct Node* link[10];
} Node;

Node *root;

void insert(Node **node, long key, char data, int depth) {
	if (*node == NULL) {

	} else {

	}
}

long prime(long n) {
	long i, j, p, flag;
	char list[n+1];

	for (i = 2; i <= n; i++) {
		list[i] = 0;
	}

	p = 2;
	while (flag != 1) {
		for (j = p; j <= n; j += p) {
			if (j == p) continue;
			list[j] = 1;
		}
		for (i = p+1; i <= n; i++) {
			flag = 1;
			if (list[i] == 0) {
				flag = 0;
				p = i;
				break;
			}
		}
	}

	int result = 0;
	for (i = 2; i <= n; i++) {
		if (list[i] == 0) result++;
	}
	return result;
}

int main() {
	prime(pow(10, 10));
	return 0;
}
