#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

static int cont = 0;

typedef enum {smartphone = 1, notebook, televisor}tipos;

typedef union
{
    char sistema[20];
    int tela;
    int ram;
    char resolucao[8];
}info;

typedef struct
{
    info extra;
    tipos tipo;
    char nome[99];
    double preco;
}tproduto;

void cadastro(tproduto **produto, int *cont)
{
    char tipo[100];
    *produto = realloc(*produto, ((*cont) + 1) * sizeof(tproduto));

        printf("digite o nome do produto:\n");
        fflush(stdin);
        scanf("%99[^\n]s", (*produto)[*cont].nome);

        printf("digite tipo de produto (smartphone, notebook, televisor):\n");
        fflush(stdin);
        scanf("%99[^\n]s", tipo);
        if(strcmp(tipo, "smartphone") == 0)
        {
            (*produto)[*cont].tipo = smartphone;
            printf("digite o nome do sistema operacional:\n");
            fflush(stdin);
            scanf("%20[^\n]s", (*produto)[*cont].extra.sistema);
        }
        else if(strcmp(tipo, "notebook") == 0)
        {
        (*produto)[*cont].tipo = notebook;
            printf("digite o tamanho da tela em polegada:\n");
            scanf("%d", &(*produto)[*cont].extra.tela);
            printf("digite a quantidade de memoria RAM em GB:\n");
            scanf("%d", &(*produto)[*cont].extra.ram);
        }
        else if(strcmp(tipo, "televisor") == 0)
        {
            produto[*cont]->tipo = televisor;
            printf("digite o tamanho da tela em polegada:\n");
            scanf("%d", &(*produto)[*cont].extra.tela);
            printf("digite a resolucao da tela:\n");
            fflush(stdin);
            scanf("%8[^\n]s", (*produto)[*cont].extra.resolucao);
        }
        
        printf("digite o preco do produto:\n");
        scanf("%lf", &(*produto)[*cont].preco);

        (*cont)++;

        return;
}

void busca(tproduto produto[], int cont)
{
    char buscar[100];
    printf("digite o nome do produto:\n");
    fflush(stdin);
    fgets(buscar, 99, stdin);
    buscar[strcspn(buscar, "\n")] = '\0';
    
    for(int i = 0; i < cont; i++)
    {
        if(strcmp(buscar, produto[i].nome) == 0)
        {
            printf("Nome: %s\n", produto[i].nome);
            if(produto[i].tipo == smartphone)
            {
            printf("Categoria: <Smartphone>\n");
            printf("Sistema: %s\n", produto[i].extra.sistema);
            }
            else if(produto[i].tipo == notebook )
            {
                printf("Categoria: <notebook>\n");
                printf("Tela: %d\"\n", produto[i].extra.tela);
                printf("Memória RAM: %d\n", produto[i].extra.ram);
            }
            else if(produto[i].tipo == televisor)
            {
                printf("Categoria: <Televisor>\n");
                printf("Tela: %d\"", produto[i].extra.tela);
                printf("Resolucao: %s\n", produto[i].extra.resolucao);
            }
            else
            {
            printf("Categoria: <indefinido>\n");
            printf("Preco: %.2lf\n", produto[i].preco);
            }
            return;
        }
    }
    printf("produto nao encontrado!!\n");
    return;
}

int main()
{
    setlocale(LC_ALL, "Portugues");
    tproduto *produto = NULL;
    char opcao;

    do
    {
        printf("--------MENU--------\n");
        printf("digite:\n1 - Cadastro\n2 - Busca\n0 - Sair\n");
        fflush(stdin);
        scanf(" %c", &opcao);

        switch (opcao)
        {
        case '1':
            cadastro(&produto, &cont);
            system("cls");
            break;
        case '2':
            busca(produto, cont);
            break;
        case '0':
            free(produto);
            return 0;
        default:
            printf("valor invalido\n");
            opcao = -1;
            break;
        }
    }while(opcao != 0);
}