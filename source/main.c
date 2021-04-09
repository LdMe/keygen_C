#include "keygen_alphanumeric.h"
#include "keygen_alphanumeric_symbol.h"
#include "keygen.h" // classic
#include "keygen_numeric.h"
#include <string.h>

#define WORD 1
#define KEY 2
#define TYPE 3
#define LENGTH 4
#define SEED 5
int main(int argc, char **argv)
{
    if(argc < 3) {
        return (1);
    }

    char *pass1 =argv[WORD];
    char *pass2 =argv[KEY];
    unsigned int seed = 0;
    char *result = "test";
    if( argc > 3) {
    	/*
        printf("word: %s\n",argv[WORD] );
    	printf("key: %s\n",argv[KEY] );
    	printf("type: %s\n",argv[TYPE] );
    	printf("length: %s\n",argv[LENGTH] );
    	printf("seed: %s\n",argv[SEED] );
        */
    	int length = 0;
    	if ( argc > LENGTH) {
    		length = atoi(argv[LENGTH]);
    	}
    	if ( argc > SEED) {
    		seed = atoi(argv[SEED]);
    	}
    	if(strcmp(argv[TYPE], "n") == 0) {
    		result = encrypt_numeric(pass1,pass2,seed, length); //numeric
    	}
    	if(strcmp(argv[TYPE], "an") == 0) {
    		result = encrypt_alphanumeric(pass1,pass2,seed, length); //alphanumeric
    	}
    	if(strcmp(argv[TYPE], "ans") == 0) {
    		result = encrypt_alphanumeric_symbol(pass1,pass2,seed, length); //alphanumeric and symbols
    	}
        if(strcmp(argv[TYPE], "c") == 0) {
            result = encrypt_classic(pass1,pass2); //classic  
        }
    }
    else {
    	result = encrypt_classic(pass1,pass2); //classic    	
    }
    printf("%s", result);
}
