#include "linked_list.h"
#include <stdio.h>


int main(void)
{
  struct list *list = NULL;
  list = list_create();

  list_unshift(list, 7);
  list_unshift(list, 8);
  list_unshift(list, 9);

  if (list) {
    list_destroy(list);
    list = NULL;
  }
  return 0;
}
