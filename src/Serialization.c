#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>


#include "Serialization.h"

void create_dir()
{
    const char *pathtdir = ".listu";

    char tempPath[1024];
    strcpy(tempPath, pathtdir);

    char *current = tempPath;
    while ((current = strchr(current, '/')) != NULL)
    {
        *current = '\0';
        if (mkdir(tempPath, 0755) && errno != EEXIST)
        {
            perror("Erro ao criar diretório .listu");
            return;
        }
        *current = '/';
        current++;
    }
    
    if (mkdir(tempPath, 0755) && errno != EEXIST)
    {
        perror("Erro ao criar diretório .listu");
        return;
    }
    return;
}

void create_file(const char *file_name) 
{
    const char *pathtdir = ".listu";
    char pathtfile[BUFFER_F1];

    snprintf(pathtfile, sizeof(pathtfile), "%s/%s", pathtdir, file_name);

    FILE *list_file = fopen(pathtfile, "w");
    if (list_file == NULL)
    {
        perror("Erro ao abrir o arquivo da lista de tarefas");
        return;
    }
    fclose(list_file);
    return;
}

void remove_file(const char *file_name)
{
    const char *pathtdir = ".listu";
    char pathtfile[BUFFER_F1];

    snprintf(pathtfile, sizeof(pathtfile), "%s/%s", pathtdir, file_name);

    FILE *list_file = fopen(pathtfile, "r");

    if (list_file == NULL)
    {
        perror("Erro ao abrir o arquivo da lista de tarefas. Arquivo pode não ter sido criado ou nome pode estar incorreto.");
        return;
    }

    if (remove(pathtfile) == EXIT_SUCCESS)
    {
        printf("Lista de tarefas %s removida.\n", file_name);
        return;
    }
    else { printf("Não foi possível remover a lista de tarefas. Verifique se o nome ou se a lista existe.\n");}
}

void print_content(const char *file_name)
{
    const char *pathtdir = ".listu";
    char pathtfile[BUFFER_F1];
    char output_file[BUFFER_F2];

    snprintf(pathtfile, sizeof(pathtfile), "%s/%s", pathtdir, file_name);

    FILE *list_file = fopen(pathtfile, "r");
    if (list_file == NULL)
    {
        perror("Erro ao abrir o arquivo da lista de tarefas. Arquivo pode não ter sido criado ou nome pode estar incorreto.");
        return;
    }
    else 
    {
        printf("Listu %s: \n", file_name);
        while (fgets(output_file, sizeof(output_file), list_file) != NULL)
        {
            printf("* %s", output_file);
        }
        printf("\n");
    }
    fclose(list_file);
    return;
}

void write_content(const char *file_name, const char *input)
{
    const char *pathtdir = ".listu";
    char pathtfile[BUFFER_F1];

    snprintf(pathtfile, sizeof(pathtfile), "%s/%s", pathtdir, file_name);

    FILE *list_file = fopen(pathtfile, "a");
    if (list_file == NULL)
    {
        perror("Erro ao abrir o arquivo da lista de tarefas. Arquivo pode não ter sido criado ou nome pode estar incorreto.");
        return;
    }
    else
    {
        fprintf(list_file, "%s\n", input);
        fflush(list_file);
    }
    fclose(list_file);
    return;
}