/*
** keygen.c
** File description:
** main keygen functions
*/
#include "keygen_alphanumeric_symbol.h"

char *encrypt_alphanumeric_symbol(char *word, char *key,unsigned int seed, int length)
{
    int charCount = 97;
    char firstChar = 33;
    

    char *lista = malloc(sizeof(char) * (charCount + 1));
    for (int i = 0; i <= charCount ; i++)
    {
        char actualChar = i + firstChar;
        lista[i] = actualChar;
    }
    lista[charCount] = '\0';
    char **results = encrypt_fixed_length(word, key, lista, seed,length);
    return (repair(results));
    
}
