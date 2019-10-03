#include <stdio.h>

int recorrente(int * v, int n){
  int counter = 0, elemento;
    for(int i = 0;i < n;i++){
      if(counter == 0){
        elemento = v[i];
        counter = 1;
      } else if(v[i] == elemento){
          counter++;
      } else if(v[i] != elemento){
          counter--;
      }
    }
  return elemento;
}

int main(){
    int v[5000], counter = 1, elemento,n,answer[5000], j = 0;
    scanf("%d",&n);
    while( n != 0){
    for(int i =0;i<n;i++){
      scanf("%d",&v[i]);
    }
    answer[j] = recorrente(v,n);
    j++;
    scanf("%d",&n);
    }
    
    for(int i = 0; i < j; i++){
      printf("%d\n",answer[i]);
    }
    
    return 0;
}