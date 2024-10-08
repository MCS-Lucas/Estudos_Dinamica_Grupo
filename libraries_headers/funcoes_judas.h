//Aqui serão declaradas as funções feitas pelo Guilherme Yago
#ifndef FUNCOES_JUDAS_H
#define FUNCOES_JUDAS_H
#endif

#include "elementos.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif


void limparTela() {
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #else

    #endif
}

void pausarExecucao(int segundos) {
    #ifdef _WIN32 // Caso WIN
        Sleep(segundos * 1000); // Função converte milisegundos -> segundos
    #else // Caso genérico
        sleep(seconds)
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

void quickSort() {
    int numeros[10];
    int i, pivot;

    printf("Entre com dez números para preencher o array, e pressione enter após digitar cada um:\n");
    for (i = 0; i <= 9; i++) {
        printf("%d/10: ", i);
        scanf("%d", &numeros[i]);
    }
}


void menuFuncoes() {
    int opc;
    do {
        limparTela();
        pausarExecucao(1); // Conversão implícita de int = 1 para float = 0.5
        wprintf(L"\n\t----------- FUNÇÕES -----------");
        wprintf(L"\n\tMétodos de ordenação:");
        wprintf(L"\n\tBubble-Sort ------------------- 1");
        wprintf(L"\n\tQuick-Sort -------------------- 2");
        wprintf(L"\n\tMerge-Sort -------------------- 3");
        wprintf(L"\n\tInsertion-Sort ---------------- 4");
        wprintf(L"\n\tInsertion-Sort ---------------- 5");
        wprintf(L"\n\n\tMétodos de busca:");
        wprintf(L"\n\tÁrvore-de-busca-binária ------- 6");
        wprintf(L"\n\tBusca-sequencial -------------- 7");
        wprintf(L"\n\tBusca-binária-recursiva ------- 8");
        wprintf(L"\n\tBusca-sequencial -------------- 9");
        wprintf(L"\n\n\tMétodos de alocação dinâmica:");
        wprintf(L"\n\tPilha ------------------------ 10");
        wprintf(L"\n\tFila ------------------------- 11");
        wprintf(L"\n\tLista-encadeada -------------- 12");
        wprintf(L"\n\tLista-duplamente-encadeada --- 13");
        wprintf(L"\n\n\tSair -------------------------- 0");
        wprintf(L"\n\n\tEscolha:");
        scanf("\n\t%d", &opc);

        switch (opc) {
            case 1:
                bubbleSort();
            break;
            case 2:
                quickSort();
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
                if(opc == 0) {
                    printf("Encerrando Programa...");
                    break;
                }
                wprintf(L"\n\tOpção inválida.");
            }
    } while (opc != 0);

}


