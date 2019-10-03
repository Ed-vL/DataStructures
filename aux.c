#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  FILE * fp;
  fp = fopen("./randInt.txt","w");
  for(int i = 0; i < 100000000; i++){
    fprintf(fp,"%d\n",i);
  }
  fclose(fp);
  return 0;
}