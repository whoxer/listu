#ifndef SERIALIZATION_H
#define SERIALIZATION_H


#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#define MAX_LINES 99

#define BUFFER_F0 128
#define BUFFER_F1 256
#define BUFFER_F2 1024

//#define MAX_INPUT (BUFFER_F2 - 1)


void init();
void create_dir();
void create_file(const char *file_name);


/**
 * @brief Exibe conteúdo de arquivos
 * 
 * @param file_name 
 */
void print_with_nlines(const char *file_name);
void print_without_nlines(const char *file_name);

/**
 * @brief Escreve conteúdo em arquivos
 * 
 * @param file_name 
 */
void write_content(const char *file_name, const char *input);
void remove_file(const char *file_name);

void list_all();

#endif