//Aqui serão declaradas as funções feitas pelo Lucas Emanuel
#ifndef FUNCOES_LULU_H
#define FUNCOES_LULU_H

#include "elementos.h"
#include <stdio.h>
#include <stdlib.h>


// Menu inicial para organizar as outras funções do projeto
void menuVonlohrmann() {

    int opLulu;

    do {
        printf("|------------------------------------------------|\n");
        printf("|              MENU DO VON LOHRMANN              |\n");
        printf("|------------------------------------------------|\n");
        printf("|  1.                                            |\n");
        printf("|  2.                                            |\n");
        printf("|  3.                                            |\n");
        printf("|  0. Sair                                       |\n");
        printf("|------------------------------------------------|\n");
        printf("Qual menu de funções deseja escolher: ");
        scanf("%d", &opLulu);

        switch (opLulu) {
            case 1:

            break;
            case 2:

            break;
            case 3:

            break;
            case 0:
                printf("|------------------------------------------------|\n");
                printf("|             Encerrando Programa...             |\n");
                printf("|------------------------------------------------|\n");
            break;
            default:
                printf("|------------------------------------------------|\n");
                printf("|       Opção inválida, tente novamente!         |\n");
                printf("|------------------------------------------------|\n");
        }

    } while (opLulu != 0);
}


#endif
