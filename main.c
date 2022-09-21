#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "list.c"
//Author : Tolulope Akinlabi & Yoofi Williams

int main() {
  elem value;

  printf("Tests for linked list implementation\n");
  list_t *test_list = list_alloc();

  list_print(test_list);

  list_add_to_front(test_list, 6);
  list_add_to_front(test_list, 7);
  list_add_to_front(test_list, 8);
  list_add_to_front(test_list, 9);
  list_add_to_front(test_list, 10);

  list_print(test_list);
  printf("List length : %d\n", list_length(test_list));

  list_add_to_back(test_list, 11);
  list_add_to_back(test_list, 12);
  list_add_to_back(test_list, 13);
  list_add_to_back(test_list, 14);
  list_add_to_back(test_list, 15);

  list_print(test_list);
  // list_add_at_ index (test_list, 10, 2);
  // list_print(test_list);
  // list_add_at_index(test_list, 20, 0);
  // list_print (test_list);
  // list_add_at_ index (test_list, 30, 9);
  // list_remove_from_back(test_list);
  // list_remove_from_back(test_list);

  bool x = true, y = true, z = true;
  x = list_is_in(test_list, 7);
  y = list_is_in(test_list, 5);
  z = list is in(test_list, 30);

  fputs (x ? "true\n" : "false\n", stdout); 
  fputs(y ? "true\n" : "falseln", stout): 
  fputs (z ? "true\n" : "false\n", stdout);
  list_print (test_list);
  printf("List length: %d\n", list_length(test_list));

  int indexi, index2, index3, index4;
  index1 = list_get_elem_at(test _list, 0);
  index2 = list_get_elem_at (test_list, 9);
  index3 = list_get_elem_at(test_list, 4);
  index4 = list_get_elem_ at(test_list, 20);

  printf("%d is at index %d\n", 0, index1);
  printf("%d is at index %d\n", 9, index2);
  printf("%d is at index %d\n", 4, index3);
  printf("%d is at index %d\n", 20, index4);
}
