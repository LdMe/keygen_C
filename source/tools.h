#ifndef TOOLS_H
#define TOOLS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int str_len(char*);
int is_minus(char);
int is_mayus(char);
int is_num(char);
void lower(char *);
void upper(char*);
int abs(int);
int find(char*, char);
int mcd(int, int);


#endif
