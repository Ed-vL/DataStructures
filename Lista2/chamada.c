#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int menor,j = 0,sorteado;
  char aux[100];
  int num,c = 0;
  char nome[100][100];
  scanf("%d",&num);
  scanf("%d",&sorteado);
  for(int i = 0; i < num; i++){
    scanf("%s",nome[i]); 
  }
  for(int k = 0;k < num - 1;k++){
   menor = k;
    for(int i = k+1; i < num;i++){
      if(nome[i][0] < nome[menor][0]){
        menor = i;
      }
      else if(nome[i][0] == nome[menor][0]){
        while(nome[i][j] == nome[menor][j]){
          if(nome[i][j+1] < nome[menor][j+1] && (j+1) != 20){
            menor = i;
            j = 0;
            break;
          } else if(nome[i][j+1] > nome[menor][j+1]){
            j = 0;
            break;
          }
          j++;
        } 
      }
    
    }
    strcpy(aux,nome[k]);
    strcpy(nome[k],nome[menor]);
    strcpy(nome[menor],aux);
  }
  printf("%s\n",nome[sorteado-1]);
  return 0;
}