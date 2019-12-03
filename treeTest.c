#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int value,raiz;
  int n;
  struct node * l;
  struct node * r;
} node;

node * rotR(node * h){
  node * x;
  x = malloc(sizeof(node));
  x = h->l;
  h->l = x->r;
  x->r = h;
  return x;
}

node * rotL(node * h){
  node * x;
  x = malloc(sizeof(node));
  x = h->r;
  h->r = x->l;
  x->l = h;
  return x;
}

node * insertT(node * h, int value){
  if(h == NULL){
    node * new;
    new = malloc(sizeof(node));
    new->l = NULL;
    new->r = NULL;
    new->value = value;
    new->raiz = 1;
    return new;
  }
  if(value < h->value){
    h->l = insertT(h->l, value);
    h = rotR(h);
  } else {
    h->r = insertT(h->r, value);
    h = rotL(h);
  }
  return h;
}

int countN(node * h){
  if(h == NULL){
    return 0;
  }
  h->n = 1 + countN(h->l) + countN(h->r);
  return h->n;
}

int selectR(node * h, int k){
  if(h == NULL){
      return 0;
    }
  int t = (h->l == NULL)? 0:h->l->n;
  if(t > k){
    return selectR(h->l,k);
  }
  if(t < k){
    return selectR(h->r,k-t-1);
  }
  return h->value;
}

node * partR(node * h, int k){
  int t = (h->l == NULL)?0:h->l->n;
  if(t>k){
    h->l = partR(h->l,k);
    h = rotR(h);
  }
  if(t<k){
    h->r = partR(h->r,k-t-1);
    h = rotL(h);
  }
  return h;
}

node * balance(node * h){
  if(h->n < 2) return h;
  h = partR(h,(h->n)/2);
  h->l = balance(h->l);
  h->r = balance(h->r);
  return h;
}

void InOrder(node * h){
  if(h == NULL) return;
   
  InOrder(h->l);
  if(h->raiz){
    printf("No: %d N: %d\n",h->value,h->n);
    h->raiz = 0;
  } else {
    printf("No: %d N: %d\n",h->value,h->n);
  }
  InOrder(h->r);
}

int height(node * r, int s){
  if(r == NULL) {
    return s-1;
  }
  int left = height(r->l, s+1);
  int right = height(r->r, s+1);

  if(left > right){
    return left;
  }
  if(right > left){
    return right;
  }
}

int main(){
  int fon, yeet;
  node * raiz;
  raiz = NULL;
  while (scanf("%d",&fon) == 1)
  {
    raiz = insertT(raiz, fon);
  }
  countN(raiz);
  // yeet = selectR(raiz,2);
  // printf("Tree[1]: %d\n",yeet);
  InOrder(raiz);
  // printf("----------------\n");
  // raiz = partR(raiz,3);
  // countN(raiz);
  //InOrder(raiz);
  int h = height(raiz,0);
  printf("h:%d\n",h);
  return 0;
}