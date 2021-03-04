#ifndef _KEYGEN_ALPHANUMERIC_H
#define _KEYGEN_ALPHANUMERIC_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "tools.h"

#define UPPER 1
#define LOWER 2
#define NUMBER 3

char *encrypt_alphanumeric(char*, char*,unsigned int);
char *repair_alphanumeric(char **);

#endif
