#ifndef ERROR_UTILS_H
#define ERROR_UTILS_H


typedef const char *error;


error non_specified_err();
error not_enough_params();
error throw_invalid();

error err_to_create_dir();
error acess_dir();
error err_to_acess_file();

#endif