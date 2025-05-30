// stack.c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#define SIZE 32

struct stack_type {
  int arr[SIZE];
  int size;
  int max_size;
};

static void stack_overflow(void);
static void stack_underflow(void);

void print_stack(Stack stack) {
  printf("Stack (size=%d): ", stack->size);
  for (int i = 0; i < stack->size; i++) {
    printf("%d ", stack->arr[i]);
  }
  printf("\n");
}

void stack_overflow(void) {
  fprintf(stderr, "stack overflow: %s at %d\n", __FILE__, __LINE__);
  exit(1);
}

void stack_underflow(void) {
  fprintf(stderr, "stack underflow: %s at %d\n", __FILE__, __LINE__);
  exit(1);
}

Stack init_stack(void) {
  Stack stack = malloc(sizeof(struct stack_type));
  if (!stack) {
    fprintf(stderr, "out of memory: %s at %d\n", __FILE__, __LINE__);
    exit(1);
  }
  stack->size = 0;
  stack->max_size = SIZE;
  return stack;
}

int size(Stack stack) { return stack->size;}

bool isempty(Stack stack) { return stack->size == 0; }

bool isfull(Stack stack) { return stack->size == stack->max_size; }

void push(Stack stack, int value) {
  if (isfull(stack))
    stack_overflow();
  stack->arr[(stack->size)++] = value;
}

int pop(Stack stack) {
  if (isempty(stack))
    stack_underflow();
  return stack->arr[--(stack->size)];
}

int peek(Stack stack) {
  if (stack->size > 0) {
    return stack->arr[stack->size - 1];
  }
  return 0;
}

void clear(Stack stack) { stack->size = 0; }
