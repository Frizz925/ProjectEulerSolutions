#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct BST {
	long key, value;
	struct BST *left;
	struct BST *right;
} BST;

BST *ftree, *gtree, *curr;

void insert(BST **node, long key, long value) {
	if (*node == NULL) {
		BST *temp = (BST*) malloc(sizeof(BST));
		temp->key = key;
		temp->value = value;
		temp->left = temp->right = NULL;
		*node = temp;
	} else {
		curr = *node;
		// lebih kecil ke kiri
		// lebih besar ke kanan
		if (curr->key > key) {
			insert(&curr->left, key, value);
		} else if (curr->key < key) {
			insert(&curr->right, key, value);
		}
	}
}

BST* search(BST **node, long key) {
	if (*node == NULL) {
		return NULL;
	} else {
		curr = *node;
		if (curr->key == key) {
			return curr;
		} else if (curr->key > key) {
			return search(&curr->left, key);
		} else {
			return search(&curr->right, key);
		}
	}
}

long checkPrime(long n) {
	long i;
	for (i = 2; i < n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

long f(long n) {
	curr = search(&ftree, n);
	if (curr != NULL) {
		return curr->value;
	}

	long i, largest;
	for (i = 1; i <= n; i++) {
		if (checkPrime(i) && n % i == 0) largest = i;
	}
	insert(&ftree, n, largest);
	//printf("f(%ld): %ld\n", n, largest);
	return largest;
}

long g(long n) {
	curr = search(&gtree, n);
	if (curr != NULL) {
		return curr->value;
	}

	long i;
	long result = 0;
	for (i = 0; i < 9; i++) {
		result += f(n+i);
	}
	insert(&gtree, n, result);
	return result;
}

long h(long n) {
	long k, result;
	for (k = 2; k <= n; k++) {
		long gk = g(k);
		if (gk > result) result = gk;
		printf("g(%ld) = %ld\n", k, gk);
	}
	return result;
}

long main() {
	long i;
	for (i = pow(10, 16); i >= 2; i--) {
		printf("%ld\n", g(i));
	}
	//long result = h(100);
	//printf("Result: %ld\n", result);

	return 0;
}
