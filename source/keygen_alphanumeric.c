/*
** keygen.c
** File description:
** main keygen functions
*/
#include "keygen_alphanumeric.h"

char *encrypt_alphanumeric(char *word, char *key,unsigned int seed)
{
    int charCount = 97;
    char firstChar = 33;
    int count = 1;
    for (int i = firstChar; i <= charCount +firstChar; ++i)
    {

        if(is_num(i) || is_upper(i) || is_lower(i) )
        {
            count++;
        }
    }

    char *lista = malloc(sizeof(char) * (count + 1));
    int position = 0;
    for (int i = 0; i <= charCount ; i++)
    {
        char actualChar = i + firstChar;
        if(is_num(actualChar) || is_upper(actualChar) || is_lower(actualChar) )
        {
            lista[position] = actualChar;
            position++;
        }
    }
    lista[count] = '\0';
    char **results = encrypt(word, key, lista, seed);
    results[SYMBOL] = "t";
    return (repair(results));
    
}
