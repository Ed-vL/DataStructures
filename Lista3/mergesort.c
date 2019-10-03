#include <stdio.h>
#include <stdlib.h>
void mergeAB(int * c, int * a, int m, int * b, int n){
  int i = 0, j = 0, k = 0;
  while( i < m && j < n){
    if(a[i] < b[j]){
      c[k] = a[i];
      i++;
      k++;
    } else {
      c[k] = b[j];
      k++;
      j++;
    }
  }
  while(i < m){
    c[k] = a[i];
    k++;
    i++;
  }
  while(j < n){
    c[k] = b[j];
    k++;
    j++;
  }
}

void merge(int * v,int l, int r, int q){
  int i = l, k = 0;
  int * c = malloc(sizeof(int)*(r-l+1));
  mergeAB(c,&v[l],(q-l+1),&v[q+1],(r-q));
  while (i<=r)
  {
    v[i] = c[k];
    i++,k++;
  }
  free(c);
}

void mergeSort(int * v, int l, int r){
  if(l == r){
    return;
  }
  int q = (r+l)/2;
  mergeSort(v,l,q);
  mergeSort(v,q+1,r);
  merge(v,l,r,q);
}

int main(){
  int v[100000], i = 0;
    while(scanf("%d",&v[i]) == 1){
      i++;
    }
    mergeSort(v,0,i);
    printf("%d",v[1]);
    for(int j = 2;j <= i;j++){
      printf(" %d",v[j]);
    }
    printf("\n");
  return 0;
}