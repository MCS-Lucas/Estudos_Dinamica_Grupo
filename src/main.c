#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "elementos.h"
#include "funcoes_carvas.h"
#include "funcoes_lulu.h"
#include "funcoes_edu.h"
#include "funcoes_judas.h"

int * preencherArray();
void bubbleSort();
void quickSort();
void menuFuncoes();
void limparTela();
void pausarExecucao(int segundos);
void chamadaQuickSort(int *v, int inicio, int fim);
int particionamento(int *v, int inicio, int fim);
void imprimirArray(int *v, int opcao);
void swap(int vetor[TAM], int numA, int numB);
void merge(int *v, int indexInicio, int meio, int indexFim);
void mergeSort(int *v, int indexInicio, int indexFim);
void chamadaMergeSort(int *v, int indexInicio, int indexFim);
void insertionSort(int *v, int indexInicio, int indexFim);
void selectionSort(int *v, int indexInicio, int indexFim);
NoPilha * empilhar(NoPilha *topo, int valor);
void inserirFila(NoFila **fila, int num);
void imprimirFila(NoFila **fila);
void inserirFimLista(NoLista **lista, int valor);
void imprimirLista(NoLista **lista);





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

                break;

            case 2:

                break;

            case 3:
                menuFuncoes();

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