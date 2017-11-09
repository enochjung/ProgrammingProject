#ifndef __FILE_MANAGE_H__
#define __FILE_MANAGE_H__

#include "header.h"

word* get_word_list(int file_number, int print_way);
void free_word_list(word* target);
void create_file(word* target);
void overwrite_file(int file_number, word* target);
int get_last_number();

#endif
