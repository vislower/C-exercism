#include "matching_brackets.h"
#include <stdio.h>

int main(void)
{
    const char *input = "[({]})";

    printf("%s", is_paired(input) ? "true\n" : "false\n");

    return 0;
}
