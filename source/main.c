#include "keygen_alphanumeric.h"
#include "keygen_alphanumeric_symbol.h"
#include "keygen.h" // classic
#include "keygen_numeric.h"
#include <string.h>
int main(int argc, char **argv)
{
    if(argc < 3) {
        return (1);
    }

    char *pass1 =argv[1];
    char *pass2 =argv[2];
    unsigned int seed = 0;
    char *result = "";
    if( argc > 3) {
    	int length = 0;
    	if ( argc > 4) {
    		length = atoi(argv[4]);
    	}
    	if ( argc > 5) {
    		seed = atoi(argv[5]);
    	}
    	if(strcmp(argv[3], "n") == 0) {
    		result = encrypt_numeric(pass1,pass2,seed, length); //numeric
    	}
    	if(strcmp(argv[3], "an") == 0) {
    		result = encrypt_alphanumeric(pass1,pass2,seed, length); //alphanumeric
    	}
    	if(strcmp(argv[3], "ans") == 0) {
    		result = encrypt_alphanumeric_symbol(pass1,pass2,seed, length); //alphanumeric and symbols
    	}
    }
    else {
    	result = encrypt_classic(pass1,pass2); //classic    	
    }
    printf("%s", result);
}
