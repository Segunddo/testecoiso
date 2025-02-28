#include <stdio.h>
#include <time.h>

int main(){
    //numero aleatorio
    srand(time(NULL));
    int numero_aleatorio = rand() %101;
    //gameplay
    int i = 0;
    int n1;
    while(i <= 10){
            printf("digite um numero entre 1 e 100 para tentar descobrir\n")
            scanf("%d", &n1);
        if(numero_aleatorio < n1){
            printf("o numero e menor");
            getchar();
        }
        else if(numero_aleatorio > n1){
            printf("o numero e maior");
            getchar();
        }
        else{
            printf("voce acertou!!!");
            getchar();
            i = 10;
        }
        i++;
    }
    return 0;
}
