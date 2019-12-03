#include <stdio.h>
#include <stdlib.h>


typedef struct node{
  unsigned long p,next,prev;
}node;

void mergeAB(node * c, node * a, int m, node * b, int n){
  int i = 0, j = 0, k = 0;
  while( i < m && j < n){
    if(a[i].p < b[j].p){
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

void merge(node * v,int l, int r, int q){
  int i = l, k = 0;
  node * c = malloc(sizeof(node)*(r-l+1));
  mergeAB(c,&v[l],(q-l+1),&v[q+1],(r-q));
  while (i<=r)
  {
    v[i] = c[k];
    i++,k++;
  }
  free(c);
}

void mergeSort(node * v, int l, int r){
  if(l == r){
    return;
  }
  int q = (r+l)/2;
  mergeSort(v,l,q);
  mergeSort(v,q+1,r);
  merge(v,l,r,q);
}

int binarySearch(node * v, int l, int r, unsigned long target){

  if(r >= l){
    int meio = l + (r -l) /2;
    if(v[meio].p == target){
      return meio;
    }
    if(v[meio].p > target){
      return binarySearch(v,l,meio - 1,target);
    } else {
      return binarySearch(v,meio + 1,r, target);
    }
  } else {
    return -1;
  }
}

int main(){
  node * address;
  node n,ptr1,ptr2;
  int i = 0, validate = 1, j,aux;
  address = malloc(sizeof(node)*250000);
  unsigned long p,next,prev;
  while(scanf(" %lx",&p) != -1){
    scanf(" %lx",&prev);
    scanf(" %lx",&next);
    n.p = p;
    n.next = next;
    n.prev = prev;
    address[i] = n;
    i++;
  }
  ptr1 = address[0];
  ptr2 = address[1];
  mergeSort(address,0,i-1);
  int iptr1 = binarySearch(address,0,i-1,ptr1.p);
  int iptr2 = binarySearch(address,0,i-1,ptr2.p);
  j = iptr1;
  aux = iptr1;
  while(address[aux].p != address[iptr2].p){
    j = binarySearch(address,0,i-1,address[j].next);
    if(address[j].prev != address[aux].p){
      validate = 0;
      break;
    }
    aux = binarySearch(address,0,i-1,address[aux].next);
  }
  if(validate){
    printf("sana\n");
  } else {
    printf("insana\n");
  }
  return 0;
}