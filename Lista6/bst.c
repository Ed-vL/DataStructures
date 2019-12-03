#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int value, raiz;
  struct node * l;
  struct node * r;
}node;

node * rightRotate(node * y) 
{ 
    node *x = y->l; 
    y->l = x->r; 
    x->r = y; 
    return x; 
}

node *leftRotate(node * x) 
{ 
    node * y = x->r; 
    x->r = y->l; 
    y->l = x; 
    return y; 
} 

node * insertT(node * root, int value){
  if(root == NULL){
    node * new;
    new = malloc(sizeof(node));
    new->value = value;
    new->l = NULL;
    new->r = NULL;
    new->raiz = 1;
    return new;
  }
  if(value < root->value){
    root->l = insertT(root->l, value);
    root = rightRotate(root);
  } else {
    root->r = insertT(root->r, value);
    root = leftRotate(root);
  }
  return root;
}

node * initT(void){
  return NULL;
}

void inorder(node * root){
  if(root == NULL){
    return;
  }
  inorder(root->l);
  if(root->raiz){
    printf("*%d ",root->value);
    root->raiz = 0;
  } else {
    printf("%d ",root->value);
  }
  inorder(root->r);
}



int main (){
  int value;
  node * somosnozes;
  somosnozes = malloc(sizeof(node));
  somosnozes = initT();
  while(scanf("%d",&value) == 1){
    somosnozes = insertT(somosnozes,value);
    inorder(somosnozes);
    printf(".\n");
  }
  
  return 0;
}