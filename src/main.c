#include "tasks.h"

int main(void) {
	int opt;
	task *STACK = (task *) malloc(sizeof(task));

	printf(" tasks.c, v0.0.1\n escrito por %s\n\n", AUTHOR);
	printf(" \t[1] criar nova tarefa\n"); //push
	printf(" \t[2] exibir todas as tarefas\n"); //show
	printf(" \t[3] excluir primeira tarefa\n"); //pop
	printf(" \t[4] excluir todas as tarefas\n");//free
	printf(" \t[5] sair\n");

	if (!STACK) {
		printf("Sem memória disponível.");
		exit(1);
	} else {
		init(STACK);

		do {
			opt = menu();
			option(STACK, opt);

		} while (opt != 5);
	}
	return 0;
}
