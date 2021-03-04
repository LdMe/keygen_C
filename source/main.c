#include "keygen_alphanumeric.h"
#include "keygen.h" // classic
int main(int argc, char **argv)
{
    if(argc < 3) {
        return (1);
    }

    char *pass1 =argv[1];
    char *pass2 =argv[2];
    unsigned int seed = 0;
    //char *result = encrypt_alphanumeric(pass1,pass2,seed); //with seed
    char *result = encrypt(pass1,pass2); //classic
    printf("%s", result);
}
