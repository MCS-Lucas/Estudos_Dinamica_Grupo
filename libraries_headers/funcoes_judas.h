//Aqui serão declaradas as funções feitas pelo Guilherme Yago
#ifndef FUNCOES_JUDAS_H
#define FUNCOES_JUDAS_H

#include "elementos.h"

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

#endif
