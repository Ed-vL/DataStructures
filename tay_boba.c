#include <stdio.h>
#include <string.h>

int main(){
    printf("Diga, a Tay é boba? Sim (s) ou Não (n)?\n");
    char ans;
    scanf("%c",&ans);
    switch (ans)
    {
    case 's':
        printf("A Tay é boba\n");
        break;
    case 'n':
        printf("Errado, a Tay é boba sim\n");
        break;
    default:
        printf("Só s ou n, tu é bobo também\n");
        break;
    }
    return 0;
}