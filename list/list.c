// list/list.c
// 
// Implementation for linked list.
//
// Author : Tolulope Akinlabi, Yoofi Williams

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

//Allocate memory to list
list_t *list_alloc() { 
  list_t *list = (list_t *)malloc(sizeof(list_t));
  list -> head = NULL;
  return list;
 }

//node free
void node_free(node_t *n) {
  free(n);
}

//Allocate memory to node
node_t *node_alloc(elem value){
  node_t *node = (node_t *)malloc(sizeof(node_t));
  node -> value = value;
  return node;
}

//free the list
void list_free(list_t *l) {
  node_t *prev, *current;
  prev = l->head;
  current = prev->next;
  if (l->head == NULL) {
    return;
  }
  else if (current == NULL) {
    node_free(prev);
  }
  while (prev != current) {
    node_free(prev);
    prev = current;
    current = current->next;
  }
}


//Print the entire list
void list_print(list_t *l) {
  node_t *current = l -> head;
  if(current==NULL)
	{
		printf("Linked List is Empty\n");
		return;
	}
  printf("LinkedList: ");
  while (current != NULL){
    printf("%d\n", current -> value);
    current = current -> next;
  }
  printf("\n");
}

//Print the length of list
int list_length(list_t *l) {
  int counter = 0;
  node_t *current = l -> head;
  while (current != NULL){
    counter++;
    current = current -> next;
  }
  return counter;
 }

//Add to the back of linked list
void list_add_to_back(list_t *l, elem value) {
  node_t *current = l->head;
  node_t *new_node;
  new_node = node_alloc(value);

  if (current == NULL){
      current = new_node;
      return;
    }
  else{
    while (current->next != NULL){
      current = current->next;
    }
    current->next = new_node;
    current->next->next = NULL;
  }
  return;
}


//Add to the front of list
void list_add_to_front(list_t *l, elem value) {
  node_t *new_node;
  new_node = node_alloc(value);

  if(l->head==NULL){
    printf("Nothing here to see!");
		return;
	}
	else{
		new_node -> next = l->head; 
		l->head = new_node; 
    return;
	}
}

//Add a value at index
void list_add_at_index(list_t *l, elem value, int index) {
  node_t *new_node;
  new_node = node_alloc(value);

  node_t *current = l->head;
  node_t *prev = NULL;
  int pos;
  int len = list_length(l);

  if(l->head==NULL) {
    return;
  }
  if ((l->head != NULL) && (index == 0)) {
    list_add_to_front(l, value);
    return;
  }
	while (pos < index) {
    prev = current;
    current = current->next;
    if (current == NULL) {
      break;
    }
    pos++;
  }
  new_node->next = current;
  prev->next = new_node;
  return;
}

//remove element from back of list
elem list_remove_from_back(list_t *l) {
  node_t *prev = NULL;  
  node_t *current = l -> head;
  int vab;

  if(current==NULL){
		printf("Linked List is empty | Nothing to delete \n");
		return NULL;
	}
	else if(current->next==NULL) {
    vab = current -> value;
    node_free(current);
    return vab;
	}
	else{
    while (current -> next -> next != NULL) {
      current = current->next;
    }
    vab = current -> next -> value;
    node_free(current->next);
    current->next = NULL;
    return vab;
  }
		
}


//remove element from the front of linked list
elem list_remove_from_front(list_t *l) {
  int vab;
  node_t *current = l -> head;
  node_t *assoc;

  if (current == NULL){
    return NULL;
  }
  assoc = current -> next;
  vab = current -> value;
  node_free(current);

  current = NULL;
  current = assoc;
  return assoc;
}

//Remove at certain index position
elem list_remove_at_index(list_t *l, int index) { 
  node_t *current = l -> head;
  int newvab;

	if(current == NULL || index < 0 ){
		return NULL;
	  }
	else{
    if (index == 0){
      list_remove_from_front(l);
    }

    int i = 0;
		while (i<index){
			current = current->next;
		}
		newvab = current->next->value; 
    current -> = current -> next -> next;
    return newvab;
	}
 }

//Check if an element is present in  list
bool list_is_in(list_t *l, elem value) { 
  node_t *current = l -> head;
  while (current != NULL){
    if (current->value == value){
      return true;
      }
    else{
      current = current->next;
    }
  }
  return false;
 }

//get element at certain position
elem list_get_elem_at(list_t *l, int index) { 
  node_t *current = l->head;
  int list_len = list_length(l);
  int step = 0;

  if ((index > list_len) || (index < 0)) {
    return NULL; 
   }

  while ((current != NULL) && (step <= index)) {
    if (step == index){
      return current -> value;
    }
    step++;
    current = current->next;
    
  }
  return NULL;
}

//get index of element in linked list
int list_get_index_of(list_t *l, elem value) { 
  node_t *current = l->head;
  int index = 0;

  if (current == NULL) {
    return NULL; 
  }
  while (current != NULL) {
    if (current->value != value) {
      index++;
      current = current->next;
    } 
    else {
      return index;
    }
  }
  return NULL;
}
