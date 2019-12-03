#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_strcat(char* destination, const char* source)
{
	int i, j;

	for (i = 0; destination[i] != '\0'; i++);
	for (j = 0; source[j] != '\0'; j++)
		destination[i + j] = source[j];
	destination[i + j] = '\0';
	return;
}

int strcomp(char * str1, char * str2){
  int c = 0;
  if(str1 == NULL || str2 == NULL){
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

void treatstring(char * string){
  int i = 0, c,j = 0;
  int arroba;
  while (string[i] != '\0')
  {
    //printf("String: %s\n",string);
    if(string[i] == '+'){
       c = i;
       while(string[c] != '@'){
        c++;
      }
      //printf("string[%d]: %c\n",i-1,string[i-1]);
      string[i] = '\0';
      my_strcat(&string[i],&string[c]);
      break; 
    }
    if(string[i] == '.'){
      if(string[i+1] == '.'){
        j = i;
        while(string[j] == '.'){
          j++;
        }
        string[i] = '\0';
        my_strcat(&string[i-1],&string[j-1]);
      }
      
      if(string[i+1] == '@'){
        my_strcat(&string[i-1],&string[i+1]);
        break;
      }
      if(string[i+1] == '+'){
        c = i+1;
       while(string[c] != '\0'){
        if(string[c] == '@'){ 
          arroba = c;
          break;
        }
        c++;
      }
      string[i+1] = '\0';
      my_strcat(&string[i],&string[c]);
      break;
      }
      string[i] = '\0';
      //printf("Join: %s  %s\n",string,&string[i+1]);
      my_strcat(string,&string[i+1]);
      //printf("TOGETHER NOW: %s\n",string);
    }
    i++;
    if(string[i] == '@') break;
  }
 // printf("final: %s\n",string);
  return;
}

int compare(char ** emails, int size){
  char * string;
  int count = size;
  for(int i = 0; i < size; i ++){
    //printf("emails[%d]: %s\n",i,emails[i]);
    string = emails[i];
    //printf("String: %s\n",string);
    for(int c = i+1; c < size;c++){
      //printf("Emails[%d]: %s\n",c,emails[c]);
      if(strcomp(string,emails[c])){
        //printf("tirou 1\n");
        count--;
        break;
      }
    }
  }
  return count;
}

int main(){
  int n, result;
  scanf("%d",&n);
  char * entry;
  char ** emails;
  emails = malloc(sizeof(char)*n*100);
  for(int i = 0; i < n; i ++){
    entry = malloc(sizeof(char)*100);
    scanf("%s",entry);
    treatstring(entry);
    emails[i] = entry;
  }
  result = compare(emails,n);
  printf("%d\n",result);
  return 0;
}
