#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "list.c"
//Author : Tolulope Akinlabi & Yoofi Williams

int main() {
  elem value;

  printf("Tests for linked list implementation\n");
  list_t *test_list;
  
  test_list = (list_t*)list_alloc();
  list_print(test_list);

  list_add_to_front(test_list, 8);
  list_add_to_front(test_list, 9);
  list_add_to_front(test_list, 10);

  list_add_to_back(test_list, 11);
  list_add_to_back(test_list, 12);

  list_print(test_list);
  printf("List length : %d\n", list_length(test_list));

  list_remove_from_back(test_list);
  printf("This is what i have after removing from back \n")
  list_print(test_list);

  list_remove_from_front(test_list);
  printf("This is what i have after removing from front \n")
  list_print(test_list);

  printf("Length of list: %d\n", list_length(test_list));

 
  list_add_at_index (test_list, 10, 2);
  printf("At index: \n")
  list_print(test_list);

  list_add_at_index (test_list, 12, 4);
  printf("At index: \n")
  list_print(test_list);

  printf("Testing getting element at index 0 : %d\n", list_get_elem_at(test_list, 0));
  printf("Testing getting element at index 1 : %d\n", list_get_elem_at(test_list, 1));

  printf("Testing getting element at index 0 : %d\n", list_get_index_of(test_list, 3));
  printf("Testing getting element at index 1 : %d\n", list_get_index_of(test_list, 4));

  list_remove_from_back(test_list);

  elem list_remove_at_index(list_t *l, int index);
  value = list_remove_at_index(test_list,1);
  value = list_remove_at_index(test_list,2);
  printf("After removing at index: \n");
  list_print(test_list);
}