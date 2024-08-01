// Escrito por whoxer
#include "tasks.h"
#include "alloc.h"
#include <string.h>


// Tamanho da pilha
int size;

// Inicia pilha de tarefas com valor zero e aponta ponteiro da pilha para NULO.
void init(task *STACK) {
	STACK->next = NULL;
	size = 0;
}

int menu(void) {
	int opt;

	printf("\n: ");
	scanf("%d", &opt);

	return opt;
}

// TODO Programar depois das funções que manipulam as pilhas.
void option(task *STACK, int opt) {
	task *tmp;

	switch (opt) {
		case 1:
			push(STACK);
			break;
		case 2:
		        show(STACK);
			break;
		case 3:
		        tmp = pop(STACK);
			if (tmp != NULL) {
			    printf("\nTarefa '%s' removida\n\n", tmp->content);
			}
			break;
		case 4:
		        free_stack(STACK);
			init(STACK);
			break;
		case 5:
			exit(SUCESS);
			break;
		default:
		        printf("'%d' é um comando inválido.", opt);
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

	while (tmp != NULL) {
		printf("\n\t * %s", tmp->content);
		tmp = tmp->next;
	}
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

		while (tmp->next != NULL)
			tmp = tmp->next;

		tmp->next = new;
	}
	size++;
}

task *pop(task *STACK) {
	if (STACK->next == NULL) {
		printf("Lista de tarefas vazia.\n\n");
		return NULL;
	} else {
	    task *last = STACK->next, *penult = STACK;

		while (last->next !=  NULL) {
		    penult = last;
			last = last->next;
		}
		penult->next = NULL;
		size--;
		return last;
	}
}
