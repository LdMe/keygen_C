/*
** keygen.c
** File description:
** main keygen functions
*/
#include "keygen_alphanumeric.h"

char *repair_alphanumeric(char **str)
{
    int charCount = 92;
    char firstChar = 33;
    char lista[charCount + 1];
    for (int i = 0; i < charCount; ++i)
    {
        lista [i] = firstChar + i;
    }
    lista [charCount] = '\0';
    if (str[UPPER] == "f") { // upper false
        if (str[LOWER] == "t") { // lower true
            for (int i = 0; i < str_len(str[0]); i++) {
                if (is_lower(str[0][i]) == 1) {
                    upper(&str[0][i]);
                    break;
                }
            }
        }
        else{
            str[0][0] = rand() % 25 + 65;
            
        }
    }
    if ( str[LOWER] == "f") {//lower false
        if (str[UPPER] == "t") { // lower true
            for (int i = 0; i < str_len(str[0]); i++) {
                if (is_num(str[0][i]) == 0) {
                    lower(&str[0][i]);
                    break;
                }
            }
        }
        else{
            str[0][1] = rand() % 25 + 97;
            
        }
    }
    if (str[NUMBER] == "f") {
        int upper = 0;
        int lower = 0;

        for (int i = 0; i < str_len(str[0]);i++) {
            if(is_upper(str[0][i]) == 1) {
                if (upper == 1) {
                    str[0][i] = str[0][i] % 10 + 48;
                    break;
                }
                upper = 1;
            }
            else {
                if (lower == 1) {
                    str[0][i] = str[0][i] % 10 + 48;
                    break;
                }
                lower = 1;
            }
        }
    }
    return str[0];
}
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
    srand(seed);
    int len =  str_len(lista);
    int len1 = str_len(word);
    int len2 = str_len(key);
    char *str1, *str2;
    char **results = malloc(sizeof(char*) * 4);
    for (int i = 1; i < 4; i++) {
        results[i] = malloc(sizeof(char) * 2);
        results[i] = "f";
    }
    if(len1 < len2) {
        int temp = len1;
        len1 = len2;
        len2 = temp;
        str1 =key;
        str2 = word;
    } else {
        str1  = word;
        str2 = key;
    }
    results[0] = malloc(sizeof(char) * (len1 + 1));
    int randX = rand() % 100;
    int randY = rand() % 100;
    for (int  i = 0; i < len1; i++) {
        int x = find(lista,str1[i]);
        int y = 0;
        y = find(lista, str2[i % len2]);
        int z= (mcd(y+randY,x+randX) * abs(x-y)) % len;
        results[0][i] =lista[z];
        if (is_upper(lista[z])) {
            results[UPPER]="t";
        }
        if (is_lower(lista[z])) {
            results[LOWER]="t";
        }
        if (is_num(lista[z])) {
            results[NUMBER]="t";
        }
    }
    return (repair_alphanumeric(results));
    
}
