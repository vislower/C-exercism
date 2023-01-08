#include "crypto_square.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    char *nt = ciphertext("If man was meant to stay on the ground, god would have given us roots.");
    printf("%s\n", nt);
    
    free(nt);
    return 0;
}