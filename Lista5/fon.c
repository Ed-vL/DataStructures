#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  FILE * fp;
  fp = fopen("./edu.txt","w");
  fprintf(fp,"1\n");
  fprintf(fp,"101\n");
  for(int i = 0; i < 101; i++){
    fprintf(fp,"ADD:edu\n");
  }
  fclose(fp);
  return 0;
}