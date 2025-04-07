#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
//a
struct nomeNotas {

    char nome[20];
    char notas1[3];
    char notas2[3];
    int n1;
    int n2;

};

int main() {

    int *n;
    char barraN = '\n';
    FILE *open;
    n = (int*) malloc(4);

    printf("Digite a quantidade de alunos:\n");
    scanf("%d", n);

    struct nomeNotas name[*n];

    open = fopen("teste.txt", "r+");

    //carregar arquivo (jeito chique)
    if (open == NULL) {

        printf("Arquivo nao encontrado\n");
        system("pause");
        printf("Criando arquivo...\n");

        #ifdef _WIN32
        Sleep(1000);
        #elif _WIN64
        Sleep(1000);
        #else
        sleep(1);
        #endif

        open = fopen("teste.txt", "w");

    }

    for(int i = 0; i < *n; i++) {

        printf("Digite o nome:\n");
        fflush(stdin);
        fgets(name[i].nome, 100, stdin);
    
        printf("Digite 2 notas:\n");

        scanf("%s ", name[i].notas1);
        scanf("%s", name[i].notas2);
        
        fputs(name[i].nome,open);
        fputs(name[i].notas1,open);

        fputc(barraN,open);

        fputs(name[i].notas2,open);

        fputc(barraN,open);
        
    }

    float media[*n];
    float mediaClasse = 0;
    int quantAprov = 0;
    int quantReprov = 0;

    for(int i = 0; i < *n; i++) {

        name[i].n1 = atoi(name[i].notas1);
        name[i].n2 = atoi(name[i].notas2);

        media[i] = (name[i].n1 + name[i].n2) / 2;
        mediaClasse += media[i];

        if (media[i] >= 7) {
            quantAprov++;
        } else {
            quantReprov++;
        }

    }

    float percent;
    percent = ((float) quantAprov / *n);


    fprintf(open, "Media: %.2f Aprovados:%d Reprovados: %d Percent: %.2f%%", mediaClasse / *n, quantAprov, quantReprov, percent*100);

    fclose(open);
}