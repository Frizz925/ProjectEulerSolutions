#include <stdio.h>

int main() {
	int w = 8;
	int h = 5;
	int i;

	char map[][10] = {
		"  *   * ",
		"  *   **",
		" ** * **",
		"***** **",
		"********"
	};

	for (i = 0; i < 5; i++) {
		printf("%s\n", map[i]);
	}

	return 0;
}
