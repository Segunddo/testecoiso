/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char input[100];
    char contrario[100];
    int igual = 0;
    
    fgets(input, 100, stdin);
    
    for (int i = strlen(input); i >= 0; i--) {
        contrario[strlen(input) - 1] = input[i];
        
        printf("%c", contrario[strlen(input) - 1]);
    }

    igual = strcmp(contrario,input);
    printf("\n%d", igual);
    
    if (igual == 0) {
        printf("Iguais");
    } else {
        printf("Diferentes");
    }
}