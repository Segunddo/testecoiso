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
            
            fgets(name[i].notas1,3,stdin);
            fgets(name[i].notas2,3,stdin);
            
            fputs(name[i].nome,open);
            fputs(name[i].notas1,open);
            fputs(name[i].notas2,open);
    
            
        }

    } else {
        printf("Deseja editar o arquivo existente?\nDigite 's' para sim.\n");
        char sim = 's';
        scanf("%c", &sim);
        
        if (sim == 's') {

            printf("Digite o nome do aluno:\n");
            fflush(stdin);
            fgets(nomePesquisa,30,stdin);
            
            char copia[1000];
            fread(copia, sizeof(char), 999, open);

            if (strstr(copia,nomePesquisa)) {

                int reset = 0;
                while(reset == 0) {

                    printf("Digite:\n0-Mudar nome\n1-Mudar nota 1\n2-Mudar nota 2\nDigite outro numero para encerrar\n");
                    int opcao;
                    scanf("%d", &opcao);

                    char novaNota[2];
                    char novoNome[30];
                    int local = 0;
                    char *copiapt;
                    char *pt;

                    switch (opcao)
                    {
                        
                        case 0:
                            
                            pt = strstr(copia,nomePesquisa);
                            
                            for(copiapt = copia; copiapt != pt; copiapt++) {
                                local++;
                            }
                            fseek(open, local, SEEK_SET);
                            fflush(stdin);
                            printf("Digite o novo nome:\n");
                            fgets(novoNome,30,stdin);
                            fprintf(open,novoNome);

                            break;
                        case 1:

                            pt = strstr(copia,nomePesquisa);
                            copiapt = copia;
                            for(copiapt = copia; copiapt != pt; copiapt++) {
                                local++;
                            }
                            local += strlen(nomePesquisa) + 1;
                           
                            fseek(open, local, SEEK_SET);
                            printf("Digite a nova nota:\n");
                            fflush(stdin);
                            fgets(novaNota,2,stdin);
                            fprintf(open,novaNota);
                            break;
                        case 2:

                            pt = strstr(copia,nomePesquisa);
                            copiapt = copia;
                            
                            for(copiapt = copia; copiapt != pt; copiapt++) {
                                local++;
                            }
                            local += strlen(nomePesquisa) + 2;
                            
                            fseek(open, local, SEEK_SET);
                            printf("Digite a nova nota:\n");
                            fflush(stdin);
                            fgets(novaNota,2,stdin);
                            fprintf(open,novaNota);
                            break;        
                    
                        default:
                        reset = 1;
                            break;
                            
                    }
                }
                
            } else {printf("Ninguem encontrado...\n");}
            
        } else {printf("Encerrando...");}
    }

    fclose(open);
    free(n);
}