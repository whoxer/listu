#ifndef PARAMS_H
#define PARAMS_H

#include <stdio.h>
#include <stdlib.h>

// #include "LinkedList.h"

typedef void (*ArgsFn) (int argc, char *argv[]);

typedef struct 
{
    const char *args;
    ArgsFn function;
} Args;


/**
 * @brief Cria diretório
 * 
 * @param argc 
 * @param argv 
 * @param list 
 */
void initparam(int argc, char *argv[]);

/**
 * @brief Cria lista de tarefas
 * 
 * @param argc 
 * @param argv 
 * @param list 
 */
void newparam(int argc, char *argv[]);

/**
 * @brief Exibe tarefas adicionado ao arquivo da lista de tarefas respectiva
 * 
 * @param argc 
 * @param argv 
 * @param list 
 */
void printparam(int argc, char *argv[]);

/**
 * @brief Tela de ajuda é exibida
 * 
 * @param argc 
 * @param argv 
 * @param list 
 */
void help_param(int argc, char *argv[]);

/**
 * @brief Invalida comando inexistente
 * 
 * @param argc 
 * @param argv 
 * @param list 
 */
void throw_invalid(int argc, char *argv[]);

void add_param(int argc, char *argv[]);


#endif