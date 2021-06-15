#include <stdio.h>
#include <string.h>

int main(){
    printf("Diga, a Tay é boba? Sim (s) ou Não (n)?\n");
    char ans;
    scanf("%c",&ans);
    if(strcmp(&ans,"s") == 0){
        printf("A Tay é boba\n");
    } else if(strcmp(&ans,"n") == 0){
        printf("Errado, a Tay é boba sim\n");
    } else {
        printf("Só s ou n, tu é bobo também\n");
    }
    return 0;
}