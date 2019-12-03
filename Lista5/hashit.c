#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Hashtable{
  int size;
  char ** table;
}Hashtable;

int strcomp(char * str1, char * str2){
  int c = 0;
  if(str1 == NULL){
    return 0;
  } else {
    while(str1[c] != '\0' && str2[c] != '\0'){
      if(str1[c] != str2[c]){
        return 0;
      }
      c++;
    }
    if(str1[c] != '\0' || str2[c] != '\0'){
      return 0;
    }
    return 1;
  }
}

int hashfunc(char * key){
  int hashed = 0, i = 0;
  while(key[i] != 0){
    hashed += key[i]*(i+1);
    i++;
  }
  return (19*hashed)%101;
}

 void push(Hashtable * hashtable, char * key){
  int hash = hashfunc(key),sonda = 0;
  int h = hash;
  char * c, * value;
  value = malloc(sizeof(char)*15);
  strcpy(value,key);
  for(int i = 0; i < 20; i++){
    c = hashtable->table[hash];
    if(strcomp(c, value)) return;
    sonda++;
    hash = ((h)+(sonda*sonda)+(23*sonda))%101;
  }
  sonda = 0;
  hash = hashfunc(value);
  for(int i = 0; i < 20; i++){
    c = hashtable->table[hash];
    if(c == NULL) break;
    sonda++;
    hash = ((h)+(sonda*sonda)+(23*sonda))%101;
  }
  if(sonda >= 20){
    return;
  } else if (c == NULL) {
    hashtable->table[hash] = value;
    hashtable->size++;
    return;
  }
 }

void del(Hashtable * hashtable, char * key){
  int hash = hashfunc(key),sonda;
  char * c;
  for(sonda = 0; sonda < 20; sonda++){
    c = hashtable->table[hash];
    if(strcomp(c,key)) break;
    hash = ((hashfunc(key))+(sonda*sonda)+(23*sonda))%101;
  }
  if(sonda >= 20){
    return;
  } else {
    hashtable->table[hash] = NULL;
    hashtable->size--;
    return;
  }
}
void printHash(Hashtable * hashtable){
  int sonda = 0;
  printf("%d\n",hashtable->size);
  for(int i = 0; i < 101;i++){
    if(hashtable->table[i] != NULL){
      printf("%d:%s\n",i,hashtable->table[i]);
    }
  }
  return;
}

void reset(Hashtable * hashtable){
  for(int i = 0; i < 101; i++){
    hashtable->table[i] = NULL;
  }
  hashtable->size = 0;
  return;
}

int main(){
  int n, op;
  char entries[19];
  Hashtable * hashtable;
  hashtable = malloc(sizeof(Hashtable));
  hashtable->table = malloc(sizeof(char)*101*16);
  hashtable->size = 0;
  scanf("%d",&n);
  for (int i = 0; i < n ; i++){
    scanf("%d",&op);
    for(int c = 0; c < op; c++){
      scanf("%s",entries);
      switch (entries[0])
      {
      case 'A':
        push(hashtable,&entries[4]);
        break;
      case 'D':
        del(hashtable,&entries[4]);
      default:
        break;
      }
    }
    printHash(hashtable);
    reset(hashtable);
  }
}