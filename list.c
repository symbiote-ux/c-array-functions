#include<stdlib.h>
#include<stdio.h>
#include "list.h"

void display_num(void *num) {
  printf("%d\n",*(int *)num);
};

void display_list(List_ptr list, Display_data displayer) {
  Node_ptr p_walk = list->head;
  while(p_walk != NULL) {
    (*displayer)(p_walk->value);
    p_walk = p_walk->next;
  }
};

Node_ptr create_node(void *value) {
  Node_ptr node = malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  return node;
};

void insert_value(List_ptr list, void *value) {
  Node_ptr new_node = create_node(value);
  if(list->head == NULL) list->head = new_node;
  else list->last->next = new_node;
  list->last = new_node;
  list->count++;
};

List_ptr create_list() {
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
};