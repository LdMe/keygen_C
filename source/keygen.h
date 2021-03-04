#ifndef _KEYGEN_H
#define _KEYGEN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "tools.h"

#define UPPER 1
#define LOWER 2
#define NUMBER 3

char *encrypt(char*, char*);
char *repair(char **);

#endif
