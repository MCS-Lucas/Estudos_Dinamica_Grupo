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

inline void swap(int *vetor, int numA, int numB) { // Função que troca dois elementos de um vetor
    int aux = vetor[numA];
    vetor[numA] = vetor[numB];
    vetor[numB] = aux;
}

inline int * preencherArray() { // Função que retorna o endereço de um array preenchido
    int i, input;
    int * numeros = calloc(TAM, sizeof (int)); /* 'calloc' aloca memória de acordo com o tamanho passado e
                                                        * retorna um ponteiro para o local onde houve a alocação,
                                                        * zerando o espaço alocado.
                                                        * 'zerar' significa colocar o byte 0 em todas as posições
                                                        * de memória alocada */

    wprintf(L"\n\tEntre com dez números para preencher o array,\n\te pressione enter após digitar cada um:\n");
    for (i = 0; i <= TAM-1; i++) {
        scanf("\t%d", &input);
        *(numeros + i) = input; // "Insere o valor ao endereço de números + i
    }
    return numeros;
}

inline void imprimirArray(int *v, int opcao) {
    char string[50];
    if (opcao == 1) {
        strcpy(string, "Elementos de array em ordem crescente:");
    }else {
        strcpy(string, "Ordem atual dos elementos do array:");
    }
    printf("\n\t%s\n", string);
    for(int i = 0; i < TAM; i++) {
        if(i == 0) {printf("\t");}
        printf("%d ", v[i]);
    }
}

inline void bubbleSort(int *v) {
    int *numeros;
    int i, aux;

    numeros = v; // Ponteiro para inteiro 'numeros' passa a apontar para v[0]
    printf("\n\tOrdem atual dos itens no array:\n");

    imprimirArray(numeros, 0);

    // Algoritimo de ordenação Bubblesort:
    for (int contador = 0; contador < TAM-1; contador++) { // "10-1" Se justifica pois contador[10] não tem comparativo
        for (i = 0; i < TAM - 1; i++) {
            if(numeros[i] > numeros[i+1]) { // Condição e swap
                aux = numeros[i];
                numeros[i] = numeros[i+1];
                numeros[i+1] = aux;
            }
        }
    }

    imprimirArray(numeros, 1);


    free(numeros);
}

inline int particionamento(int *v, int inicio, int fim) {
    int pivot = (v[inicio] + v[fim] + v[(inicio + fim)/2])/3; // Define pivot à partir da média de 3 elementos aleatórios
    while(inicio < fim) {
        while(inicio <= fim && v[inicio] <= pivot)
            inicio = inicio + 1;
        while(inicio < fim && v[fim] > pivot)
            fim = fim -1;
        swap(v, inicio, fim);
    }
    return inicio;
}


inline void quickSort(int *v, int inicio, int fim) {
    if(inicio < fim) {
        int pos = particionamento(v, inicio, fim); // 'pos' recebe o índice do elemento correto que está no meio
        quickSort(v, inicio, pos-1); // Chama 'quickSort' de forma recursiva para ordernar n < elemento central
        quickSort(v, pos, fim); // Chama 'quickSort' de forma recursiva para ordernar n >= elemento central
    }
}

inline void chamadaQuickSort(int *v, int inicio, int fim) {
    int *numeros = v;
    imprimirArray(numeros, 0);
    printf("\n\tPrimeiro elemento     : %d", numeros[0]);
    printf("\n\tElemento central      : %d", numeros[TAM/2]);
    wprintf(L"\n\tÚltimo elemento       : %d", numeros[TAM-1]);
    wprintf(L"\n\n\tAlgorítimo de ordenação QuickSort:");
    quickSort(numeros, inicio, fim);
    printf("\n\tPrimeiro elemento     : %d", numeros[0]);
    printf("\n\tElemento central      : %d", numeros[TAM/2]);
    wprintf(L"\n\tÚltimo elemento       : %d", numeros[TAM-1]);
    imprimirArray(numeros, 1);
}

inline void menuFuncoes() {
    int opc;
    int *vetor;
    do {
        limparTela();
        pausarExecucao(1);
        printf("\n\n");
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
                pausarExecucao(1/2);
                vetor = preencherArray();
                bubbleSort(vetor);
                free(vetor);
            break;
            case 2:
                pausarExecucao(1/2);
                vetor = preencherArray();
                chamadaQuickSort(vetor, 0, TAM-1);
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


