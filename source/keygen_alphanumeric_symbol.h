#ifndef _KEYGEN_ALPHANUMERIC_SYMBOL_H
#define _KEYGEN_ALPHANUMERIC_SYMBOL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "tools.h"

#define UPPER 1
#define LOWER 2
#define NUMBER 3
#define SYMBOL 4
#define ARRAY_SIZE 5

char *encrypt_alphanumeric_symbol(char*, char*,unsigned int);
char *repair_alphanumeric_symbol(char **);

#endif
