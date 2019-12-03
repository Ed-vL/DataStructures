#include <stdio.h>
#include <stdlib.h>

typedef struct bairro{
  int * hashtable;
  int julius;
}bairro;

int main()
{
  bairro **hash;
  int n, m, j, entry, ni, mi, ji;
  scanf("%d %d %d", &n, &m, &j);
  hash = malloc(sizeof(bairro*)*n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &ni);
    hash[i]->hashtable = malloc(sizeof(int)*ni);
    for (int c = 0; c < ni; c++)
    {
      scanf("%d", &entry);
      hash[i]->hashtable[entry] = entry;
      //printf("hashtable[%d][%d]: %d\n",i,entry,hashtable[ji][entry]);
    }
  }
  for (int i = 0; i < m; i++)
  {
    scanf("%d", &mi);
    for(int k = 0; k < n;k++){
    if(mi == hash[k]->hashtable[mi]){
    hash[k]->julius = 1;
    } else {
      hash[k]->julius = 0;
     }
   }
  }
  for (int i = 0; i < j; i++)
  {
    scanf("%d", &ji);
   
      if (hash[ji]->julius)
      {
        printf("Eu vou estar la\n");
      } else {
        printf("Nao vou estar la\n");
      }
  }
  return 0;
}