// Escrito por whoxer
#include "tasks.h"
#include "alloc.h"

// Tamanho da pilha
int size;

// Inicia pilha de tarefas com valor zero e aponta ponteiro da pilha para NULO.
void init(task *STACK) {
	STACK->next = NULL;
	size = 0;
}

int menu(void) {
	int opt;

	printf(" tasks.c, v0.0.1\n escrito por %s\n\n", AUTHOR);
	printf(" [1] criar nova tarefa\n"); //push
	printf(" [2] exibir todas as tarefas\n"); //show
	printf(" [3] excluir ultima tarefa\n"); //pop
	printf(" [4] excluir todas as tarefas\n");//free
	printf(" [5] sair");

	return opt;
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

void free_stack(task *STACK) {
	if (!isit_void(STACK)) {
		task *nextTask,
		     *current;

		current = STACK->next;
		while(current != NULL) {
			nextTask = current->next;
			free(current);
			current = nextTask;
		}
	}
}

void push(task *STACK) {
	task *new = alloc();
	new->next = NULL;

	if (isit_void(STACK)) {
		STACK->next = new;
	} else {
		task *tmp = STACK->next;

		while (tmp->next != NULL) {
			tmp = tmp->next;

			tmp->next = new;
		}
	}
	size++;
}

task *pop(task *STACK) {
	if (STACK->next == NULL) {
		printf("Lista de tarefas vazia.\n\n");
		return NULL;
	} else {
		task *last = STACK->next,
		     *penult = STACK;

		while (last->next != NULL) {
			penult = last;
			last = last->next;
		}
		penult->next = NULL;
		size--;
		return last;
	}
}
