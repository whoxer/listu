#include "utils/Params.h"
#include "utils/Serialization.h"
#include "core/Main.h"
#include "utils/Config.h"
#include "utils/ErrorUtils.h"


#include <string.h>

/**
 * @brief Inicia diretório .listu
 * 
 * @param argc 
 * @param argv 
 */
void initparam(int argc, char *argv[])
{
    (void)argv;

    if (argc < 2)
    {
        perror(not_enough_params());
        return;
    }
    init();
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
        perror(non_specified_err());
        return;
    }
    create_file(argv[2]);
}

void removeparam(int argc, char *argv[])
{
    if (argc < 3)
    {
        perror(not_enough_params());
        return;
    }
    remove_file(argv[2]);
}

void printparam(int argc, char *argv[])
{
    load_config();

    if (argc < 3)
    {
        perror(non_specified_err());
    }

    if (show_lines())
    {
        print_with_nlines(argv[2]);
    } else {
        print_without_nlines(argv[2]);
    }    
}

void listparam(int argc, char *argv[])
{
    (void)argv;
    
    if (argc < 2) { perror(throw_invalid()); return;}

    list_all();
}

void add_param(int argc, char *argv[])
{
    if (argc < 4)
    {
        perror(non_specified_err());
        return;
    }
    write_content(argv[2], argv[3]);
}

void help_param(int argc, char *argv[])
{
    (void)argc; 
    (void)argv;

    if (strcmp(language(), "pt-br") == 0)
    {
        printf("%s", LISTU_VERSION);
        printf("Uso: listu [OPÇÃO]\n");
        printf("  init                    Inicia diretório .listu \n");
        printf("  new  [ARQUIVO]          Cria lista de tarefas \n");
        printf("  add  [TAREFA] [ARQUIVO] Adiciona tarefas para arquivo \n");
        printf("  show [ARQUIVO]          Exibe tarefas de um arquivo \n");
        printf("  help                    Mostra este menu de ajuda \n");
        printf("  rm, remove [ARQUIVO]    Remove lista de tarefas\n");
        printf("  list                    Lista todas os listus existentes \n");
    }
    if (strcmp(language(), "en") == 0)
    {
        printf("%s", LISTU_VERSION);
        printf("Usage: listu [OPTION]\n");
        printf("  init                  Initializes the .listu directory \n");
        printf("  new  [FILE]           Creates a task list \n");
        printf("  add  [TASK] [FILE]    Adds tasks to the file \n");
        printf("  show [FILE]           Displays tasks from a file \n");
        printf("  help                  Shows this help menu \n");
        printf("  rm, remove [FILE]     Removes the task list\n");
        printf("  list                  Lists all existing listus \n");
    }
}

void throw_invalid_param(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    
    perror(throw_invalid());

    help_param(0, NULL);
}
