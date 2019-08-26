#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define Key(A) (A)
#define less(A,B) (Key(A) < Key(B))
#define exch(A,B) {Item t=B; B=A; A=t;}
#define compexch(A,B) {if(less(B,A)) exch(A,B);}

void IS(Item * v, int l, int r){
 Item ordenado = v[l];
 for(int i = l+1; i <=r; i++){
   for(int k = i; k > l; k--){
     compexch(v[k - 1], v[k])
   }
 }
}


int main(){
  Item v[1000];
  int entrada, i = 0, k=1;

  while(scanf("%d",&entrada) == 1){
    v[i] = entrada;
    i++;
  }

  IS(v, 0, i - 1);
  printf("%d",v[0]);
 for(int k = 1; k < i; k++){
   printf(" %d",v[k]);
 }
  printf("\n");
  return 0;
}