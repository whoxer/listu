#include "Params.h"
#include "Serialization.h"
#include "Main.h"

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

void removeparam(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Erro.\n");
        return;
    }
    remove_file(argv[2]);
}

void printparam(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Erro. Nenhum arquivo especificado! \n");
    }
    print_content(argv[2]);
}

void listparam(int argc, char *argv[])
{
    (void)argv;
    
    if (argc < 2) { printf("Erro ** Comando inválido."); return;}

    list_all();
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

    printf("%s", LISTU_VERSION);
    printf("Uso: listu [OPÇÃO]\n");
    printf("  init                    Inicia diretório .listu \n");
    printf("  new  [ARQUIVO]          Cria lista de tarefas \n");
    printf("  add  [ARQUIVO] [TAREFA] Adiciona tarefas para arquivo \n");
    printf("  show [ARQUIVO]          Exibe tarefas de um arquivo \n");
    printf("  help                    Mostra este menu de ajuda \n");
    printf("  rm, remove [ARQUIVO]    Remove lista de tarefas\n");
    printf("  list                    Lista todas os listus existentes \n");
}

void throw_invalid(int argc, char *argv[])
{
    (void)argc;

    printf("Erro: Comando '%s' inválido \n", argv[1]);

    help_param(0, NULL);
}
