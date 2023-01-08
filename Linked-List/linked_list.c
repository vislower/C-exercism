#include "linked_list.h"
#include <stdlib.h>


struct list *list_create(void)
{
    struct list *list = malloc(sizeof(struct list));
    if (list == NULL)
        exit(EXIT_FAILURE);
    list->first = NULL;
    list->last = NULL;
    return list;
}

size_t list_count(const struct list *list)
{
    size_t count = 0;
    struct list_node *tmp = list->first;
    if (tmp == NULL)
        return count;
    
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

void list_push(struct list *list, ll_data_t item_data)
{
    struct list_node *node = malloc(sizeof(struct list_node));
    if (node == NULL)
       exit(EXIT_FAILURE);
    
    node->data = item_data;
    node->next = NULL;
    node->prev = list->last;

    /* if list is empty */
    if (list->first == NULL && list->last == NULL)
    {
        list->first = node;
        list->last = node;
    }
    else
    {
        list->last->next = node;
        list->last = node;
    }
}

ll_data_t list_pop(struct list *list)
{
    struct list_node *tmp = list->last;
    ll_data_t item_data = list->last->data;

    /* if list only has one element */
    if (list->first == list->last)
    {
        list->first = NULL;
        list->last = NULL;
    }
    else
    {
        list->last->prev->next = NULL;
        list->last = list->last->prev;
    }
    free(tmp);
    return item_data;
}

void list_unshift(struct list *list, ll_data_t item_data)
{
    struct list_node *node = malloc(sizeof(struct list_node));
    if (node == NULL)
        exit(EXIT_FAILURE);
    
    node->data = item_data;
    node->prev = NULL;
    node->next = list->first;

    /* if list is empty */
    if (list->first == NULL && list->last == NULL)
    {
        list->first = node;
        list->last = node;
    }
    else
    {
        list->first->prev = node;
        list->first = node;
    }
}

ll_data_t list_shift(struct list *list)
{
    struct list_node *tmp = list->first;
    ll_data_t item_data = list->first->data;

    /* if list only has one element */
    if (list->first == list->last)
    {
        list->first = NULL;
        list->last = NULL;
    }
    else
    {
        list->first->next->prev = NULL;
        list->first = list->first->next;
    }
    free(tmp);
    return item_data;
}

void list_delete(struct list *list, ll_data_t data)
{
    struct list_node *tmp = list->first;
    while (tmp != NULL)
    {
        if (tmp->data == data)
        {
            if (tmp == list->first)
            {
                list_shift(list);
                break;
            }
            if (tmp == list->last)
            {
                list_pop(list);
                break;
            }
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            free(tmp);
            break;
        }
        tmp = tmp->next;
    }
}

void list_destroy(struct list *list)
{
    struct list_node *tmp = list->first;
    while (tmp != NULL)
    {
        struct list_node *tmp_prev = tmp;
        tmp = tmp->next;
        free(tmp_prev);
    }
    free(list);
}