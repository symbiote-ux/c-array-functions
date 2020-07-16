#include<stdlib.h>
#include<stdio.h>
#include "array_functions.h"

int find_greatest(int num1, int num2) {
  if(num1 > num2) return num1;
  return num2;
};

int reduce(List_ptr list, Reducer operation, int context) {
  Node_ptr p_walk = list->head;
  while(p_walk != NULL) {
    context = (*operation)(context,*(int *)p_walk->value);
    p_walk = p_walk->next;
  }
  return context;
};

Bool is_odd(void *value) {
  return *(int *)value % 2;
};

List_ptr filter(List_ptr list, Filterer operation) {
  Node_ptr p_walk = list->head;
  List_ptr result = create_list();
  while(p_walk != NULL) {
    Bool value = (*operation)(p_walk->value);
    if(value) insert_value(result,p_walk->value);
    p_walk = p_walk->next;
  }
  return result;
};

void *find_square(void *value) {
  int *square = malloc(sizeof(int));
  int num = *(int *)value;
  *square = num * num;
  return square;
};

List_ptr map(List_ptr list, Mapper operation) {
  Node_ptr p_walk = list->head;
  List_ptr result = create_list();
  while(p_walk != NULL) {
    void *value = (*operation)(p_walk->value);
    insert_value(result,value);
    p_walk = p_walk->next;
  }
  return result;
};
