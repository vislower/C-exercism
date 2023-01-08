#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int tree_data[] = {4, 2, 6, 3, 1, 5, 7};
    node_t *tree = build_tree(tree_data, 7);
    
    int *sorted = sorted_data(tree);
    printf("sorted data : ");
    for (size_t i = 0; i < 7; i++)
    {
        printf("%d ", sorted[i]);
    }
    printf("\n");
    free(sorted);
    free_tree(tree);
    
    return 0;
}
