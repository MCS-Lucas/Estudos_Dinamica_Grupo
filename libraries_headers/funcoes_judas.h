//Aqui serão declaradas as funções feitas pelo Guilherme Yago
#ifndef FUNCOES_JUDAS_H
#define FUNCOES_JUDAS_H
#endif
#define TAM 10
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif


inline void limparTela() {
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #else

    #endif
}

inline void pausarExecucao(int segundos) {
    #ifdef _WIN32 // Caso WIN
        Sleep(segundos * 1000); // Função converte milisegundos -> segundos
    #else // Caso genérico
        sleep(seconds);
    #endif
}

inline void swap(int vetor[TAM], int numA, int numB) {
    int aux = vetor[numA];
    vetor[numA] = vetor[numB];
    vetor[numB] = aux;
}

inline void bubbleSort() {
    int numeros[TAM];
    int i, aux, contador, input;
    int *p;

    wprintf(L"\n\tEntre com dez números para preencher o array,\ne pressione enter após digitar cada um:\n");
    for (i = 0; i <= TAM-1; i++) {
        scanf("%d", &input);
        *(numeros + i) = input; // "Insere o valor ao endereço de números + i
    }

    printf("\n\tOrdem atual dos itens no array:\n");

    for ( p = numeros; p <= &numeros[9]; p++ ) {
        if(p == numeros){printf("\t");} // Corrigir a margem do primeiro elemento
        printf("%d ", *p);
    } // Valor desreferenciado do ponteiro p -> numeros é impresso na tela
    // O propósito desse metodo de impressão é evidenciar como é acessado o endereço de memória de um array

    // Algoritimo de ordenação Bubblesort:
    for (contador = 0; contador < TAM-1; contador++) { // "10-1" Se justifica pois contador[10] não tem comparativo
        for (i = 0; i < TAM; i++) {
            if(numeros[i] > numeros[i+1]) { // Condição e swap
                aux = numeros[i];
                numeros[i] = numeros[i+1];
                numeros[i+1] = aux;
            }
        }
    }
    printf("\n\tElementos do array em ordem crescente:\n");
    for(i = 0; i < TAM; i++) {
        if(i == 0) {printf("\t");}
        printf("%d ", numeros[i]);
    }
}

inline int particionamento(int *v, int inicio, int fim, int pivot) {
    while(inicio < fim) {
        while(inicio <= fim && v[inicio] <= pivot)
            inicio++;
        while(inicio < fim && v[fim] > pivot)
            fim--;
        swap(v, v[fim], v[inicio]);
    }
    return inicio;
}


inline void quickSort() {
    int numeros[TAM];
    int i, j;
    int pivot; // Elemento usado como comparador no laço de repetição [ x < pivot > y ]

    wprintf(L"\n\tEntre com dez números para preencher o array, e pressione enter após digitar cada um:\n");
    for (i = 0; i <= TAM-1; i++) {
        scanf("%d", &numeros[i]);
    }

    printf("\n\tOrdem atual dos itens no array:\n");
    for( i = 0; i < TAM; i++) {
        if( i == 0 ) {printf("\t");} // Correção da margem do primeiro elemento
        printf("%d ", numeros[i]);
    }

    printf("\n\tPrimeiro elemento     : %d", numeros[0]);
    printf("\n\tElemento central      : %d", numeros[TAM/2]);
    wprintf(L"\n\tÚltimo elemento       : %d", numeros[TAM-1]);

    wprintf(L"\n\n\tAlgorítimo de ordenação QuickSort:");
    pivot = (numeros[0] + numeros[TAM/2] + numeros[TAM-1])/3; // Define pivot à partir da média de 3 elementos aleatórios
    printf("\n\tPivot                 : %d", pivot);

}


inline void menuFuncoes() {
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
                limparTela();
                bubbleSort();
            break;
            case 2:
                limparTela();
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


