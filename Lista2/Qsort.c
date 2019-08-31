#include <stdio.h>

#define exch(a,b) { int t = b; b = a; a = t;}

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

int main(){
  int entrada, vetor[100000], i = 0;
  while(scanf("%d",&entrada) == 1){
    vetor[i] = entrada;
    i++;
  }
  Qsort(vetor,0,i);
  printf("%d",vetor[1]);
  for(int c = 2; c <= i; c++){
    printf(" %d",vetor[c]);
  }
  printf("\n");
  return 0;
}