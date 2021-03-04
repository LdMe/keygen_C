/*
** keygen.c
** File description:
** main keygen functions
*/
#include "keygen.h"
char *repair_classic(char **str)
{

    char *lista= "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (str[UPPER] == "f") { // upper false
        if (str[LOWER] == "t") { // lower true
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
    if ( str[LOWER] == "f") {
        if (str[UPPER] == "t") { // upper true
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
    if (str[NUMBER] == "f") {
        int upper = 0;
        int lower = 0;

        for (int i = 0; i < str_len(str[0]);i++) {
            if(is_upper(str[0][i]) == 1) {
                if (upper == 1) {
                    str[0][i] = lista[find(lista,str[0][i]) % 10];
                    break;
                }
                upper = 1;
            }
            else {
                if (lower == 1) {
                    str[0][i] = lista[find(lista,str[0][i]) % 10];
                    break;
                }
                lower = 1;
            }
        }
    }
    return str[0];
}
char *encrypt_classic(char *word, char *key)
{

    char *lista= "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
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
    for (int  i = 0; i < len1; i++) {
        int x = find(lista,str1[i]);
        int y = 0;
        y = find(lista, str2[i % len2]);
        int z= (mcd(y+1,x+1) * abs(x-y)) % len;
        results[0][i] =lista[z];
        if (is_upper(lista[z])) {
            results[1]="t";
        }
        if (is_lower(lista[z])) {
            results[2]="t";
        }
        if (is_num(lista[z])) {
            results[3]="t";
        }
    }
    
    return (repair_classic(results));
    
}
