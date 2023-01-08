#include "run_length_encoding.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
    char *encoded_text = encode("");
    printf("%s, length = %ld\n", encoded_text, strlen(encoded_text));

    char *decoded_text = decode(encoded_text);
    printf("%s, length = %ld\n", decoded_text, strlen(decoded_text));
    
    free(encoded_text);
    free(decoded_text);
    
    return 0;
}
