#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "Serialization.h"
#include "Params.h"

Args params[] = {
    {"init", create_dir}, // Inicia diretório para o programa Listu
    {"new", newparam}, // Cria arquivo para a lista de tarefas
    {"help", help_param}, // Exibe menu de ajuda
    {"show", printparam}, // Escreve conteúdo de arquivo de lista de tarefas na tela
    {"add", add_param}
};

int main(int argc, char *argv[]) {
    if (argc < 2)
    {
        help_param(argc, argv);
        return EXIT_FAILURE;
    }
    for (Args *arg = params; arg->args != NULL; arg++)
    {
        if (strcmp(argv[1], arg->args) == EXIT_SUCCESS)
        {
            arg->function(argc, argv);
            break;
        }
    }
    return EXIT_SUCCESS;
}