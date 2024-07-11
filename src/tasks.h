// Escrito por whoxer

#ifndef TASKS_H
#define TASKS_H

#define AUTHOR "whoxer"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Estrutura de dados da "Task" contendo o número de tarefas, o ponteiro FILE que guardará o conteúdo da Task
	e uma outra estrutura de dados que será chamada na pilha por conseguinte.
*/
struct Task {
	int num;
	char content[30];
	struct Task *next;
};


typedef struct Task task;


int menu(void);

void init(task *STACK);
void option(task *STACK, int opt);
void show(task *STACK);
void free_stack(task *STACK);
void push(task *STACK);

task *pop(task *STACK);

#endif
