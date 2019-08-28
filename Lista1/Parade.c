#include <stdio.h>
#include <stdlib.h>

struct Stack { 
    int top; 
    unsigned capacity; 
    int * array;
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
    stack->size--;
    return stack->array[stack->top--];
    
}

int sizeStack(struct Stack* stack){
  return stack->size;
}

int stackTop(struct Stack* stack){
  return stack->array[stack->top];
}

int organiza(int * trucks, struct Stack* rua, int n){
  int i = 0, target = 1;
   while(i < n || sizeStack(rua) != 0) {
    if(trucks[i] == target && i < n) {
      i++;
      target++;
    } else if(stackTop(rua) == target) {
        pop(rua);
        target++;
      } else if(i < n) {
        push(rua, trucks[i]);
        i++;
        } else if(sizeStack(rua) != 0 && i >= n) {
            return 0;
          }
   }
  return 1;
}

int main(){
  int truck, Ntruck, i = 0, answer[100];
  scanf("%d", &Ntruck);
  while(Ntruck != 0){
    int trucks[Ntruck];
    for(int c = 0; c < Ntruck; c++){
      scanf("%d",&truck);
      trucks[c] = truck;
    }
    struct Stack * rua = createStack(Ntruck);
    answer[i] = organiza(trucks, rua, Ntruck);
    i++;
    scanf("%d",&Ntruck);
  }
  for(int j = 0; j < i; j++){
    if(answer[j]){
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }
  return 0;
}