#include "keygen_alphanumeric.h"
#include "keygen_alphanumeric_symbol.h"
#include "keygen.h" // classic
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
    	if(argv[3] == "an") {
    		result = encrypt_alphanumeric(pass1,pass2,seed); //with seed
    	}
    	if(argv[3] == "ans") {
    		result = encrypt_alphanumeric_symbol(pass1,pass2,seed); //with seed and symbols
    	}
    }
    else {
    	result = encrypt(pass1,pass2); //classic    	
    }
    printf("%s", result);
}
