// list/list.c
// 
// Implementation for linked list.
//
// Tolulope Akinlabi

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

//Allocate memory to node
node_t *node_alloc(elem value){
  node_t *node = (node_t *)malloc(sizeof(node_t));
  return node;
}

//free the list
void list_free(list_t *l) {
  node_t current = list_t -> head;
  while (current != NULL){
    current = current->next;
    free(current);
    }
}


//Print the entire list
void list_print(list_t *l) {
  node_t current = list_t -> head;
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

}

//Print the length of list
int list_length(list_t *l) {
  int counter = 0;
  node_t current = list_t -> head;
  while (current != NULL){
    counter++;
    current = current -> next;
  }
  return counter;
 }

//Add to the back of linked list
void list_add_to_back(list_t *l, elem value) {
  node_t *new_node;
  node_t current = list_t -> head;
  new_node -> value  = value;
  new_node -> next = NULL;
  if (current == NULL){
      current = new_node;
      return;
    }
  else{
    while (current->next != NULL)
      current = current->next;
      current->next = new_node;
  }
}


//Add to the front of list
void list_add_to_front(list_t *l, elem value) {
  node_t new_node;
  node_t current = list_t -> head;
  new_node -> value  = value;
  new_node  -> next = NULL;
  if(current==NULL){
		current = new_node;
		return;
	}
	else{
		new_node -> next = current; 
		current = new_node; 
	}
}

//Add a value at index
void list_add_at_index(list_t *l, elem value, int index) {
  node_t new_node -> value;
  new_node -> next = NULL;
  node_t current = head;
  node_t prev;

  if(current==NULL) {
		current = new_node;
	  return;
	}
	else{
		for(int i=0;i<index;i++)
		{
			prev = current;
			current = current->next;
		}
		new_node->current = ptr;
		prev->next = new_node;
	}
  }
}

//remove element from back of list
elem list_remove_from_back(list_t *l) {
  node_t current = list_t -> head;
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
		return;
	}
	else{
    node_t current = list_t -> head;
    current = current ->next;
    free(current);
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
  node_t current = list_t -> head;
  int index = 0;
  while (current != NULL){
    if (current->data == value){
      return index;
      }
      current = current->next;
      index++;
    }
  return -1;
 }

//get element at certain position
elem list_get_elem_at(list_t *l, int index) { return -1; }

//get index of element in linked list
int list_get_index_of(list_t *l, elem value) { return -1; }

