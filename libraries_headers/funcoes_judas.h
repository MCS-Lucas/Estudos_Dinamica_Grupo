//Aqui serão declaradas as funções feitas pelo Guilherme Yago
#ifndef FUNCOES_JUDAS_H
#define FUNCOES_JUDAS_H

#include "elementos.h"
#include <locale.h>

void limparTela() {
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#else

#endif
}





void bubbleSort() {
    int numeros[10];
    int i, aux, contador, input;
    int *p;

    printf("Entre com dez números para preencher o array, e pressione enter após digitar cada um:\n");
    for (i = 0; i <= 9; i++) {
        printf("%d/10: ", i);
        scanf("%d", &input);
        *(numeros + i) = input; // "Insere o valor ao endereço de números + i
    }

    printf("Ordem atual dos itens no array:\n");
    for ( p = numeros; p <= &numeros[9]; p++ ) {printf("%d ", *p);} // Valor desreferenciado do ponteiro p -> numeros é impresso na tela
    // O propósito desse metodo de impressão é evidenciar como é acessado o endereço de memória de um array

    // Algoritimo de ordenação Bubblesort:
    for (contador = 0; contador < 10-1; contador++) { // "10-1" Se justifica pois contador[10] não tem comparativo
        for (i = 0; i < 10; i++) {
            if(numeros[i] > numeros[i+1]) { // Condição e swap
                aux = numeros[i];
                numeros[i] = numeros[i+1];
                numeros[i+1] = aux;
            }
        }
    }
    printf("\nElementos do array em ordem crescente:\n");
    for(i = 0; i < 10; i++) {
        printf("%d ", numeros[i]);
    }
}

void subMenuFuncoes(int opc) {
    switch (opc) {
        case 1:
            bubbleSort();
        break;
        case 2:
            printf("quickSort()");
        break;
        case 3:
            printf("mergeSort()");
        break;
        case 4:
            printf("quickSort()");
        break;
        case 5:
            printf("quickSort()");
        break;
        case 6:
            printf("quickSort()");
        break;
        case 7:
            printf("quickSort()");
        break;
        case 8:
            printf("quickSort()");
        break;
        case 9:
            printf("quickSort()");
        break;
        case 10:
            printf("quickSort()");
        break;
        case 11:
            printf("quickSort()");
        break;
        case 12:
            printf("quickSort()");
        break;
        case 13:
            printf("quickSort()");
        break;
        default:
            wprintf(L"\n\tOpção inválida.");
    }

}


void menuFuncoes() {
    int opc;
    do {
        limparTela();
        wprintf(L"\n\t----------- FUNÇÕES -----------");
        wprintf(L"\n\tMétodos de ordenação:");
        printf("\n\tBubble-Sort ------------------- 1");
        printf("\n\tQuick-Sort -------------------- 2");
        printf("\n\tMerge-Sort -------------------- 3");
        printf("\n\tInsertion-Sort ---------------- 4");
        printf("\n\tInsertion-Sort ---------------- 5");
        wprintf(L"\n\tMétodos de busca:");
        printf("\n\tÁrvore-de-busca-binária ------- 6");
        printf("\n\tBusca-sequencial -------------- 7");
        printf("\n\tBusca-binária-recursiva ------- 8");
        printf("\n\tBusca-sequencial -------------- 9");
        wprintf(L"\n\tMétodos de alocação dinâmica:");
        printf("\n\tPilha ------------------------ 10");
        printf("\n\tFila ------------------------- 11");
        printf("\n\tLista-encadeada -------------- 12");
        printf("\n\tLista-duplamente-encadeada --- 13");
        printf("\n\tSair -------------------------- 0");
        wprintf(L"\n\n\tEscolha:");
        scanf("\n\t%d", &opc);
    } while (opc != 0);

    subMenuFuncoes(opc);
}


#endif
