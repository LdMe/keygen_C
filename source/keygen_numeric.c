/*
** keygen.c
** File description:
** main keygen functions
*/
#include "keygen_numeric.h"

char *encrypt_numeric(char *word, char *key,unsigned int seed)
{
    int charCount = 10;
    char firstChar = 48;

    char *lista = malloc(sizeof(char) * (charCount + 1));
    for (int i = 0; i <= charCount ; i++)
    {
        char actualChar = i + firstChar;
        lista[i] = actualChar;
    }
    lista[charCount] = '\0';
    char **results = encrypt(word, key, lista, seed);
    return (results[0]);
    
}
