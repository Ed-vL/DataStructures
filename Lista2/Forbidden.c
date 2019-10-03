#include <stdio.h>
#include <stdlib.h>

#define exch(a,b) { int t = b; b = a; a = t;}

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

static int separa(int * v, int l, int r){
  int c = v[r];
  int j = l;

  for(int i = l; i < r; i++){
    if(v[i] <= c){
        exch(v[i],v[j]);
        j++;
    }
  }
  exch(v[j],v[r]);

  return j;
}

void Qsort(int * v, int l, int r){
  int j;
  if( l < r){
    j = separa(v,l,r);
     Qsort(v,l,j-1);
     Qsort(v,j+1,r);
  } else {
    return;
  }
  
}

int binarySearch(int * v, int l, int r, int target){

  if(r >= l){
    int meio = l + (r -l) /2;
    if(v[meio] == target){
      return 1;
    }
    if(v[meio] > target){
      return binarySearch(v,l,meio - 1,target);
    } else {
      return binarySearch(v,meio + 1,r, target);
    }

  } else {
    return 0;
  }
}

int main(){
  int N, entrada, c = 0, j = 0;
  scanf("%d",&N);
  int proibido[N];
  Vector answer;
  init(&answer);
  for (int i = 0; i < N; i++){
    scanf("%d",&entrada);
    proibido[i] = entrada;
  }
  Qsort(proibido,0,N - 1);
  while(scanf("%d", &entrada) == 1){
    append(&answer,binarySearch(proibido,0,N - 1,entrada));
    c++;
  }
  for(int i = 0; i < c; i++){
    if(get(&answer,i)){
      printf("sim\n");
    } else {
      printf("nao\n");
    }
  }
  return 0;
}

