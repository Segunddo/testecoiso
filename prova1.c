#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

unsigned int cont = 0;

typedef struct
{
    char nome[500];
    int idade;
    char cargo[100];
    float salario;
}tFuncionarios;

void cadastro(tFuncionarios **lista, unsigned int *cont)
{
    (*cont)++;
    *lista = realloc(*lista, *cont * sizeof(tFuncionarios));

    printf("--------digite as informacoes do funcionario--------\n");

    fflush(stdin);
    printf("nome: \n");
    fgets((*lista)[*cont - 1].nome, 500, stdin);
    (*lista)[*cont - 1].nome[strcspn((*lista)[*cont - 1].nome, "\n")] = '\0';

    printf("Idade:\n");
    scanf("%d", &(*lista)[*cont - 1].idade);

    fflush(stdin);
    printf("Cargo:\n");
    fgets((*lista)[*cont - 1].cargo, 100, stdin);
    (*lista)[*cont - 1].cargo[strcspn((*lista)[*cont - 1].cargo, "\n")] = '\0';

    printf("Salario:\n");
    scanf("%f", &(*lista)[*cont - 1].salario);
    
    return;
}

void busca(tFuncionarios lista[], unsigned int cont)
{
    char nome[200];
    fflush(stdin);
    printf("digite o nome completo do funcionario:\n");
    fgets(nome, 200, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for(unsigned int i = 0; i < cont; i++)
    {
        if(strcmp(nome, lista[i].nome) == 0)
        {
            printf("nome: %s\n", lista[i].nome);
            printf("idade: %d\n", lista[i].idade);
            printf("cargo: %s\n", lista[i].cargo);
            printf("salario: %.2lf\n", lista[i].salario);

            return;
        }
    }
    printf("Funcionario nao existe!!\n");
    return;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    tFuncionarios *lista = NULL;
    char opcao;

    do
    {
        printf("--------MENU--------\n");
        printf("digite:\n1 - Cadastro\n2 - Busca\n0 - Sair\n");
        scanf(" %c", &opcao);

        switch (opcao)
        {
        case '1':
            cadastro(&lista, &cont);
            system("cls");
            break;
        case '2':
            busca(lista, cont);
            break;
        case '0':
            free(lista);
            return 0;
        default:
            printf("valor invalido\n");
            opcao = -1;
            break;
        }

    }while(opcao != 0);

}