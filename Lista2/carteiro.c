#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    int val;
    struct Node *next;
}Node;

typedef struct Table{
    int size;
    struct Node **list;
}Table;

Table * createHashMap(int size){
    Table *t = (Table*)malloc(sizeof(Table));
    t->size = size;
    t->list = (Node**)malloc(sizeof(Node*)*size);
    int i;
    for(i=0;i<size;i++)
        t->list[i] = NULL;
    return t;
}
int hashCode(Table *t,int key){
    if(key<0)
        return -(key%t->size);
    return key%t->size;
}
void inserir(Table *t,int key,int val){
    int pos = hashCode(t,key);
    Node *list = t->list[pos];
    Node *newNode = (Node*)malloc(sizeof(Node));
    Node *temp = list;
    while(temp){
        if(temp->key==key){
            temp->val = val;
            return;
        }
        temp = temp->next;
    }
    newNode->key = key;
    newNode->val = val;
    newNode->next = list;
    t->list[pos] = newNode;
}
int procurar(Table *t,int key){
    int pos = hashCode(t,key);
    struct Node *list = t->list[pos];
    struct Node *temp = list;
    while(temp){
        if(temp->key==key){
            return temp->val;
        }
        temp = temp->next;
    }
    return -1;
}

int main(){
  int N,M;
  Table * map = createHashMap(45000);
  int destinos[45000], d = 0, casa, target,c = 0;
  scanf("%d",&N);
  scanf("%d",&M);
  for(int i = 0;i < N;i++){
    scanf("%d",&casa);
    inserir(map,casa,i);
  }
  for(int i = 0;i < M;i++){
   scanf("%d",&target);
   destinos[i] = target;
  }
  for(int i = 0; i < M;i++){
    destinos[i] = procurar(map,destinos[i]);
  }
  for(int i = 0; i < M; i++){
    d += abs(destinos[i] - c);
    c = destinos[i];
  }
  printf("%d\n",d);
  return 0;
}