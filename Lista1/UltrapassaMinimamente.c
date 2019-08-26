#include <stdio.h> 
#include <stdlib.h> 

typedef struct {
    int size;
    int capacity;
    int *data;
} Vector;

void init(Vector *vector){
    vector->size = 0;
    vector->capacity = 2;
    vector->data = malloc(sizeof(int) * vector->capacity);
}

void append(Vector *vector, int value){

    if(vector->size >= vector->capacity){
        vector->capacity *= 2;
        vector->data = realloc(vector->data, sizeof(int) * vector->capacity);
    }

    vector->data[vector->size++] = value;
}

int get(Vector *vector, int index){

    if(index > vector->capacity || index < 0){
        exit(1);
    }

    return vector->data[index];
}

int sizeVector(Vector *vector){
    return vector->size;
}

struct Stack { 
    int top; 
    unsigned capacity; 
    int* array;
    int size;
}; 

struct Stack* createStack(unsigned capacity) 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    stack->size = 0;
    return stack; 
} 

void push(struct Stack* stack, int item) 
{ 
    stack->array[++stack->top] = item;
    stack->size++;
} 
  
int pop(struct Stack* stack) 
{ 
    return stack->array[stack->top--];
    stack->size--;
}

int sizeStack(struct Stack* stack){
  return stack->size;
}
   
int main() 
{ 
  Vector v;
  init(&v);
  int entry, sum = 0, limit;
  scanf("%d", &entry);
  append(&v, entry);

  while(entry != 0){
    scanf("%d", &entry);
    if(entry != 0) {
      append(&v, entry);
    }
  }

  scanf("%d", &limit);

  struct Stack* stack = createStack(sizeVector(&v));

  for(int i = 0; i < sizeVector(&v); i++){

    sum += get(&v,i);

    if(sum > limit){
      push(stack,get(&v,i));
      sum = 0;
    }
  }
  int size = sizeStack(stack);

  for(int i = 0; i < size; i++){
    printf("%d\n", pop(stack));
  }

    return 0; 
} 
