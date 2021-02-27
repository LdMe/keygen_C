#include "keygen_alphanumeric.h"

int main(int argc, char **argv)
{
    if(argc < 3) {
        return (1);
    }
    char *pass1 =argv[1];
    char *pass2 =argv[2];
    unsigned int seed = 0;
    char *result = encrypt(pass1,pass2,seed);
    printf("%s", result);
}
