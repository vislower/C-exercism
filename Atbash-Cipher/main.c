#include "atbash_cipher.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *encoded_text = atbash_encode("The quick brown fox jumps over the lazy dog.");
    printf("%s\n", encoded_text);

    char *decoded_text = atbash_decode("test");
    printf("%s\n", decoded_text);
    
    free(encoded_text);
    free(decoded_text);
    return 0;
}
