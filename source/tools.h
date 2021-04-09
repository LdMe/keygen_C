#ifndef TOOLS_H
#define TOOLS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define UPPER 1
#define LOWER 2
#define NUMBER 3
#define SYMBOL 4
#define ARRAY_SIZE 5

int str_len(char*);
int is_type(char, unsigned int);
int is_lower(char);
int is_upper(char);
int is_num(char);
int is_symbol(char);
char change_to_type(char,unsigned int);
char change_to_upper(char);
char change_to_lower(char);
char change_to_number(char);
char change_to_symbol(char);

void lower(char *);
void upper(char*);
int abs(int);
int find(char*, char);
int mcd(int, int);
char *repair(char**);
char **encrypt(char*, char*,char*,unsigned int);
char **encrypt_fixed_length(char*, char*,char*,unsigned int,int);


#endif
