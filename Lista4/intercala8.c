#include <stdio.h>
#include <stdlib.h>

int * intercala2(int * a, int sa, int * b, int sb){
  int ca = 0, cb = 0, cc = 0;
  int * c = malloc(sizeof(int)*(sa+sb+10));
  while(ca < sa && cb < sb){
    if(a[ca] <= b[cb]){
      c[cc] = a[ca];
      cc++;
      ca++;
    } else if(b[cb] < a[ca]){
      c[cc] = b[cb];
      cc++;
      cb++;
    }
  }
  while(ca < sa){
    c[cc] = a[ca];
    ca++;
    cc++;
  }
  while(cb < sb){
    c[cc] = b[cb];
    cb++;
    cc++;
  }
  return c;
}

int * intercala4(int * a, int sa, int * b, int sb,int * c, int sc, int * d, int sd){
    int * aux1 = malloc(sizeof(int)*(sa+sb+10));
    int * aux2 = malloc(sizeof(int)*(sc+sd+10));
    int * answer = malloc(sizeof(int)*(sa+sb+sc+sd+10));
    aux1 = intercala2(a,sa,b,sb);
    aux2 = intercala2(c,sc,d,sd);
    answer = intercala2(aux1,(sa+sb),aux2,(sc+sd));
    return answer;
}

int * intercala8(int * a, int sa, int * b, int sb,int * c, int sc, int * d, int sd,int * e, int se, int * f, int sf,int * g, int sg, int * h, int sh){
    int * aux1 = malloc(sizeof(int)*(sa+sb+sc+sd+10));
    int * aux2 = malloc(sizeof(int)*(se+sf+sg+sh+10));
    int * answer = malloc(sizeof(int)*(sa+sb+sc+sd+se+sf+sg+sh+10));
    aux1 = intercala4(a,sa,b,sb,c,sc,d,sd);
    aux2 = intercala4(e,se,f,sf,g,sg,h,sh);
    answer = intercala2(aux1,(sa+sb+sc+sd),aux2,(se+sf+sg+sh));
    return answer;
}

int main(){
  int n, s, v[8][100000],sizes[8],aux = 0;
  int * intercalado;
  intercalado = malloc(sizeof(int)*100000);
  for(int i = 0;i < 8;i++){
    scanf("%d",&s);
    aux += s;
    if(s == 0){
      v[i][0] = 0;
      sizes[i] = 0;
      continue;
    }
    sizes[i] = s;
    for(int c = 0; c < s; c++){
      scanf("%d",&n);
      v[i][c] = n;
    }
  }
  intercalado = intercala8(v[0],sizes[0],v[1],sizes[1],v[2],sizes[2],v[3],sizes[3],v[4],sizes[4],v[5],sizes[5],v[6],sizes[6],v[7],sizes[7]);
  printf("%d",intercalado[0]);
  for(int i = 1; i < aux; i++){
    printf(" %d",intercalado[i]);
  }
  printf("\n");
  free(intercalado);
  return 0;
}