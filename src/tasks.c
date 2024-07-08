// Escrito por whoxer
#include "tasks.h"
#include "alloc.h"

// Inicia pilha de tarefas com valor zero e aponta ponteiro da pilha para NULO.
void init(task *STACK) {
	STACK->next = NULL;
	size = 0;
}

int menu(void) {
	// code
}

// TODO Programar depois das funções que manipulam as pilhas.
void option(task *STACK, int opt) {
	task *tmp;

	switch (opt) {
		case 0:
			break;
	}
}

// Exibe número de tarefas na stack
// TODO: Codificar a exibição de título +prévia do conteúdo das tarefas
void show(task *STACK) {
	if (isit_void(STACK)) {
		printf("Sem tarefas. Pilha vazia!\n\n");
		return;
	}

	task *tmp;
	tmp = STACK->next;
	printf("Tarefas: ");

	while(tmp != NULL) {
		printf("%5d", tmp->num);
		tmp = tmp->next;
	}
	printf("\n 	");

	int count;

	for (count = 0; count < size; count++)
		printf(" ^ ");

	printf("Ordem: ");

	for (count = 0; count < size; count++)
		printf("%5d", count + 1);
	printf("\n\n");
}

void free(stack *STACK) {

}
