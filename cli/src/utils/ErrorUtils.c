#include "utils/ErrorUtils.h"
#include "utils/Config.h"

#include <string.h>

error non_specified_err()
{
    load_config();

    if (strcmp(language(), "pt-br") == 0) 
        return "Erro ** Nome incorreto ou nenhum arquivo especificado."; 
    if (strcmp(language(), "en") == 0) 
        return "Error ** Incorrect name or no file specified.";

    return "** ";
}

error not_enough_params()
{
    load_config();

    if (strcmp(language(), "pt-br") == 0)
        return "Erro ** Número de parâmetros não é suficiente. Possíveis soluções: \n\tlistu help";
    if (strcmp(language(), "en") == 0)
        return "Error ** Number of parameters is not enough. Possible solutions: \n\tlistu help";

    return "** ";
}

error throw_invalid()
{
    load_config();

    if (strcmp(language(), "pt-br") == 0)
        return "Erro ** Comando inválido. Possíveis soluções: \n\tlistu help";
    if (strcmp(language(), "en") == 0)
        return "Error ** Invalid command. Possible solutions: \n\tlistu help";

    return "** ";
}

error err_to_create_dir(){
    load_config();

    if (strcmp(language(), "pt-br") == 0)
        return "Erro ao criar diretório .listu";
    if (strcmp(language(), "en") == 0)
        return "Error creating .listu directory";

    return "** ";
}

error acess_dir()
{
    load_config();

    if (strcmp(language(), "pt-br") == 0)
        return "Erro ao acessar o diretório .listu *** Possível solução:\n\n\t> listu init\n\n";
    if (strcmp(language(), "en") == 0)
        return "Error accessing .listu directory *** Possible solution:\n\n\t> listu init\n\n";

    return "** ";
}

error err_to_acess_file()
{
    load_config();

    if (strcmp(language(), "pt-br") == 0)
        return "Erro ao verificar ou abrir arquivos. Arquivo pode não ter sido criado ou nome pode estar incorreto.";
    if (strcmp(language(), "en") == 0)
        return "Error checking or opening files. File may not have been created or name may be incorrect.";

    return "** ";
}
