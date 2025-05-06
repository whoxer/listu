#ifndef ERROR_UTILS_H
#define ERROR_UTILS_H

/**
 * @typedef error
 * @brief Define um tipo de erro como uma string constante.
 *
 * Esse tipo é usado para representar mensagens de erro legíveis ao usuário,
 * adaptadas à linguagem configurada (português ou inglês).
 */
typedef const char *error;

/**
 * @brief Retorna um erro de nome de arquivo não especificado ou incorreto.
 *
 * Essa função é chamada quando o usuário omite o nome do arquivo no input,
 * ou fornece um nome que não pode ser processado. A mensagem retornada é
 * multilíngue, baseada na configuração de idioma.
 *
 * @return Mensagem de erro formatada de acordo com o idioma configurado.
 */
error non_specified_err();

/**
 * @brief Retorna um erro quando parâmetros insuficientes são fornecidos.
 *
 * Esse erro ocorre quando o comando do usuário está incompleto, sem todos
 * os argumentos necessários. Sugestões de solução são incluídas na mensagem.
 * O idioma da resposta depende da configuração atual.
 *
 * @return Mensagem de erro detalhada conforme o idioma definido.
 */
error not_enough_params();

/**
 * @brief Retorna um erro para comandos inválidos.
 *
 * Usado quando o comando digitado pelo usuário não é reconhecido como válido.
 * A mensagem sugere o uso do comando `listu help` para obter ajuda.
 *
 * @return Mensagem de erro multilíngue indicando comando inválido.
 */
error throw_invalid();

/**
 * @brief Retorna um erro ao tentar criar o diretório `.listu`.
 *
 * Essa função é usada quando há falha ao criar o diretório de dados
 * da aplicação. A mensagem informa o usuário sobre essa falha em português ou inglês.
 *
 * @return Mensagem de erro de criação de diretório, de acordo com o idioma.
 */
error err_to_create_dir();

/**
 * @brief Retorna um erro ao tentar acessar o diretório `.listu`.
 *
 * Ocorre quando o diretório `.listu` não existe ou não pode ser acessado.
 * A mensagem sugere a execução de `listu init` como possível solução.
 *
 * @return Mensagem de erro multilíngue com sugestão de correção.
 */
error acess_dir();

/**
 * @brief Retorna um erro relacionado a falhas com arquivos.
 *
 * Essa função cobre problemas de leitura e escrita de arquivos. Pode indicar que o
 * arquivo não foi criado corretamente, está corrompido, ou o nome está incorreto.
 *
 * @return Mensagem de erro multilíngue sobre acesso a arquivos.
 */
error err_to_acess_file();

#endif