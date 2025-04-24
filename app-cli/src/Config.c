#include "Config.h"

static Config listu_config = { .lines = false};


int create_config_file() 
{
    const char *pathtdir = ".listu", *file_name = "config.toml";
    char pathtfile[BUFFER_F1];

    snprintf(pathtfile, sizeof(pathtfile), "%s/%s", pathtdir, file_name);

    FILE *toml_config_file = fopen(pathtfile, "w");

    if (toml_config_file == NULL)
    {
        perror("Erro ao abrir o arquivo de configuração 'config.toml'. Arquivo pode ter sido excluído, movido de lugar ou até mesmo renomeado.\n");
        return EXIT_FAILURE;
    }

    fprintf(toml_config_file, "[general]\n\nlines = false\n");

    fclose(toml_config_file);
    return EXIT_SUCCESS;
}

void load_config()
{
    const char *pathtdir = ".listu", *file_name = "config.toml";
    char pathtfile[BUFFER_F1];

    snprintf(pathtfile, sizeof(pathtfile), "%s/%s", pathtdir, file_name);


    FILE *toml_file_ptr = fopen(pathtfile, "r");

    if (toml_file_ptr == NULL)
    {
        perror("Erro ao abrir o arquivo de configuração 'config.toml'. Arquivo pode ter sido excluído, movido de lugar ou até mesmo renomeado.\n");
        return;
    }

    char errbuf[200];
    toml_table_t *config = toml_parse_file(toml_file_ptr, errbuf, sizeof(errbuf));
    fclose(toml_file_ptr);

    if (!config)
    {
        fprintf(stderr, "Erro no parsing de arquivo de configuração 'config.toml': %s.", errbuf); 
        return;
    }

    toml_table_t *general = toml_table_in(config, "general");

    /**
     * @brief
     * 
     * Verificação todas as configurações presentes na tabela [general]
     * e passa os valores para a struct Config
     */
    if (general) 
    {
        toml_datum_t lines = toml_bool_in(general, "lines");
        if (lines.ok) listu_config.lines = lines.u.b;
    }

    toml_free(config);
}

bool show_lines()
{
    return listu_config.lines;
}