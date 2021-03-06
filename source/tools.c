/*
** keygen.c
** File description:
** main keygen functions
*/
#include "tools.h"

int str_len(char *str)
{
    int counter = 0;
    while (*str !='\0' ) {
        str++;
        counter++;
    }
    return (counter);
}
int is_lower(char c)
{
    if (c > 96 && c < 123) {
        return (1);
    }
    return (0);
            
}
int is_upper(char c)
{
    if (c > 64 && c < 91) {
        return (1);
    }
    return (0);
            
}
int is_num(char c)
{
    if ( c > 47 && c < 58) {
        return (1);
    }
    return (0);
            
}
int is_symbol(char c)
{
    if ( is_upper(c) || is_lower(c) || is_num(c)) {
        return (0);
    }
    return (1);
            
}
void lower(char *a)
{
    *a = *a + 32;
}
void upper(char *a)
{
    *a = *a - 32;
}
int abs(int n)
{
    if(n < 0) {
        return -n;
    }
    return n;
}
int find(char *lista,char word){
    int len = str_len(lista);
	for (int i =0; i < len; i++){
		if(lista[i] == word){
			return i;
		}
	}
	
	
	return -1;
}
int mcd(int x, int y)
{	
	int max,min;
	if (x > y) {
		max= x;
        // min should be y, but it changes keys I'm currently using
		min= x;
	}
	else if (y > x) {
		max= y;
		min=x;
	}
	else {
		return x;
	}
	
	for (int i = min; i > 0; i--) {
		if (max % i==0 && min% i == 0) {
			return i;
		}
	}
	return -1;
}
int sum(char *str)
{
	int result = 0;
	int pos = 0;
	while( str[pos] != '\0') {
		result += str[pos];
		pos++;
	}
	printf("word:%s sum: %i\n",str,result);
	return result;
}
int is_type(char c, unsigned int type) {
	switch (type){
		case UPPER:
			return is_upper(c);
		case LOWER:
			return is_lower(c);
		case NUMBER:
			return is_num(c);
		case SYMBOL:
			return is_symbol(c);
		default:
			return 0;
	}
}
char change_to_type(char c, unsigned int type) {
	switch (type){
		case UPPER:
			return change_to_upper(c);
		case LOWER:
			return change_to_lower(c);
		case NUMBER:
			return change_to_number(c);
		case SYMBOL:
			return change_to_symbol(c);
		default:
			return 48;
	}
}
char change_to_upper(char c) {
	return 65 + c % 26;
}
char change_to_lower(char c) {
	return 97 + c % 26;
}
char change_to_number(char c) {
	return 48 + c % 10;
}
char change_to_symbol(char c) {
	int option = rand() % 100;
    char operand = 33;
    if (option < 25) {
    	operand  = c % 15 + 33;
    }
    else if (option < 50) {
    	operand  = c % 7 + 58;
    }
    else if (option < 75) {
    	operand  = c % 6 + 91;
    }
    else {
    	operand  = c % 4 + 123;
    }
    return operand;
}
char *repair(char **str) {
	int *repetitions = malloc(sizeof(int) * ARRAY_SIZE);
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		repetitions[i] = 0;
	}
	int len = str_len(str[0]);
	for (int i = 0; i < len; ++i)
	{
		if (is_upper(str[0][i])) {
			repetitions[UPPER]++;
		}
		if (is_lower(str[0][i])) {
			repetitions[LOWER]++;
		}
		if (is_num(str[0][i])) {
			repetitions[NUMBER]++;
		}
		if (is_symbol(str[0][i])) {
			repetitions[SYMBOL]++;
		}
	}
	for (int i = 1; i < ARRAY_SIZE; i++)
	{
		if(strcmp(str[i], "f") == 0) {
			unsigned int maxPosition = 0;
			int max = 0;
			for (int j = 1; j < ARRAY_SIZE; j++) {
				if(repetitions[j] > max) {
					max  = repetitions[j];
					maxPosition = j;
				}
			}
			for (int k = 0; k < len; k++) {
				if (is_type(str[0][k],maxPosition)) {
					str[0][k] = change_to_type(str[0][k], (unsigned int)i);
					repetitions[maxPosition]--;
					break;
				}
			}

		}
	}
	return str[0];
}
char **encrypt(char *word, char *key,char *lista,unsigned int seed)
{
    srand(seed);
    int len =  str_len(lista);
    int len1 = str_len(word);
    int len2 = str_len(key);
    char *str1, *str2;
    char **results = malloc(sizeof(char*) * ARRAY_SIZE);
    for (int i = 1; i < ARRAY_SIZE; i++) {
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
        int x = str1[i];
        int y = 0;
        y = str2[i % len2];
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
        if (is_symbol(lista[z])) {
            results[SYMBOL]="t";
        }
    }
    return results;
}
char **encrypt_fixed_length(char *word, char *key,char *lista,unsigned int seed,int resultLen)
{
    srand(seed);
    int listaLen =  str_len(lista);
    int wordLen = str_len(word);
    int keyLen = str_len(key);
    char **results = malloc(sizeof(char*) * ARRAY_SIZE);
    for (int i = 1; i < ARRAY_SIZE; i++) {
        results[i] = malloc(sizeof(char) * 2);
        results[i] = "f";
    }
    results[0] = malloc(sizeof(char) * (resultLen + 1));
    int randX = rand() % 100;
    int randY = rand() % 100;
    printf("randX: %i, randY: %i\n", randX, randY);
    int sumX = sum(word);
    int sumY = sum(key);
    for (int  i = 0; i < resultLen; i++) {
        int x = word[i   % wordLen] + sumX +randX;
        int y = key[i  % keyLen] + sumY +randY;
        int z = ( mcd(y,x) * abs(x-y)) % listaLen;
        printf("x: %i y: %i z: %i mcd: %i\n",x,y,z , mcd(y+randY,x+randX));
        results[0][i] = lista[z];
        if (is_upper(lista[z])) {
            results[UPPER] = "t";
        }
        if (is_lower(lista[z])) {
            results[LOWER] = "t";
        }
        if (is_num(lista[z])) {
            results[NUMBER] = "t";
        }
        if (is_symbol(lista[z])) {
            results[SYMBOL] = "t";
        }
    }
    results[0][resultLen] ='\0';
    return results;
}