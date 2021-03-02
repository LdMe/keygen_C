/*
** keygen.c
** File description:
** main keygen functions
*/
#include "keygen_alphanumeric.h"
char *repair_alphanumeric(char **str)
{

    char *lista= "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (str[1] == "f") { // mayus false
        if (str[2] == "t") { // minus true
            for (int i = 0; i < str_len(str[0]); i++) {
                if (is_num(str[0][i]) == 0) {
                    upper(&str[0][i]);
                    break;
                }
            }
        }
        else{
            str[0][0] = lista[find(lista, lista[find(lista, str[0][0]) + 26])];
            
        }
    }
    if ( str[2] == "f") {
        if (str[1] == "t") { // minus true
            for (int i = 0; i < str_len(str[0]); i++) {
                if (is_num(str[0][i]) == 0) {
                    lower(&str[0][i]);
                    break;
                }
            }
        }
        else{
            str[0][0] = lista[find(lista, lista[find(lista, str[0][0]) + 10])];
            
        }
    }
    if (str[3] == "f") {
        int may = 0;
        int min = 0;

        for (int i = 0; i < str_len(str[0]);i++) {
            if(is_mayus(str[0][i]) == 1) {
                if (may == 1) {
                    str[0][i] = lista[find(lista,str[0][i]) % 10];
                    break;
                }
                may = 1;
            }
            else {
                if (min == 1) {
                    str[0][i] = lista[find(lista,str[0][i]) % 10];
                    break;
                }
                min = 1;
            }
        }
    }
    return str[0];
}
char *encrypt_alphanumeric(char *word, char *key,unsigned int seed)
{

    char *lista= "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
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
        if (is_mayus(lista[z])) {
            results[1]="t";
        }
        if (is_minus(lista[z])) {
            results[2]="t";
        }
        if (is_num(lista[z])) {
            results[3]="t";
        }
    }
    
    return (repair_alphanumeric(results));
    
}
