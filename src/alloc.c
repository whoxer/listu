//Escrito por whoxer

#include "alloc.h"
#include "tasks.h"

int isit_void(task *STACK) {
 	if (STACK->next == NULL)
  		return SUCESS;
	 else
		return FAILURE;
}

task *alloc() {
 	task *new = (task *) malloc(sizeof(task));

 	if(!new) {
  		printf("Sem memoria disponivel!\n");
 		exit(1);
 	} else {
		printf(" > ");
		scanf("%s", new->content);
  		return new;
 	}
}
