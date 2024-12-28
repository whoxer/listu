#include "Params.h"
#include "Serialization.h"

#include <string.h>

/**
 * @brief Inicia diretório .listu
 * 
 * @param argc 
 * @param argv 
 */
void initparam(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Erro.\n");
        return;
    }
    create_dir(argv[2]);
}

/**
 * @brief Cria nova lista de tarefas
 * 
 * @param argc 
 * @param argv 
 */
void newparam(int argc, char *argv[]) 
{
    if (argc < 3)
    {
        printf("Erro. Você não especificou nenhum nome para a sua lista! \n");
        return;
    }
    create_file(argv[2]);
}

void printparam(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Erro. Nenhum arquivo especificado! \n");
    }
    print_content(argv[2]);
}

void add_param(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Erro. Nome incorreto ou nenhum arquivo especificado! \n");
        return;
    }
    write_content(argv[2], argv[3]);
}

void help_param(int argc, char *argv[])
{
    (void)argc; 
    (void)argv;

    printf("Listu, v0.0.1 \n\n");
    printf("Uso: listu [OPÇÃO]\n");
    printf("  init                    Inicia diretório .listu \n");
    printf("  new  [ARQUIVO]          Cria lista de tarefas \n");
    printf("  add  [ARQUIVO] [TAREFA] Adiciona tarefas para arquivo \n");
    printf("  show [ARQUIVO]          Exibe tarefas de um arquivo \n");
    printf("  help                    Mostra este menu de ajuda \n");
}

void throw_invalid(int argc, char *argv[])
{
    (void)argc;

    printf("Erro: Comando '%s' inválido \n", argv[1]);

    help_param(0, NULL);
}
