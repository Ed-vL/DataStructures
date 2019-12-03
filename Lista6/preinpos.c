#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int value;
  struct node * l;
  struct node * r;
}node;

node * insertT(node * root, int value){
  if(root == NULL){
    node * new;
    new = malloc(sizeof(node));
    new->value = value;
    new->l = NULL;
    new->r = NULL;
    return new;
  }
  if(value < root->value){
    root->l = insertT(root->l, value);
  } else {
    root->r = insertT(root->r, value);
  }
  return root;
}

node * initT(void){
  return NULL;
}

void preorder(node * root){
  if(root == NULL){
    return;
  }
  printf("%d ",root->value);
  preorder(root->l);
  preorder(root->r);
}

void inorder(node * root){
  if(root == NULL){
    return;
  }
  inorder(root->l);
  printf("%d ",root->value);
  inorder(root->r);
}

void posorder(node * root){
  if(root == NULL){
    return;
  }
  posorder(root->l);
  posorder(root->r);
  printf("%d ",root->value);
}

int main (){
  int value;
  node * somosnozes;
  somosnozes = malloc(sizeof(node));
  somosnozes = initT();
  scanf("%d",&value);
  somosnozes = insertT(somosnozes,value);
  while(scanf("%d",&value) == 1){
    insertT(somosnozes,value);
  }
  preorder(somosnozes);
  printf(".\n");
  inorder(somosnozes);
  printf(".\n");
  posorder(somosnozes);
  printf(".\n");
  return 0;
}