#include "binary_search_tree.h"
#include <stdlib.h>

void get_nodes(node_t *tree, int *data, int *pos);

size_t tree_length = 0;

node_t *build_tree(int *tree_data, size_t tree_data_len)
{
    tree_length = tree_data_len;
    node_t *tree = malloc(sizeof(node_t));
    tree->data = tree_data[0];
    tree->left = NULL;
    tree->right = NULL;

    /*
    create a tmp pointer to move inside the tree
    and initialize at the root of the tree
    */
    node_t *tmp = tree;
    for (size_t i = 1; i < tree_data_len; i++)
    {
        tmp = tree;
        while (tmp != NULL)
        {
            if (tree_data[i] <= tmp->data)
            {
                if (tmp->left == NULL)
                {
                    node_t *node = malloc(sizeof(node_t));
                    node->data = tree_data[i];
                    node->left = NULL;
                    node->right = NULL;
                    tmp->left = node;
                    break;
                }
                else
                {
                    tmp = tmp->left;
                }
            }
            else
            {
                if (tmp->right == NULL)
                {
                    node_t *node = malloc(sizeof(node_t));
                    node->data = tree_data[i];
                    node->left = NULL;
                    node->right = NULL;
                    tmp->right = node;
                    break;
                }
                else
                {
                    tmp = tmp->right;
                }
            }
        }
    }
    return tree;
}

void free_tree(node_t *tree)
{
    if (tree)
    {
        free_tree(tree->left);
        free_tree(tree->right);
        free(tree);
    }
}

void get_nodes(node_t *tree, int *data, int *pos)
{
    if (!tree)
    {
        return;
    }
    get_nodes(tree->left, data, pos);
    data[(*pos)++] = tree->data;
    get_nodes(tree->right, data, pos);
}

int *sorted_data(node_t *tree)
{
    if (tree == NULL)
        return NULL;
    int *data = malloc(tree_length * sizeof(int));
    int pos = 0;
    get_nodes(tree, data, &pos);
    return data;
}