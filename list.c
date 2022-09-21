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
  node_t *new_node;
  new_node = (node_t *) malloc(sizeof(node_t));
  new_node -> value  = value;

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
}


//Add to the front of list
void list_add_to_front(list_t *l, elem value) {
  node_t *new_node;
  new_node = (node_t *) malloc(sizeof(node_t));
  new_node -> value  = value;

  if(current->head==NULL){
		current = new_node;
		return;
	}
	else{
		new_node -> next = current->head; 
		current->head = new_node; 
    return;
	}
}

//Add a value at index
void list_add_at_index(list_t *l, elem value, int index) {
  node_t *new_node;
  new_node = (node_t *) malloc(sizeof(node_t));
  new_node->value = value;

  node_t *current = l->head;
  node_t *prev = NULL;

  if(l->head==NULL) {
    if (index != 0){
      return;
    }
		else{
      l->head = new_node;
    }
  }
  if ((l->head != NULL) && (index == 0)) {
    list_add_to_front(l, value);
    return;
  }
	while (pos < index) {
    prev = curr;
    curr = curr->next;
    if (curr == NULL) {
      break;
    }
    pos++;
  }
  new_node->next = curr;
  prev->next = new_node;
}

//remove element from back of list
elem list_remove_from_back(list_t *l) {
  node_t current = l -> head;
  node_t prev = NULL;  

  if(current==NULL){
		printf("Linked List is empty | Nothing to delete \n");
		return;
	}
	else if(current->next==NULL) {
		current = current->next;
		free(current);
	}
	else{
    while (current ->next != NULL) {
    prev = current;
    current = current->next;
    }
    prev -> Next = NULL;
    free(current);
  }
		
}


//remove element from the front of linked list
elem list_remove_from_front(list_t *l) {
  if(current==NULL) 
	{
		printf("Linked List is empty | Nothing to delete \n");
		return -1;
	}
	else{
    node_t current = l -> head;
    head = head ->next;
    return current -> value;
;
  }
}

//Remove at certain index position
elem list_remove_at_index(list_t *l, int index) { 
  node_t current = list_t -> head;                                                                             
	if(current==NULL){
		printf("Linked List is empty \n"); 
		return;
	  }
	else if(index == 0) {
		current = current;
		current=current->next; 
		free(current); }
	else{
		list_t prev;
		for(int i=0;i<index;i++){
			prev = current;
			current = current->next;
		}
		prev->next = current->next; 
	}
 }

//Check if an element is present in  list
bool list_is_in(list_t *l, elem value) { 
  node_t *current = l -> head;
  int index = 0;
  while (current != NULL){
    if (current->value == value){
      return true;
      }
    else{
      current = current->next;
      index++;
    }
  }
  return false;
 }

//get element at certain position
elem list_get_elem_at(list_t *l, int index) { 
  node_t *curr = l->head;
  int list_len = list_length(l);
  int step = 0;

  if ((index > list_len) || (index < 0)) {
    return -1; 
   }

  while ((curr != NULL) && (step <= index)) {
    curr = curr->next;
    step++;
  }
  return curr->value; 
return -1;
}

//get index of element in linked list
int list_get_index_of(list_t *l, elem value) { 
  node_t *curr = l->head;
  int index = 0;

  if (curr == NULL) {
    return -1; 
  }
  while (curr != NULL) {
    if (curr->value != value) {
      index++;
      curr = curr->next;
    } 
    else {
      return index;
    }
  }
  return -1;
}

