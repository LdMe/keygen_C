#ifndef _KEYGEN_ALPHANUMERIC_H
#define _KEYGEN_ALPHANUMERIC_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "tools.h"

char *encrypt_alphanumeric(char*, char*,unsigned int);
char *repair_alphanumeric(char **);

#endif
