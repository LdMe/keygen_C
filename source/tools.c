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
int is_minus(char c)
{
    if (c > 96 && c < 123) {
        return (1);
    }
    return (0);
            
}
int is_mayus(char c)
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