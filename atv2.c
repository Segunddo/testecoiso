#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>

struct nomeNotas {

    char nome[20];
    char notas1[3];
    char notas2[3];
    float n1;
    float n2;

};

int main() {

    int *n;
    char barraN = '\n';
    FILE *open;
    n = (int*) malloc(4);
    char nomePesquisa[30];

    open = fopen("quest4.txt", "r+");

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

        printf("Digite a quantidade de alunos:\n");
        scanf("%d", n);

        struct nomeNotas name[*n];

        open = fopen("quest4.txt", "w");

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

    } else {
        printf("Deseja editar o arquivo existente?\nDigite 's' para sim.");
        char sim = 's';
        scanf("%c", &sim);
        
        if (sim == 's') {

            printf("Digite o nome do aluno:\n");
            fflush(stdin);
            fgets(nomePesquisa,30,stdin);
            nomePesquisa[strlen(nomePesquisa)-1] = '\0';
           
            if (strcmp(nomePesquisa,fgets(nomePesquisa,30,open)) == 0) {

                fseek(open,-1 * sizeof(nomePesquisa), SEEK_CUR);
                
                int reset = 0;
                while(reset == 0) {

                    printf("Deseja alterar o nome ou as notas:\n");
                    printf("Digite:\n0-Mudar nome\n1-Mudar nota 1\n2-Mudar nota 2\nDigite outro numero para encerrar\n");
                    int opcao;
                    scanf("%d", &opcao);
                    int novaNota;
                    char novoNome[30];

                    switch (opcao)
                    {
                        case 0:

                            fflush(stdin);
                            fgets(novoNome,30,stdin);
                            fprintf(open,novoNome);

                            break;
                        case 1:

                            fseek(open,1, SEEK_CUR);
                            printf("Escreva a nova nota:\n");
                            scanf("%d ", &novaNota);
                            fprintf(open, (char*) novaNota);

                            break;
                        case 2:

                            fseek(open,2, SEEK_CUR);
                            printf("Escreva a nova nota:\n");
                            scanf("%d ", &novaNota);
                            fprintf(open, (char*) novaNota);

                            break;        
                    
                        default:
                        reset = 1;
                            break;
                            
                    }
                }
                
            }
            
        } else {printf("Encerrando...");}
    }

    fclose(open);
    free(n);
}