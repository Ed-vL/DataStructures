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

void printList(node * list, int i, int aux){
  if(list[aux].prev != 0){
    aux = binarySearch(list,0,i-1,list[aux].prev);
    return printList(list,i,aux);
  } else {
    printf("%lx %lx %lx\n",list[aux].p,list[aux].prev,list[aux].next);
    return;
  }
}

int main(){
  node * address;
  node n,ptr1,ptr2;
  int i = 0, aux,x, c = 0;
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
  aux = iptr1;
  while(address[aux].prev != 0){
    c = aux;
    aux = binarySearch(address,0,i-1,address[aux].prev);
    if(aux == -1){
      aux = c;
      break;
    }
  }
  x = binarySearch(address,0,i-1,ptr1.prev);
  address[x].next = ptr2.next;
  c = binarySearch(address,0,i-1,ptr2.next);
  address[c].prev = address[x].p; 
  x = binarySearch(address,0,i-1,address[aux].next);
  while(x != -1 || address[x].next != 0){
    printf("%lx %lx %lx\n",address[aux].p,address[aux].prev,address[aux].next);
    if(address[x].p == ptr1.p){
      x = binarySearch(address,0,i-1,ptr2.next);
    }
    aux = x;
    x = binarySearch(address,0,i-1,address[x].next);
  }
  printf("%lx %lx %lx\n",address[aux].p,address[aux].prev,address[aux].next);
  printf("\n");
  while(address[iptr1].next != ptr2.next){
    printf("%lx\n",address[iptr1].p);
    iptr1 = binarySearch(address,0,i-1,address[iptr1].next);
  }
  printf("%lx\n",address[iptr2].p);
  return 0;
}