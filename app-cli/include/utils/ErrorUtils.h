#ifndef ERROR_UTILS_H
#define ERROR_UTILS_H


typedef const char *error;

/**
 * @typedef error
 * @brief Representa um erro como uma string constante.
 *
 * Esse tipo é utilizado para padronizar o retorno de mensagens de erro
 * em toda a aplicação, facilitando o tratamento e exibição das mensagens.
 */
typedef const char *error;

/**
 * @brief Erro de entrada não especificada.
 *
 * Esse erro é retornado quando o usuário não fornece um nome de arquivo
 * ou fornece um nome inválido como argumento no input.
 *
 * @return Mensagem de erro descritiva.
 */
error non_specified_err();

/**
 * @brief Erro de parâmetros insuficientes.
 *
 * Indica que o usuário não forneceu a quantidade necessária de parâmetros
 * para a execução do comando desejado.
 *
 * @return Mensagem de erro descritiva.
 */
error not_enough_params();

/**
 * @brief Erro de comando inválido.
 *
 * Esse erro é retornado quando o comando digitado pelo usuário não é
 * reconhecido ou está malformado, não correspondendo a nenhum comando válido.
 *
 * @return Mensagem de erro descritiva.
 */
error throw_invalid();

/**
 * @brief Erro ao criar diretório.
 *
 * Retorna um erro quando o programa falha ao tentar criar o diretório necessário
 * para armazenar os dados do usuário (como o diretório `.listu`).
 *
 * @return Mensagem de erro descritiva.
 */
error err_to_create_dir();

/**
 * @brief Erro ao acessar diretório.
 *
 * Indica que o diretório `.listu` não pôde ser acessado, seja por não existir
 * ou por falta de permissões.
 *
 * @return Mensagem de erro descritiva.
 */
error acess_dir();

/**
 * @brief Erro ao acessar arquivo.
 *
 * Esse erro é retornado quando o programa enfrenta problemas ao tentar
 * ler ou escrever arquivos necessários para o funcionamento do Listu.
 *
 * @return Mensagem de erro descritiva.
 */
error err_to_acess_file();

#endif