#ifndef _LIST_H_
#define _LIST_H_

typedef struct node {
  void *value;
  struct node *next;
} Node;

typedef Node *Node_ptr;

typedef struct {
  Node_ptr head;
  Node_ptr last;
  int count;
} List;

typedef List *List_ptr;
typedef void (*Display_data)(void *);

List_ptr create_list();
void insert_value(List_ptr,void *);
Node_ptr create_node(void *);
void display_num(void *);
void display_list(List_ptr, Display_data);
#endif