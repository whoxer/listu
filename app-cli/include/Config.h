#ifndef CONFIG_H
#define CONFIG_H


#include "Toml.h"
#include "Serialization.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    bool lines;
} Config;


/**
 * @brief Cria arquivo de configuração TOML
 * 
 */
int create_config_file();




void load_config();
bool show_lines();



#endif
