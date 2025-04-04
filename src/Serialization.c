#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

#include "Main.h"
#include "Serialization.h"
#include "Config.h"

void create_dir()
{
    const char *pathtdir = ".listu";

    char tempPath[BUFFER_F2];
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
        perror("Erro ao criar diretório .listu \n");
        return;
    }
    return;
}


void init()
{
    create_dir();
    create_config_file();
}

void list_all()
{
    const char *pathtdir = ".listu";

    DIR *directory = opendir(pathtdir);

    if (directory == NULL)
    {
        perror("Erro ao acessar o diretório .listu *** Possível solução:\n\n\t> listu init\n\n");
        return;
    }

    struct dirent *entry;

    printf("%s", LISTU_VERSION);
    printf("\t--------------------------------\n");
    while ((entry = readdir(directory)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        if (strcmp(entry->d_name, "config.toml") == 0)
            continue;

        struct stat st;
        char full_path[BUFFER_F2];

        snprintf(full_path, sizeof(full_path), "%s/%s", pathtdir, entry->d_name);

        if (stat(full_path, &st) == -1) {
            perror("Erro ao verificar arquivos.");
            continue;
        }
        
        if (S_ISDIR(st.st_mode))
            continue;

        printf("\t* %s \n", entry->d_name);
    }

    closedir(directory);
}

void create_file(const char *file_name) 
{
    const char *pathtdir = ".listu";
    char pathtfile[BUFFER_F1];

    snprintf(pathtfile, sizeof(pathtfile), "%s/%s", pathtdir, file_name);

    FILE *list_file = fopen(pathtfile, "w");
    if (list_file == NULL)
    {
        perror("Erro ao abrir o arquivo da lista de tarefas\n");
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

void print_with_nlines(const char *file_name)
{
    const char *pathtdir = ".listu";
    char pathtfile[BUFFER_F1];
    char output_file[BUFFER_F2];
    int lines = 0;

    snprintf(pathtfile, sizeof(pathtfile), "%s/%s", pathtdir, file_name);

    FILE *list_file = fopen(pathtfile, "r");
    if (list_file == NULL)
    {
        perror("Erro ao abrir o arquivo da lista de tarefas. Arquivo pode não ter sido criado ou nome pode estar incorreto.");
        return;
    }
    else 
    {   
        printf("%s", LISTU_VERSION);
        printf("\tListu %s \n", file_name);
        printf("\t--------------------------------\n");
        while (fgets(output_file, sizeof(output_file), list_file) != NULL)
        {
            printf("%d\t* %s", lines, output_file);
            lines++;
        }
        printf("\n");
    }
    fclose(list_file);
    return;
}
void print_without_nlines(const char *file_name)
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
        printf("%s", LISTU_VERSION);
        printf("\tListu %s \n", file_name);
        printf("\t--------------------------------\n");
        while (fgets(output_file, sizeof(output_file), list_file) != NULL)
        {
            printf("\t* %s", output_file);
        }
        printf("\n");
    }
    fclose(list_file);
    return;
}

void write_content(const char *input, const char *file_name)
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

