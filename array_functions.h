#ifndef _ARRAY_FUNCTIONS_H_
#define _ARRAY_FUNCTIONS_H_

#include "list.h"

typedef enum {
  False,
  True
} Bool;

typedef void *(*Mapper)(void *);
typedef Bool (*Filterer)(void *);
typedef int (*Reducer)(int,int);


int find_greatest(int,int);
int reduce(List_ptr, Reducer, int); 

Bool is_odd(void *);
List_ptr filter(List_ptr, Filterer);

List_ptr map(List_ptr, Mapper);
void *find_square(void *);

#endif