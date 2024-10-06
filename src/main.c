#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "elementos.h"
#include "funcoes_carvas.h"
#include "funcoes_lulu.h"
#include "funcoes_edu.h"
#include "funcoes_judas.h"


int main(){

    setlocale(LC_ALL, "Portuguese");

    int op;

    do{

        printf("===== MENU PRINCIPAL =====\n");
        printf("1. Menu (Lucas Carvalho)\n");
        printf("2. Menu (Lucas Emanuel)\n");
        printf("3. Menu (Guilherme Yago)\n");
        printf("4. Menu (Eduardo Coelho)\n");
        printf("0. Sair\n");
        printf("==========================\n");
        wprintf(L"Qual menu de funções deseja escolher: ");
        scanf("%d",&op);

        switch(op){

            case 1:
                pilha_exe();
                break;


            case 2:

                break;

            case 3:

                break;

            case 4:

                break;

            default:

                if(op == 0) {
                    printf("Encerrando Programa...");
                    break;
                }
                wprintf(L"Opção inválida");
        }
    }while(op != 0);
return 0;
}