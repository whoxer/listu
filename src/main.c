#include "tasks.h"

int main(void) {
	task *STACK = (task *) malloc(sizeof(task));

	if (!STACK) {
		printf("Sem memória disponível.");
		exit(1);
	} else {
		init(STACK);
		int opt;

		do {
			opt = menu();
			option(STACK, opt);
		} while (opt);

		free(STACK);
	}
	return 0;
}
