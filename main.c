#include<stdlib.h>
#include<stdio.h>
#include "list.h"
#include "array_functions.h"

void save_numbers(List_ptr list) {
  int numbers[] = {5,7,3,4,3};
  for(int i = 0; i < 5; i++) {
    int *num = malloc(sizeof(int));
    *num = numbers[i];
    insert_value(list,num);
  }
};

int main(void){
  List_ptr list = create_list();
  save_numbers(list);

  printf("Numbers in the List: \n");
  Display_data operation = &display_num;
  display_list(list,operation);

  printf("Square of the numbers:\n");
  Mapper operation1 = &find_square;
  List_ptr result = map(list,operation1);
  display_list(result,operation);

  printf("Odd Numbers:\n");
  Filterer operation2 = &is_odd;
  List_ptr result2 = filter(list,operation2);
  display_list(result2,operation);

  Reducer operation3 = &find_greatest;
  printf("Greatest Num in the list: %d\n",reduce(list,operation3,0));
  return 0;
};