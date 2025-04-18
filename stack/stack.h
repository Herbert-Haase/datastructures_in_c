// stack.h
#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define SIZE 32

typedef struct Stack {
  int arr[SIZE];
  int size;
  int max_size;
  void (*push)(struct Stack*, int);
  int (*pop)(struct Stack*);
  int (*peek)(struct Stack*);
  bool (*isempty)(struct Stack*);
  bool (*isfull)(struct Stack*);
  void (*clear)(struct Stack*);
  void (*print_stack)(struct Stack*);
} Stack;

Stack* init_stack(void);

#endif

