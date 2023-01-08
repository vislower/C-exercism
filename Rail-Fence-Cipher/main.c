#include "rail_fence_cipher.h"
#include <stdio.h>


int main()
{
    char *encoded = encode("WEAREDISCOVEREDFLEEATONCE", 5);
    printf("%s\n", encoded);

    char *decoded = decode(encoded, 5);
    printf("%s\n", decoded);

    return 0;
}
